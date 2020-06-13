/********************************************************************************
** Form generated from reading UI file 'fly_war.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLY_WAR_H
#define UI_FLY_WAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fly_war
{
public:

    void setupUi(QWidget *fly_war)
    {
        if (fly_war->objectName().isEmpty())
            fly_war->setObjectName(QStringLiteral("fly_war"));
        fly_war->resize(400, 300);
        fly_war->setMinimumSize(QSize(0, 300));

        retranslateUi(fly_war);

        QMetaObject::connectSlotsByName(fly_war);
    } // setupUi

    void retranslateUi(QWidget *fly_war)
    {
        fly_war->setWindowTitle(QApplication::translate("fly_war", "fly_war", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fly_war: public Ui_fly_war {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLY_WAR_H
