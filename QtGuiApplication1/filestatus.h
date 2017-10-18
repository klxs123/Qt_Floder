#pragma once

#include <QDialog>

#include "ui_filestatus.h"


class FileStatus : public QDialog
{
	Q_OBJECT

public:
	FileStatus(QWidget *parent = Q_NULLPTR);
	~FileStatus();

public slots:
	void OnBrowerClick();
	void OnAnalysisClick();
	QString dealline(QString dealstr);
	void OnItemClicked(QTreeWidgetItem *, int);

private:
	Ui::FileStatus ui;
	QString m_curDir;
};
