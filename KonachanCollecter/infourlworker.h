#pragma once

#include <QFileInfo>
#include <QRegExp>
#include "taskworker.h"

class InfoUrlWorker :public TaskWorker
{
public:
	virtual void handle_page();
};