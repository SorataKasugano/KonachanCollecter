#include "poolmanager.h"

PoolManager::PoolManager(QString path, int max)
	: path_(path)
{
	thread_pool_.setMaxThreadCount(max);
}

PoolManager::~PoolManager()
{
}

void PoolManager::add_new_task(QString task)
{// TODO: 抽取封装逻辑处理
	if(!task.contains("http"))
	{// progress update task
		emit new_progress(task); 
		return;
	}
	TaskWorker *worker;
	if (task.contains("/image")) worker = new DownloadUrlWorker;
	else if (task.contains("/post/show")) worker = new InfoUrlWorker;
	else if (task.contains("/post?page=")) worker = new PagingUrlWorker;
	else if (task.contains("/post?tags=")) worker = new RootUrlWorker;
	worker->set_url(task)->set_path(path_);
	connect(worker, &TaskWorker::new_task, this, &PoolManager::add_new_task);
	thread_pool_.start(worker);
}