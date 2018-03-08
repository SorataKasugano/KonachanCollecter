#include "konachanthread.h"

namespace {
	int imageFinished, imageCount;	// ��¼����
	QQueue<QString> queueUrl;		// url����
	QMutex queueMutex;
}

KonachanThread::KonachanThread(QString tags, QString path, int max = 10)
	: m_seedUrl("https://konachan.com/post?tags=" + tags)
	, m_path(path)
{
	threadPool.setMaxThreadCount(max);	// �����̳߳�����߳���
	imageFinished = imageCount = 0;		// ��ʼ�����ؽ���
	queueUrl.enqueue(m_seedUrl);			// ��ʼ��url����
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
				emit newProgress(imageFinished, imageCount);// �������ؽ���
			}
		}
		if (!threadPool.activeThreadCount())
			break;
		sleep(1);// ÿ�����һ��url����
	}
}

// �������ؽ���
void KonachanThread::sendProgress(int value)
{
	emit newProgress(value, imageCount);
}

KonachanTask::KonachanTask(QString url, QString path)
	: m_url(url)
	, m_path(path)
{
	// ����sslЭ��
	sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
	sslConfig.setProtocol(QSsl::TlsV1_2);
	m_request.setSslConfiguration(sslConfig);
	// ҳ�洦��������ʽ
	m_rxList << (QRegExp)"href=\"/post\\?page=\\d+[^><]+>\\d+"					// 0.��ȡҳ��
		<< (QRegExp)"/post/show/\\d+/[^\"]+"										// 1.��ȡ����url
		<< (QRegExp)"https://konachan.com/image/[0-9a-z]+/Konachan.com[^\"]+";	// 2.��ȡ����url
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

// url����
void KonachanTask::analyze()
{
	m_url.contains("/image") ?										// ����ҳ�棿
		download() : (m_url.contains("/post/show") ?					// ����ҳ�棿
			extractDownloadUrl() : (m_url.contains("/post?page=") ?	// ��ҳҳ�棿
				extractInfoUrl() : extractPagingUrl()));				// ��ҳҳ��
}

// ��ȡ��ҳurl
void KonachanTask::extractPagingUrl()
{
	m_rxList[0].lastIndexIn(m_page);
	int pageCount = m_rxList[0].cap().section(">", -1).toInt();
	if (!pageCount)	pageCount = 1;// �޷�ҳ
	queueMutex.lock();
	for (int index = 1;index <= pageCount;index++)
	{
		queueUrl.enqueue(QString("https://konachan.com/post?page=%1&").arg(index) + m_url.section("/post?", -1));
	}
	queueMutex.unlock();
}

// ��ȡ����url
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

// ��ȡ����url
void KonachanTask::extractDownloadUrl()
{
	m_rxList[2].indexIn(m_page);
	queueMutex.lock();
	queueUrl.enqueue(m_rxList[2].cap());
	queueMutex.unlock();
}

// ����
void KonachanTask::download()
{
	QFile file(m_path + "/" + m_url.section("/", -1));
	file.open(QIODevice::WriteOnly);
	file.write(m_page);
	file.close();
	imageFinished++;
	emit newFinished(imageFinished);// �������ؽ���
}
