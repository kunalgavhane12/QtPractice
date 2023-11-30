/********************************************************************************
** Form generated from reading UI file 'loginapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINAPP_H
#define UI_LOGINAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginApp
{
public:
    QWidget *centralwidget;
    QLabel *label_status;
    QGroupBox *groupBox;
    QPushButton *Login;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *username;
    QLineEdit *lineEdit_username;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password;
    QLineEdit *lineEdit_password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginApp)
    {
        if (LoginApp->objectName().isEmpty())
            LoginApp->setObjectName(QString::fromUtf8("LoginApp"));
        LoginApp->resize(800, 600);
        centralwidget = new QWidget(LoginApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_status = new QLabel(centralwidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(60, 280, 241, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(270, 70, 241, 171));
        Login = new QPushButton(groupBox);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setGeometry(QRect(60, 110, 75, 23));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 190, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        username = new QLabel(widget);
        username->setObjectName(QString::fromUtf8("username"));

        horizontalLayout->addWidget(username);

        lineEdit_username = new QLineEdit(widget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));

        horizontalLayout->addWidget(lineEdit_username);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 70, 187, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        password = new QLabel(widget1);
        password->setObjectName(QString::fromUtf8("password"));

        horizontalLayout_2->addWidget(password);

        lineEdit_password = new QLineEdit(widget1);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_password);

        LoginApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginApp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        LoginApp->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginApp->setStatusBar(statusbar);

        retranslateUi(LoginApp);

        QMetaObject::connectSlotsByName(LoginApp);
    } // setupUi

    void retranslateUi(QMainWindow *LoginApp)
    {
        LoginApp->setWindowTitle(QApplication::translate("LoginApp", "LoginApp", nullptr));
        label_status->setText(QApplication::translate("LoginApp", "[+]Status", nullptr));
        groupBox->setTitle(QApplication::translate("LoginApp", "SignIn", nullptr));
        Login->setText(QApplication::translate("LoginApp", "Login", nullptr));
        username->setText(QApplication::translate("LoginApp", "UserName", nullptr));
        password->setText(QApplication::translate("LoginApp", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginApp: public Ui_LoginApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINAPP_H
