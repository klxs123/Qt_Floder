/********************************************************************************
** Form generated from reading UI file 'filestatus.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESTATUS_H
#define UI_FILESTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileStatus
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_leFolder;
    QPushButton *m_btBrowser;
    QTreeWidget *m_twFiles;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *my_commentaries;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_btAnalysis;

    void setupUi(QDialog *FileStatus)
    {
        if (FileStatus->objectName().isEmpty())
            FileStatus->setObjectName(QStringLiteral("FileStatus"));
        FileStatus->resize(589, 327);
        verticalLayout = new QVBoxLayout(FileStatus);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(FileStatus);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        m_leFolder = new QLineEdit(FileStatus);
        m_leFolder->setObjectName(QStringLiteral("m_leFolder"));

        horizontalLayout->addWidget(m_leFolder);

        m_btBrowser = new QPushButton(FileStatus);
        m_btBrowser->setObjectName(QStringLiteral("m_btBrowser"));

        horizontalLayout->addWidget(m_btBrowser);


        verticalLayout->addLayout(horizontalLayout);

        m_twFiles = new QTreeWidget(FileStatus);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_twFiles->setHeaderItem(__qtreewidgetitem);
        m_twFiles->setObjectName(QStringLiteral("m_twFiles"));

        verticalLayout->addWidget(m_twFiles);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        my_commentaries = new QCheckBox(FileStatus);
        my_commentaries->setObjectName(QStringLiteral("my_commentaries"));

        horizontalLayout_2->addWidget(my_commentaries);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_btAnalysis = new QPushButton(FileStatus);
        m_btAnalysis->setObjectName(QStringLiteral("m_btAnalysis"));

        horizontalLayout_2->addWidget(m_btAnalysis);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FileStatus);

        QMetaObject::connectSlotsByName(FileStatus);
    } // setupUi

    void retranslateUi(QDialog *FileStatus)
    {
        FileStatus->setWindowTitle(QApplication::translate("FileStatus", "FileStatus", Q_NULLPTR));
        label->setText(QApplication::translate("FileStatus", "Folder:", Q_NULLPTR));
        m_btBrowser->setText(QApplication::translate("FileStatus", "Browser...", Q_NULLPTR));
        my_commentaries->setText(QApplication::translate("FileStatus", "no commentary", Q_NULLPTR));
        m_btAnalysis->setText(QApplication::translate("FileStatus", "Analysis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileStatus: public Ui_FileStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESTATUS_H
