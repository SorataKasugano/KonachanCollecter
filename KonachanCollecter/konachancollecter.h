#ifndef KONACHANCOLLECTER_H
#define KONACHANCOLLECTER_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QNetWorkAccessManager>
#include <QNetWorkRequest>
#include <QNetWorkReply>
#include <QMessageBox>
#include "ui_konachancollecter.h"
class KonachanCollecter : public QMainWindow
{
	Q_OBJECT

public:
	KonachanCollecter(QWidget *parent = 0);
	~KonachanCollecter();

	void memberInit();

	public slots:
		void getFolderPath();
		void sendRequest();
		void getInfoAddr(QNetworkReply* reply);
		void getDownloadAddr(QNetworkReply* reply);
		void downloadImage(QNetworkReply* reply);

private:
	Ui::KonachanCollecterClass ui;

	int imageCount;// 图片总数
	int downloadCount;// 当前已下载数
	QString folderPath;// 本机保存路径
	QStringList imageInfoUrl;// 图片信息页面地址

	// https request
	QString requestUrl;
	QSslConfiguration sslConfig;
	QNetworkRequest request;
};

#endif // KONACHANCOLLECTER_H
