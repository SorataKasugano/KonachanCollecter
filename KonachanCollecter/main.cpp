#include "konachancollecter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KonachanCollecter w;
	w.show();
	// change qDebug&qInfo to logger
	qInstallMessageHandler([](QtMsgType type, const QMessageLogContext &context, const QString &msg) {
		QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
		QFile file("kc_log.txt");
		file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
#ifdef _DEBUG
		if (type == QtDebugMsg) file.write(QString("%1: %2 (%3:%4, %5)\n").arg(time).arg(msg).arg(context.file).arg(context.line).arg(context.function).toLocal8Bit());
#endif // _DEBUG
		if (type == QtInfoMsg) file.write(QString("%1: %2\n").arg(time).arg(msg).toLocal8Bit());
		file.close();
	});
	return a.exec();
}
