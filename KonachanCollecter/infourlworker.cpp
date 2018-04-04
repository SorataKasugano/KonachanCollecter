#include "infourlworker.h"

void InfoUrlWorker::handle_page()
{
	QRegExp reg_exp("https://konachan.com/image/[0-9a-z]+/Konachan.com[^\"]+");
	reg_exp.indexIn(page_);
	url_ = reg_exp.cap();
	emit new_task("todo");
	// ¹ıÂËÒÑ´æÔÚÍ¼Æ¬
	QFileInfo file(path_ + "/" + url_.section("/", -1));
	emit file.exists() ? new_task("dup") : new_task(url_);
}