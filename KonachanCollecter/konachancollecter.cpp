#include "konachancollecter.h"

KonachanCollecter::KonachanCollecter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// ���ؽ���
	ui.label_progress->hide();
	ui.progressBar->hide();
	// ui�źŲ�
	connect(ui.pushButton_tags, SIGNAL(clicked()), this, SLOT(hyperlink()));
	connect(ui.pushButton_selectFolder, SIGNAL(clicked()), this, SLOT(changeFolderPath()));
	connect(ui.pushButton_start, SIGNAL(clicked()), this, SLOT(startMisson()));
}

KonachanCollecter::~KonachanCollecter()
{
	
}

// �鿴����tag
void KonachanCollecter::hyperlink()
{
	QDesktopServices::openUrl(QUrl("https://konachan.com/tag"));
}

// ���ı���·��
void KonachanCollecter::changeFolderPath()
{
	ui.lineEdit_folderPath->setText(QFileDialog::getExistingDirectory(nullptr, "Please select the destination folder..."));
}

void KonachanCollecter::startMisson()
{
	QString tags = ui.lineEdit_tags->text();					// Դ��ַ
	QString folderPath = ui.lineEdit_folderPath->text();		// ����·��
	QString maxThread = ui.lineEdit_maxThread->text();		// ����߳���

	if (tags.isEmpty() || folderPath.isEmpty() || maxThread.isEmpty())
	{
		QMessageBox::warning(this, "Error", "Null input parameter(s)!");
		return;
	}
	QDir dir;
	if (!dir.exists(folderPath) && !dir.mkdir(folderPath))
	{
		QMessageBox::warning(this, "Error", "Create directory failed!");
		return;
	}

	ui.label_progress->setText("Please wait for a minute...");
	ui.progressBar->setRange(0, 0);
	ui.label_progress->show();
	ui.progressBar->show();
	ui.pushButton_start->setEnabled(false);

	thread = new KonachanThread(tags, folderPath, maxThread.toInt());
	connect(thread, SIGNAL(newProgress(int, int)), this, SLOT(updateProgress(int, int)));
	thread->start();
}

// ���Ȼ���
void KonachanCollecter::updateProgress(int value,int max)
{
	ui.label_progress->setText(QString("Downloading...(Finished: %1/%2)").arg(value).arg(max));
	ui.progressBar->setMaximum(max);
	ui.progressBar->setValue(value);

	if (value == max)
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		QMessageBox::about(this, "Done", QString("All images matched have been download!(%1/%2)").arg(value).arg(max));
	}
}


