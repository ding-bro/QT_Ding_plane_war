/********************************************************************************
** Form generated from reading UI file 'hellmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLMODEL_H
#define UI_HELLMODEL_H

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

class Ui_hellmodel
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *hellmodel)
    {
        if (hellmodel->objectName().isEmpty())
            hellmodel->setObjectName(QStringLiteral("hellmodel"));
        hellmodel->resize(800, 600);
        menubar = new QMenuBar(hellmodel);
        menubar->setObjectName(QStringLiteral("menubar"));
        hellmodel->setMenuBar(menubar);
        centralwidget = new QWidget(hellmodel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        hellmodel->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(hellmodel);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        hellmodel->setStatusBar(statusbar);

        retranslateUi(hellmodel);

        QMetaObject::connectSlotsByName(hellmodel);
    } // setupUi

    void retranslateUi(QMainWindow *hellmodel)
    {
        hellmodel->setWindowTitle(QApplication::translate("hellmodel", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hellmodel: public Ui_hellmodel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLMODEL_H
