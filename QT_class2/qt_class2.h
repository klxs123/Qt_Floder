#pragma once

#include <QtWidgets/QWidget>
#include <ActiveQt/QAxBindable>

#include "ui_qt_class2.h"

class qt_class2 : public QWidget, public QAxBindable
{
	Q_OBJECT

public:
	qt_class2(QWidget *parent = Q_NULLPTR);

private:
	Ui::qt_class2Class ui;
};
