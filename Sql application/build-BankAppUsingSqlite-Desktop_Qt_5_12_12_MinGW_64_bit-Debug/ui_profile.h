/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QPushButton *pushButton_AccountDetails;
    QPushButton *pushButton_Transfer;
    QPushButton *pushButton_Balance;
    QPushButton *pushButton_Logout;
    QTableView *tableView;

    void setupUi(QDialog *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName(QString::fromUtf8("Profile"));
        Profile->resize(565, 373);
        pushButton_AccountDetails = new QPushButton(Profile);
        pushButton_AccountDetails->setObjectName(QString::fromUtf8("pushButton_AccountDetails"));
        pushButton_AccountDetails->setGeometry(QRect(20, 40, 111, 41));
        pushButton_Transfer = new QPushButton(Profile);
        pushButton_Transfer->setObjectName(QString::fromUtf8("pushButton_Transfer"));
        pushButton_Transfer->setGeometry(QRect(150, 40, 111, 41));
        pushButton_Balance = new QPushButton(Profile);
        pushButton_Balance->setObjectName(QString::fromUtf8("pushButton_Balance"));
        pushButton_Balance->setGeometry(QRect(270, 40, 111, 41));
        pushButton_Logout = new QPushButton(Profile);
        pushButton_Logout->setObjectName(QString::fromUtf8("pushButton_Logout"));
        pushButton_Logout->setGeometry(QRect(390, 40, 111, 41));
        tableView = new QTableView(Profile);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 100, 471, 231));

        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QDialog *Profile)
    {
        Profile->setWindowTitle(QApplication::translate("Profile", "Dialog", nullptr));
        pushButton_AccountDetails->setText(QApplication::translate("Profile", "Account Details", nullptr));
        pushButton_Transfer->setText(QApplication::translate("Profile", "Transfer", nullptr));
        pushButton_Balance->setText(QApplication::translate("Profile", "Balance", nullptr));
        pushButton_Logout->setText(QApplication::translate("Profile", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
