#pragma once

#include <QRegExp>
#include "taskworker.h"

class RootUrlWorker :public TaskWorker
{
public:
	virtual void handle_page();
};