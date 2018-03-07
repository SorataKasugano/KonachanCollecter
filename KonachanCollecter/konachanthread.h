#pragma once
#include <QString>
#include <QByteArray>
#include <QNetWorkAccessManager>
#include <QNetWorkRequest>
#include <QNetWorkReply>
#include <QEventLoop>
#include <QThreadPool>
#include <QQueue>
#include <QMutex>
#include <QFile>
// �����߳�
class KonachanThread :public QThread
{
	Q_OBJECT
public:
	KonachanThread(QString, QString, int);
	void run();

	public slots:
	void sendProgress(int);
signals:
	void newProgress(int, int);// ��ǰ�ܽ���

private:
	QString m_seedUrl;		// ԭʼurl
	QString m_path;			// ����·��
	QThreadPool threadPool;	// ����https�����̳߳�
};

// �̳߳����߳�
class KonachanTask :public QObject, public QRunnable
{
	Q_OBJECT
public:
	KonachanTask(QString, QString);
	void run();
	void analyze();
	void extractPagingUrl();
	void extractInfoUrl();
	void extractDownloadUrl();
	void download();

signals:
	void newFinished(int);// ��ǰ���ؽ���

private:
	QString m_url;
	QSslConfiguration sslConfig;
	QNetworkRequest m_request;
	QNetworkReply* m_reply;

	QString m_path;					// ����·��
	QByteArray m_page;				// ҳ�滺��
	QList<QRegExp> m_rxList;			// ���ҳ����������������ʽ�б�
};