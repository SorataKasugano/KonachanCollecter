#include "rooturlworker.h"

void RootUrlWorker::handle_page()
{
	QRegExp reg_exp("href=\"/post\\?page=\\d+[^><]+>\\d+");
	reg_exp.lastIndexIn(page_);
	int paging_count = reg_exp.cap().section(">", -1).toInt();
	if (!paging_count) paging_count = 1;
	for (int index = 1;index <= paging_count;index++)
		emit new_task(QString("https://konachan.com/post?page=%1&").arg(index) + url_.section("/post?", -1));
}