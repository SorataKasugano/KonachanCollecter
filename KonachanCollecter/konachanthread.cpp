#include "konachanthread.h"

namespace {
	int imageFinished, imageCount;	// 记录进度
	QQueue<QString> queueUrl;		// url队列
	QMutex queueMutex;
}

KonachanThread::KonachanThread(QString tags, QString path, int max = 10)
	: m_seedUrl("https://konachan.com/post?tags=" + tags)
	, m_path(path)
{
	threadPool.setMaxThreadCount(max);	// 设置线程池最大线程数
	imageFinished = imageCount = 0;		// 初始化下载进度
	queueUrl.enqueue(m_seedUrl);			// 初始化url队列
}

void KonachanThread::run()
{
	while (true)
	{
		while(!queueUrl.isEmpty())
		{
			queueMutex.lock();
			QString url = queueUrl.dequeue();
			queueMutex.unlock();
			// QThreadPool deletes the QRunnable automatically by default
			KonachanTask* task = new KonachanTask(url, m_path);
			QObject::connect(task, SIGNAL(newFinished(int)), this, SLOT(sendProgress(int)));
			threadPool.start(task);
			if (url.contains("/image"))
			{
				imageCount++;
				emit newProgress(imageFinished, imageCount);// 更新下载进度
			}
		}
		if (!threadPool.activeThreadCount())
			break;
		sleep(1);// 每秒添加一次url队列
	}
}

// 更新下载进度
void KonachanThread::sendProgress(int value)
{
	emit newProgress(value, imageCount);
}

KonachanTask::KonachanTask(QString url, QString path)
	: m_url(url)
	, m_path(path)
{
	// 配置ssl协议
	sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
	sslConfig.setProtocol(QSsl::TlsV1_2);
	m_request.setSslConfiguration(sslConfig);
	// 页面处理正则表达式
	m_rxList << (QRegExp)"href=\"/post\\?page=\\d+[^><]+>\\d+"					// 0.获取页数
		<< (QRegExp)"/post/show/\\d+/[^\"]+"										// 1.获取概览url
		<< (QRegExp)"https://konachan.com/image/[0-9a-z]+/Konachan.com[^\"]+";	// 2.获取下载url
}

void KonachanTask::run()
{
	QNetworkAccessManager* pManager = new QNetworkAccessManager();
	QEventLoop loop;
	int statusCode;
	m_request.setUrl(QUrl(m_url));
	m_reply = pManager->get(m_request);
	connect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	m_page = m_reply->readAll();
	// it is the responsibility of the user to delete the QNetworkReply object at an appropriate time
	pManager->deleteLater();
	m_reply->deleteLater();
	analyze();
}

// url分析
void KonachanTask::analyze()
{
	m_url.contains("/image") ?										// 下载页面？
		download() : (m_url.contains("/post/show") ?					// 概览页面？
			extractDownloadUrl() : (m_url.contains("/post?page=") ?	// 分页页面？
				extractInfoUrl() : extractPagingUrl()));				// 根页页面
}

// 获取分页url
void KonachanTask::extractPagingUrl()
{
	m_rxList[0].lastIndexIn(m_page);
	int pageCount = m_rxList[0].cap().section(">", -1).toInt();
	if (!pageCount)	pageCount = 1;// 无分页
	queueMutex.lock();
	for (int index = 1;index <= pageCount;index++)
	{
		queueUrl.enqueue(QString("https://konachan.com/post?page=%1&").arg(index) + m_url.section("/post?", -1));
	}
	queueMutex.unlock();
}

// 获取概览url
void KonachanTask::extractInfoUrl()
{
	if (m_rxList[1].indexIn(m_page) == -1)
		emit newFinished(0);
	int pos = 0;
	queueMutex.lock();
	while ((pos = m_rxList[1].indexIn(m_page, pos)) != -1)
	{
		queueUrl.enqueue("https://konachan.com" + m_rxList[1].cap());
		pos += m_rxList[1].matchedLength();
	}
	queueMutex.unlock();
}

// 获取下载url
void KonachanTask::extractDownloadUrl()
{
	m_rxList[2].indexIn(m_page);
	queueMutex.lock();
	queueUrl.enqueue(m_rxList[2].cap());
	queueMutex.unlock();
}

// 下载
void KonachanTask::download()
{
	QFile file(m_path + "/" + m_url.section("/", -1));
	file.open(QIODevice::WriteOnly);
	file.write(m_page);
	file.close();
	imageFinished++;
	emit newFinished(imageFinished);// 更新下载进度
}
