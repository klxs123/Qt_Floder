#include "filestatus.h"
#include <iostream>
#include <QFileDialog>
#include <QList>
#include <QListWidgetItem>
#include <QString>
#include <QTextEdit>
#include <QTextStream>

using namespace std;

static bool FLAG_COMMENT = 0;
//char* dealdata = new char[256];

QString dealdatas;

static void RecurseDirectory(const QString& sDir, QList<QString>& files)
{
	QDir dir(sDir);

	QFileInfoList list = dir.entryInfoList();

	for (QFileInfoList::Iterator it = list.begin(); it != list.end(); it++)
	{
		QFileInfo info = *it;

		if (info.isDir())
		{
			if (info.fileName() != ".." && info.fileName() != ".")
			{
				QString sFilePath = info.filePath();
				RecurseDirectory(sFilePath, files);
			}
		}
		else
		{
			if (info.isFile() && info.fileName().endsWith(".cpp"))
				files.push_back(info.absoluteFilePath());

		}
	}
}

FileStatus::FileStatus(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.my_commentaries->setChecked(true);


	ui.m_twFiles->setColumnCount(3);
	QStringList sl;
	sl << QObject::tr("File Name") << "Size" << "Full Path";
	ui.m_twFiles->setHeaderLabels(sl);

	//QObject::connect(ui.my_commentaries, SIGNAL(clicked()), this, SLOT(OnBrowerClick()));
	QObject::connect(ui.m_btBrowser, SIGNAL(clicked()), this, SLOT(OnBrowerClick()));
	QObject::connect(ui.m_btAnalysis, SIGNAL(clicked()), this, SLOT(OnAnalysisClick()));
	QObject::connect(ui.m_twFiles, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(OnItemClicked(QTreeWidgetItem *, int)));
}

FileStatus::~FileStatus(){}

void FileStatus::OnAnalysisClick()
{
	ui.m_twFiles->clear();

	if (m_curDir.isEmpty())
	{
		ui.m_btBrowser->setFocus();
		return;
	}

	QList<QString> files;

	RecurseDirectory(m_curDir, files);

	for (QList<QString>::iterator it = files.begin(); it != files.end(); it++)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem(ui.m_twFiles);

		item->setText(2, *it);

		QFileInfo fileInfo(*it);

		item->setText(0, fileInfo.fileName());

		item->setText(1, QString::number(fileInfo.size(), 10));
	}

}

void FileStatus::OnItemClicked(QTreeWidgetItem *item, int column)
{
	QString file = item->text(2);
	QTextEdit *qe = new QTextEdit();
	QFile f(file);
	f.open(QFile::ReadOnly);
	QTextStream ts(&f);

	if (ui.my_commentaries->isChecked())
	{
		//QString str ;
		//QString str1 = str.section(QRegExp(QString("[\r,\n]")), 0);
		qe->setText(dealline(ts.readAll()));
	}
	else
	{
		qe->setText(ts.readAll());
		
	}
	qe->show();
}

void FileStatus::OnBrowerClick()
{

	QString dir = QFileDialog::getExistingDirectory(this, "select folder...");

	if (m_curDir == dir)
	{
		return;
	}

	m_curDir = dir;

	ui.m_leFolder->setText(dir);
}


QString  FileStatus::dealline(QString dealstr)
{
	int flag = 0;
	int flag_doub = 0;
	int writecount = 0;

	for (int readcount = 0;dealstr[readcount] != 0;readcount++,writecount++)
	{
		if ('/' == dealstr[readcount])
		{
			if ('/' == dealstr[readcount + 1])
			{
				dealdatas[writecount] = 13;
				dealdatas[++writecount] = 10;
				
				while ('\n' != dealstr[++readcount])
				{
					;
				}
				writecount--;
				continue;
			}
			else if ('*' == dealstr[readcount + 1])
			{
				while (dealstr[readcount] !=  0)
				{
					if ('*' == dealstr[++readcount] && '/' == dealstr[readcount + 1])
					{
						dealdatas[writecount] = 13;
						dealdatas[++writecount] = 10;
						break;
					}
				}
				writecount--;
				readcount++;
				continue;
			}
		}
		dealdatas[writecount] = dealstr[readcount];

	}
	return dealdatas;
}