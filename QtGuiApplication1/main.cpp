#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QListWidget>
#include <QTreeWidget>

#include "filestatus.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	FileStatus fs;
	fs.show();
	
	return a.exec();
}
