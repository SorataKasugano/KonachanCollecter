#include "konachancollecter.h"

KonachanCollecter::KonachanCollecter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.label_progress->hide();
	ui.progressBar->hide();
}

KonachanCollecter::~KonachanCollecter()
{
	qInfo("Application quitted.");
}

// see all tags to hyperlink
void KonachanCollecter::on_pushButton_tags_clicked()
{
	QDesktopServices::openUrl(QUrl("https://konachan.com/tag"));
}

// change folder
void KonachanCollecter::on_pushButton_selectFolder_clicked()
{
	ui.lineEdit_folderPath->setText(QFileDialog::getExistingDirectory(nullptr, "Please select the destination folder..."));
}

// start mission
void KonachanCollecter::on_pushButton_start_clicked()
{
	dup_ = done_ = sum_ = 0;
	QString tags = ui.lineEdit_tags->text();	
	QString folder_path = ui.lineEdit_folderPath->text();
	// max threads in thread pool
	QString max_thread = ui.lineEdit_maxThread->text();

	if (tags.isEmpty() || folder_path.isEmpty() || max_thread.isEmpty())
	{
		QMessageBox::warning(this, "Error", "Null input parameter(s)!");
		return;
	}
	QDir dir;
	if (!dir.exists(folder_path) && !dir.mkdir(folder_path))
	{
		QMessageBox::warning(this, "Error", "Create directory failed!");
		return;
	}
	qInfo("Mission start: tag(s)=[%s]", qPrintable(tags));

	ui.label_progress->setText("Please wait for a minute...");
	ui.progressBar->setMaximum(0);
	ui.label_progress->show();
	ui.progressBar->show();
	ui.pushButton_start->setEnabled(false);

	PoolManager* manager = new PoolManager(folder_path, max_thread.toInt());
	manager->moveToThread(&worker_thread_);
	connect(manager, &PoolManager::new_progress, this, &KonachanCollecter::update_progress);
	worker_thread_.start();
	manager->add_new_task("https://konachan.com/post?tags=" + tags);
}

// echo progress
void KonachanCollecter::update_progress(QString progress)
{
	if (progress == "none")
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		qInfo("No image matched.");
		QMessageBox::warning(this, "Error", "No image matched!");
		return;
	}
	else if (progress == "todo") sum_++;
	else if (progress == "done") done_++;
	else if (progress == "dup") dup_++;
	ui.label_progress->setText(QString("Downloading...[new:%1/%2 dup:%3 sum:%4]").arg(done_).arg(sum_ - dup_).arg(dup_).arg(sum_));
	ui.progressBar->setMaximum(sum_ - dup_);
	ui.progressBar->setValue(done_);
	if ((done_ + dup_ == sum_) && (done_ != 0))
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		qInfo("Mission accomplished: details=[new:%d dup:%d sum:%d/%d]", done_, dup_, done_ + dup_, sum_);
		QMessageBox::about(this, "Congratulations!", QString("All images done.[%1/%2 new:%3]").arg(done_ + dup_).arg(sum_).arg(done_));
	}
}


