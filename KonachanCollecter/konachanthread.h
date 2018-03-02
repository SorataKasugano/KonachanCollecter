#pragma once
#include <QString>
#include <QByteArray>
#include <QNetWorkAccessManager>
#include <QNetWorkRequest>
#include <QNetWorkReply>
#include <QEventLoop>
#include <QThreadPool>
#include <QQueue>
#include <QReadWriteLock>
#include <QDir>
#include <QFile>
// �����߳�
class KonachanThread :public QThread
{
	Q_OBJECT
public:
	KonachanThread(QUrl, QString, int);
	void run();

	public slots:
	void sendProgress(int, int);
signals:
	void newProgress(int, int);

private:
	QUrl m_seedUrl;		// ԭʼurl
	int m_maxThread;		// �̳߳�����߳���
	QString m_path;		// ����·��
};

// �̳߳����߳�
class KonachanTask :public QObject, public QRunnable
{
	Q_OBJECT
public:
	KonachanTask(QUrl,QString);
	void init();
	void run();
	void analyze(QNetworkReply*);

signals:
	void newFinished(int, int);

private:
	QUrl m_url;
	QSslConfiguration sslConfig;
	QNetworkRequest m_request;
	QNetworkReply* m_reply;

	QString m_path;					// ����·��
	QList<QRegExp> m_rxList;			// ���ҳ����������������ʽ�б�
};