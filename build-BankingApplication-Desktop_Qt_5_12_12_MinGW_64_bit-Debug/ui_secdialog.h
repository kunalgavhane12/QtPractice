/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QPushButton *pushButton_account;
    QPushButton *pushButton_deposits;
    QPushButton *pushButton_transfer;
    QPushButton *pushButton_withdrawal;
    QPushButton *pushButton_balance;
    QPushButton *pushButton_Logout;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(400, 300);
        pushButton_account = new QPushButton(SecDialog);
        pushButton_account->setObjectName(QString::fromUtf8("pushButton_account"));
        pushButton_account->setGeometry(QRect(20, 40, 75, 23));
        pushButton_deposits = new QPushButton(SecDialog);
        pushButton_deposits->setObjectName(QString::fromUtf8("pushButton_deposits"));
        pushButton_deposits->setGeometry(QRect(100, 40, 75, 23));
        pushButton_transfer = new QPushButton(SecDialog);
        pushButton_transfer->setObjectName(QString::fromUtf8("pushButton_transfer"));
        pushButton_transfer->setGeometry(QRect(180, 40, 75, 23));
        pushButton_withdrawal = new QPushButton(SecDialog);
        pushButton_withdrawal->setObjectName(QString::fromUtf8("pushButton_withdrawal"));
        pushButton_withdrawal->setGeometry(QRect(260, 40, 75, 23));
        pushButton_balance = new QPushButton(SecDialog);
        pushButton_balance->setObjectName(QString::fromUtf8("pushButton_balance"));
        pushButton_balance->setGeometry(QRect(20, 70, 75, 23));
        pushButton_Logout = new QPushButton(SecDialog);
        pushButton_Logout->setObjectName(QString::fromUtf8("pushButton_Logout"));
        pushButton_Logout->setGeometry(QRect(100, 70, 75, 23));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Profile", nullptr));
        pushButton_account->setText(QApplication::translate("SecDialog", "Account", nullptr));
        pushButton_deposits->setText(QApplication::translate("SecDialog", "Deposits", nullptr));
        pushButton_transfer->setText(QApplication::translate("SecDialog", "Transfer", nullptr));
        pushButton_withdrawal->setText(QApplication::translate("SecDialog", "WithdDrawal", nullptr));
        pushButton_balance->setText(QApplication::translate("SecDialog", "Balance", nullptr));
        pushButton_Logout->setText(QApplication::translate("SecDialog", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
