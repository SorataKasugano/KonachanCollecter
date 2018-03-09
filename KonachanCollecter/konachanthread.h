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
// 工作线程
class KonachanThread :public QThread
{
	Q_OBJECT
public:
	KonachanThread(QString, QString, int);
	void run();

signals:
	void newProgress(int, int);// 当前总进度

private:
	QString m_url;			// 线程池任务url
	QString m_path;			// 保存路径
	QThreadPool threadPool;	// 管理https连接线程池
};

// 线程池子线程
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
	void newFinished();

private:
	QString m_url;
	QSslConfiguration sslConfig;
	QNetworkRequest m_request;
	// m_reply;

	QString m_path;					// 保存路径
	QByteArray m_page;				// 页面缓存
	QList<QRegExp> m_rxList;			// 多次页面分析所需的正则表达式列表
};