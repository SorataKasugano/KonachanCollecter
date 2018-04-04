#include "downloadurlworker.h"

void DownloadUrlWorker::handle_page()
{
	QFile file(path_ + "/" + url_.section("/", -1));
	file.open(QIODevice::WriteOnly);
	file.write(page_);
	file.close();
	emit new_task("done");
}
