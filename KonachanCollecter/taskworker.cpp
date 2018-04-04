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
	for (int i = 0;i < 3;i++)
	{// 重发三次
		reply = manager->get(request);
		connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		loop.exec();
		if (!reply->error()) break;
		qInfo("Network Error : %d--%s!\nURL : %s", reply->error(), reply->errorString(), reply->url().toString());
		delete reply; reply = nullptr;
	}
	page_ = reply->readAll();
	reply->deleteLater();
	//connect(reply, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
	//	[&](QNetworkReply::NetworkError error) {
	//	if (error) {
	//		qDebug("Network Error : %d--%s!\nURL : %s", error, reply->errorString(), reply->url().toString());
	//		reply->abort();
	//		delete reply;
	//		reply = nullptr;
	//	}
	//	else {
	//		err = false;
	//		page_ = reply->readAll();
	//	}
	//});
	//for (int i = 0;i < 3 || !err;i++) {
	//	reply = manager->get(request);
	//	loop.exec();
	//	delete reply; reply = nullptr;
	//}
	handle_page();
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
