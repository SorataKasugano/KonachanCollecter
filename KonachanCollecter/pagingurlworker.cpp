#include "pagingurlworker.h"

void PagingUrlWorker::handle_page()
{
	QRegExp reg_exp("/post/show/\\d+/[^\"]+");
	if (reg_exp.indexIn(page_) == -1)
		emit new_task("none");// Œﬁ∆•≈‰Õº∆¨
	int pos = 0;
	while ((pos = reg_exp.indexIn(page_, pos)) != -1)
	{
		emit new_task("https://konachan.com" + reg_exp.cap());
		pos += reg_exp.matchedLength();
	}
}