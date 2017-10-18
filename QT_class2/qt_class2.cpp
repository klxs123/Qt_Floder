#include "qt_class2.h"

#include <ActiveQt/QAxFactory>

qt_class2::qt_class2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QAXFACTORY_DEFAULT(qt_class2,
	"{dcf9f3a7-4602-4fdc-b67e-5e6af8dbb37c}",
	"{1e3dcd9e-af61-4e68-b26a-4960de602223}",
	"{3a73e15c-7b83-4c6f-9c6f-4c27397a7da9}",
	"{f9c4fa37-69c0-486a-a98d-8d699de0d07c}",
	"{489f4fcb-3851-4efa-8177-3372f9905ca2}"
)
