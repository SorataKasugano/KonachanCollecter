#include "taskworker.h"

void TaskWorker::run()
{
	QSslConfiguration ssl_config;
	ssl_config.setPeerVerifyMode(QSslSocket::VerifyNone);
	ssl_config.setProtocol(QSsl::TlsV1_2);
	QNetworkRequest request;
	request.setSslConfiguration(ssl_config);
	request.setUrl(QUrl(url_));
	QEventLoop loop;
	QNetworkAccessManager* manager = new QNetworkAccessManager;
	QNetworkReply* reply;
	bool suc = false;
	for (int i = 0;i < 3 && !suc;i++)
	{// resend when error
		reply = manager->get(request);
		connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		loop.exec();
		if (!reply->error()) {
			suc = true;// quit loop when success
			page_ = reply->readAll();
		}
		else qInfo("Network Error(%d): %s![%s]", reply->error(), qPrintable(reply->errorString()), qPrintable(url_));
		delete reply; reply = nullptr;// mem release
	}
	manager->deleteLater();
	suc ? handle_page() : qInfo("Request failed: %s",qPrintable(url_));
}

TaskWorker* TaskWorker::set_url(QString url)
{
	url_ = url;
	return this;
}

TaskWorker* TaskWorker::set_path(QString path)
{
	path_ = path;
	return this;
}
