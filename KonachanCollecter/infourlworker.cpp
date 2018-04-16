#include "infourlworker.h"

void InfoUrlWorker::handle_page()
{
	QRegExp reg_exp("https://konachan.com/image/[0-9a-z]+/Konachan.com[^\"]+");
	reg_exp.indexIn(page_);
	url_ = reg_exp.cap();
	// filter duplicate images
	QFileInfo file(path_ + "/" + url_.section("/", -1));
	if (file.exists()) emit new_task("dup");
	else { emit new_task("new"); emit new_task(url_); };
}