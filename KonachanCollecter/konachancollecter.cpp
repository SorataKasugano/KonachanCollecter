#include "konachancollecter.h"

KonachanCollecter::KonachanCollecter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// ���ؽ���
	ui.label_progress->hide();
	ui.progressBar->hide();
	// Ĭ����Ϣ
	ui.lineEdit_tags->setPlaceholderText("6 tags at most:dress+long_hair+...");
	ui.lineEdit_folderPath->setText("D:/KonachanImages");
	ui.lineEdit_maxThread->setText("10");
	// ui�źŲ�
	connect(ui.pushButton_selectFolder, SIGNAL(clicked()), this, SLOT(getFolderPath()));
	connect(ui.pushButton_start, SIGNAL(clicked()), this, SLOT(sendRequest()));
}

KonachanCollecter::~KonachanCollecter()
{
	
}

// ���ı���ͼƬ��Ŀ���ļ���·��
void KonachanCollecter::getFolderPath()
{
	ui.lineEdit_folderPath->setText(QFileDialog::getExistingDirectory(nullptr, "Please select the destination folder..."));
}

// ���������߳�
void KonachanCollecter::sendRequest()
{
	ui.label_progress->setText("Please wait for a minute...");
	ui.progressBar->setRange(0, 0);
	ui.label_progress->show();
	ui.progressBar->show();
	thread = new KonachanThread(
		(QUrl)("https://konachan.com/post?tags=" + ui.lineEdit_tags->text()),	// Դ��ַ
		ui.lineEdit_folderPath->text(),											// ����·��
		ui.lineEdit_maxThread->text().toInt());									// ����߳���
	connect(thread, SIGNAL(newProgress(int, int)), this, SLOT(updateProgress(int, int)));
	thread->start();
}

// ���Ȼ���
void KonachanCollecter::updateProgress(int value,int max)
{
	if (value == max)
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		QMessageBox::about(this, "Done", QString("All images matched have been download!(%1/%2)").arg(value).arg(max));
	}
	ui.label_progress->setText(QString("Downloading...(Finished: %1/%2)").arg(value).arg(max));
	ui.progressBar->setMaximum(max);
	ui.progressBar->setValue(value);
}


