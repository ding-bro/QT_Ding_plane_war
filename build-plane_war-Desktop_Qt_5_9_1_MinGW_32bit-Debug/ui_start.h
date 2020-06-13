/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName(QStringLiteral("start"));
        start->resize(800, 600);
        menubar = new QMenuBar(start);
        menubar->setObjectName(QStringLiteral("menubar"));
        start->setMenuBar(menubar);
        centralwidget = new QWidget(start);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        start->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(start);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        start->setStatusBar(statusbar);

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QMainWindow *start)
    {
        start->setWindowTitle(QApplication::translate("start", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
