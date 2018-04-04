#pragma once

#include <QFile>
#include "taskworker.h"

class DownloadUrlWorker :public TaskWorker
{
public:
	virtual void handle_page();
};