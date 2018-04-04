#pragma once

#include <QRegExp>
#include "taskworker.h"

class PagingUrlWorker :public TaskWorker
{
public:
	virtual void handle_page();
};