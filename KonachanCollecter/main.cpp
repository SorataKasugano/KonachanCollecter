#include "konachancollecter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/konachan.ico"));
	KonachanCollecter w;
	w.show();
	return a.exec();
}
