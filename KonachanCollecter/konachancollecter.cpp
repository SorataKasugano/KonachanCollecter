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
	progress_map_.clear();
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
	// map keys:"todo" "dup" "new" "done"
	else progress_map_[progress.toStdString()]++;

	ui.label_progress->setText(QString("Downloading...[done:%1/%2 new:%2 dup:%3 sum:%4]")
		.arg(progress_map_["done"]).arg(progress_map_["new"]).arg(progress_map_["dup"]).arg(progress_map_["todo"]));
	ui.progressBar->setMaximum(progress_map_["new"]);
	ui.progressBar->setValue(progress_map_["done"]);

	if (progress_map_["done"] == progress_map_["new"] && (progress_map_["done"] != 0))
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		qInfo("Mission accomplished: details=[new:%d dup:%d sum:%d/%d]"
			, progress_map_["new"], progress_map_["dup"], progress_map_["done"] + progress_map_["dup"], progress_map_["todo"]);
		QMessageBox::about(this, "Congratulations!", QString("All images done.[%1/%2 new:%3]")
			.arg(progress_map_["done"] + progress_map_["dup"]).arg(progress_map_["todo"]).arg(progress_map_["new"]));
	}
}


