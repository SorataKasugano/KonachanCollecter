#pragma once

#include <QString>
#include <QByteArray>
#include <QRunnable>
#include <QNetWorkAccessManager>
#include <QNetWorkRequest>
#include <QNetWorkReply>
#include <QEventLoop>

class TaskWorker :public QObject ,public QRunnable
{
	Q_OBJECT

public:
	void run();
	TaskWorker* set_url(QString url);
	TaskWorker* set_path(QString path);
	virtual void handle_page() = 0;

signals:
	void new_task(QString task);

protected:
	QString url_;
	QString path_;
	QByteArray page_;
};