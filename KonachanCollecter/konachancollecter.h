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

	int imageCount;// ͼƬ����
	int downloadCount;// ��ǰ��������
	QString folderPath;// ��������·��
	QStringList imageInfoUrl;// ͼƬ��Ϣҳ���ַ

	// https request
	QString requestUrl;
	QSslConfiguration sslConfig;
	QNetworkRequest request;
};

#endif // KONACHANCOLLECTER_H
