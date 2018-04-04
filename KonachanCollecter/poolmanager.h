#pragma once

#include <QObject>
#include <QThreadPool>
#include "rooturlworker.h"
#include "pagingurlworker.h"
#include "infourlworker.h"
#include "downloadurlworker.h"

class PoolManager :public QObject
{
	Q_OBJECT
public:
	PoolManager(QString path,int max);
	~PoolManager();

public slots:
	void add_new_task(QString task);

signals:
	void new_progress(QString progress);

private:
	QString path_;
	QThreadPool thread_pool_;
};