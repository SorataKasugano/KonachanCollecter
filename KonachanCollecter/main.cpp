#include "konachancollecter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KonachanCollecter w;
	w.show();
	return a.exec();
}
