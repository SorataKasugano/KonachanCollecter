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
// 工作线程
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
	QUrl m_seedUrl;		// 原始url
	int m_maxThread;		// 线程池最大线程数
	QString m_path;		// 保存路径
};

// 线程池子线程
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

	QString m_path;					// 保存路径
	QList<QRegExp> m_rxList;			// 多次页面分析所需的正则表达式列表
};