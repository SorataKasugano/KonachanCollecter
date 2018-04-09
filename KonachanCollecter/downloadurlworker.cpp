#include "downloadurlworker.h"

void DownloadUrlWorker::handle_page()
{
	// over concurrent requests(too much threads)
	if (page_.size() < 1024)
	{
		qInfo("Shame on you! You made Haruka cry.");
		emit new_task(url_);
	}
	QFile file(path_ + "/" + url_.section("/", -1));
	file.open(QIODevice::WriteOnly);
	file.write(page_);
	file.close();
	emit new_task("done");
}
