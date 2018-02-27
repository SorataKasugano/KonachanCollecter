#include "konachancollecter.h"

KonachanCollecter::KonachanCollecter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// 隐藏进度
	ui.label_progress->hide();
	ui.progressBar->hide();
	// 提示信息
	ui.lineEdit_tags->setPlaceholderText("6 tags at most:dress+long_hair+...");
	ui.lineEdit_folderPath->setPlaceholderText("All pictures will be downloaded to this folder.");
	// 信号槽
	connect(ui.pushButton_selectFolder, SIGNAL(clicked()), this, SLOT(getFolderPath()));
	connect(ui.pushButton_start, SIGNAL(clicked()), this, SLOT(sendRequest()));
	// 初始化SSL
	sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
	sslConfig.setProtocol(QSsl::TlsV1_2);
	request.setSslConfiguration(sslConfig);
}

KonachanCollecter::~KonachanCollecter()
{

}

// 成员初始化
void KonachanCollecter::memberInit()
{
	imageCount = 0;
	downloadCount = 0;
	imageInfoUrl.clear();
}

// 获取保存图片的目标文件夹路径
void KonachanCollecter::getFolderPath()
{
	folderPath = QFileDialog::getExistingDirectory(nullptr, "Please select the destination folder...","D:/Picture/tmp");
	ui.lineEdit_folderPath->setText(folderPath);
}

// 请求图片列表
void KonachanCollecter::sendRequest()
{
	if ("stop" == ui.pushButton_start->text())
	{
		// 结束所有https线程
	}
	// 界面处理
	ui.label_progress->show();
	ui.pushButton_start->setText("Stop");
	// 发送请求
	memberInit();
	QNetworkAccessManager* pManager = new QNetworkAccessManager();
	connect(pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getInfoAddr(QNetworkReply*)));
	requestUrl = "https://konachan.com/post?tags=" + ui.lineEdit_tags->text();
	request.setUrl(requestUrl);
	pManager->get(request);
}

// 请求图片概览
void KonachanCollecter::getInfoAddr(QNetworkReply* reply)
{
	QString listPage = reply->readAll();

	int pageCount = 0;
	QString tmp;
	int pos = 0;
	// 获取图片列表页数
	QRegExp rx("a href=\"/post\\?page=\\d+");
	rx.lastIndexIn(listPage);
	tmp = rx.cap();
	rx.setPattern("\\d+");
	rx.indexIn(tmp);
	pageCount = rx.cap().toInt();
	// 获取第一页所有图片的概览地址
	rx.setPattern("/post/show/\\d+/[0-9a-z-_]+");
	while ((pos = rx.indexIn(listPage, pos)) != -1)
	{
		imageInfoUrl<<("https://konachan.com" + rx.cap());
		pos += rx.matchedLength();
	}
	// 获取2-last页所有图片的概览地址
	QEventLoop loop;
	QNetworkAccessManager* pManager = new QNetworkAccessManager();
	for (;pageCount > 1;pageCount--)
	{
		disconnect(reply);
		requestUrl = QString("https://konachan.com/post?page=%1&tags=").arg(pageCount) + ui.lineEdit_tags->text();
		request.setUrl(requestUrl);
		reply = pManager->get(request);
		connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		loop.exec();
		listPage = reply->readAll();
		pos = 0;
		while ((pos = rx.indexIn(listPage, pos)) != -1)
		{
			imageInfoUrl << ("https://konachan.com" + rx.cap());
			pos += rx.matchedLength();
		}
	}
	imageCount = imageInfoUrl.count();// 图片总数
	reply->deleteLater();
	// 显示进度条
	ui.label_progress->setText(QString("Downloading...no.1/%1").arg(imageCount));
	ui.progressBar->setRange(0, imageCount);
	ui.progressBar->setValue(0);
	ui.progressBar->show();
	// 请求所有图片的概览页面
	connect(pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getDownloadAddr(QNetworkReply*)));
	for (auto iter : imageInfoUrl)
	{
		qDebug() << iter;
		request.setUrl(iter);
		pManager->get(request);
	}
}

// 请求原图下载：png version->jpg version
void KonachanCollecter::getDownloadAddr(QNetworkReply* reply)
{
	QString infoPage = reply->readAll();
	reply->deleteLater();
	QRegExp rx("https://konachan.com/image/[0-9a-z]+/Konachan.com[0-9a-z-_%]+.png|https://konachan.com/image/[0-9a-z]+/Konachan.com[0-9a-z-_%]+.jpg");
	QNetworkAccessManager* pManager = new QNetworkAccessManager();
	rx.indexIn(infoPage);
	requestUrl = rx.cap();
	request.setUrl(requestUrl);
	connect(pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadImage(QNetworkReply*)));
	pManager->get(request);
}

// 下载器
void KonachanCollecter::downloadImage(QNetworkReply* reply)
{
	QRegExp rx("Konachan.com.*");
	QString str = reply->url().toString();
	rx.indexIn(str);
	QString fileName = rx.cap();
	QFile file(folderPath+"/"+fileName);
	if (!file.open(QIODevice::WriteOnly))
	{

	}
	file.write(reply->readAll());
	file.close();
	reply->deleteLater();
	downloadCount++;
	if (downloadCount != imageCount)
	{
		ui.label_progress->setText(QString("Downloading...no.%1/%2").arg(downloadCount + 1).arg(imageCount));
		ui.progressBar->setValue(downloadCount);
		qDebug() << "filename:" << fileName;
	}
	else
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		QMessageBox::about(nullptr, "Finished!", QString("All images have been downloaded!(%1/%2)").arg(downloadCount).arg(imageCount));
	}
}