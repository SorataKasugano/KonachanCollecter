#include "konachanthread.h"

namespace {
	int imageFinished, imageCount;
	//QReadWriteLock queueLock;
	QQueue<QUrl> queueUrl;
}

KonachanThread::KonachanThread(QUrl url, QString path, int max = 10)
{
	m_seedUrl = url;
	m_path = path;
	m_maxThread = max;
}

void KonachanThread::run()
{
	imageFinished = imageCount = 0;
	QThreadPool threadPool;
	threadPool.setMaxThreadCount(m_maxThread);
	queueUrl.enqueue(m_seedUrl);
	while (true)
	{
		if (!queueUrl.isEmpty())
		{
			QUrl url = queueUrl.dequeue();
			qDebug() << "(1)task url:" << url;
			KonachanTask* task = new KonachanTask(url, m_path);
			QObject::connect(task, SIGNAL(newFinished(int, int)), this, SLOT(sendProgress(int, int)));
			threadPool.start(task);
			if (url.toString().contains("/image"))
			{
				imageCount++;
				emit newProgress(imageFinished, imageCount);// 更新下载进度
			}
		}
		if (!threadPool.activeThreadCount())
			break;
	}
}

void KonachanThread::sendProgress(int value, int max)
{
	emit newProgress(value, max);
}

KonachanTask::KonachanTask(QUrl url,QString path)
{
	m_url = url;
	m_path = path;
}

void KonachanTask::init()
{
	// ssl协议
	sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
	sslConfig.setProtocol(QSsl::TlsV1_2);
	m_request.setSslConfiguration(sslConfig);
	// 正则表达式
	m_rxList << (QRegExp)"href=\"/post\\?page=\\d+[^><]+>\\d+"					// 0.获取页数
		<< (QRegExp)"/post/show/\\d+/[^\"]+"										// 1.获取概览url
		<< (QRegExp)"https://konachan.com/image/[0-9a-z]+/Konachan.com[^\"]+";	// 2.获取下载url
}

void KonachanTask::run()
{
	init();
	QNetworkAccessManager* pManager = new QNetworkAccessManager();
	QEventLoop loop;
	m_request.setUrl(m_url);
	m_reply = pManager->get(m_request);
	connect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	//QWriteLocker locker(&queueLock);
	analyze(m_reply);
}

void KonachanTask::analyze(QNetworkReply* reply)
{
	QString url = reply->url().toString();
	QByteArray page = reply->readAll();
	// 下载 
	if (url.contains("/image"))
	{
		QDir dir;
		if (!dir.exists(m_path)) dir.mkdir(m_path);
		QFile file(m_path + "/" + url.section("/",-1));
		file.open(QIODevice::WriteOnly);
		file.write(page);
		file.close();
		imageFinished++;
		emit newFinished(imageFinished, imageCount);// 更新下载进度
	}
	// 概览
	else if (url.contains("/post/show"))
	{
		m_rxList[2].indexIn(page);
		QUrl tmp = (QUrl)(m_rxList[2].cap());
		//qDebug() << "(3.3)down url:" << tmp;
		queueUrl.enqueue(tmp);
	}
	// 分页
	else if (url.contains("/post?"))
	{
		// 根页
		if (url.contains("/post?tags="))
		{
			m_rxList[0].lastIndexIn(page);
			int pageCount = m_rxList[0].cap().section(">",-1).toInt();
			for (int index=2;index <=pageCount;index++)
			{
				QUrl tmp = (QUrl)(QString("https://konachan.com/post?page=%1&").arg(index) + url.section("/post?", -1));
				//qDebug() << "(3.1)page url:" << tmp;
				queueUrl.enqueue(tmp);
			}
		}
		int pos = 0;
		while ((pos = m_rxList[1].indexIn(page, pos)) != -1)
		{
			QUrl tmp = (QUrl)("https://konachan.com" + m_rxList[1].cap());
			//qDebug() << "(3.2)info url:" << tmp;
			queueUrl.enqueue(tmp);
			pos += m_rxList[1].matchedLength();
		}
	}
	reply->deleteLater();
}
