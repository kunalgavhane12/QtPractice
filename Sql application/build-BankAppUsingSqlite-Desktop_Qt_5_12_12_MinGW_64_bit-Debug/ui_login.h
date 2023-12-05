/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_Username;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_password;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_Login;
    QLabel *label_Status;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Email;
    QLineEdit *lineEdit_Email;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Deposit_Amount;
    QLineEdit *lineEdit_deposit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_fusername;
    QLineEdit *lineEdit_fusername;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_fpassword;
    QLineEdit *lineEdit_fpassword;
    QPushButton *pushButton_CreateAccount;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(390, 90, 301, 171));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        verticalLayout->addWidget(label_username);

        lineEdit_Username = new QLineEdit(groupBox);
        lineEdit_Username->setObjectName(QString::fromUtf8("lineEdit_Username"));

        verticalLayout->addWidget(lineEdit_Username);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        verticalLayout_2->addWidget(label_password);

        lineEdit_Password = new QLineEdit(groupBox);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));

        verticalLayout_2->addWidget(lineEdit_Password);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_Login = new QPushButton(groupBox);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));

        verticalLayout_3->addWidget(pushButton_Login);

        label_Status = new QLabel(centralwidget);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setGeometry(QRect(10, 340, 291, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 70, 341, 241));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Name = new QLabel(groupBox_2);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        horizontalLayout->addWidget(label_Name);

        lineEdit_name = new QLineEdit(groupBox_2);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_Email = new QLabel(groupBox_2);
        label_Email->setObjectName(QString::fromUtf8("label_Email"));

        horizontalLayout_4->addWidget(label_Email);

        lineEdit_Email = new QLineEdit(groupBox_2);
        lineEdit_Email->setObjectName(QString::fromUtf8("lineEdit_Email"));

        horizontalLayout_4->addWidget(lineEdit_Email);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_Deposit_Amount = new QLabel(groupBox_2);
        label_Deposit_Amount->setObjectName(QString::fromUtf8("label_Deposit_Amount"));

        horizontalLayout_5->addWidget(label_Deposit_Amount);

        lineEdit_deposit = new QLineEdit(groupBox_2);
        lineEdit_deposit->setObjectName(QString::fromUtf8("lineEdit_deposit"));

        horizontalLayout_5->addWidget(lineEdit_deposit);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_fusername = new QLabel(groupBox_2);
        label_fusername->setObjectName(QString::fromUtf8("label_fusername"));

        horizontalLayout_6->addWidget(label_fusername);

        lineEdit_fusername = new QLineEdit(groupBox_2);
        lineEdit_fusername->setObjectName(QString::fromUtf8("lineEdit_fusername"));
        lineEdit_fusername->setReadOnly(false);

        horizontalLayout_6->addWidget(lineEdit_fusername);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_fpassword = new QLabel(groupBox_2);
        label_fpassword->setObjectName(QString::fromUtf8("label_fpassword"));

        horizontalLayout_7->addWidget(label_fpassword);

        lineEdit_fpassword = new QLineEdit(groupBox_2);
        lineEdit_fpassword->setObjectName(QString::fromUtf8("lineEdit_fpassword"));

        horizontalLayout_7->addWidget(lineEdit_fpassword);


        verticalLayout_4->addLayout(horizontalLayout_7);

        pushButton_CreateAccount = new QPushButton(groupBox_2);
        pushButton_CreateAccount->setObjectName(QString::fromUtf8("pushButton_CreateAccount"));

        verticalLayout_4->addWidget(pushButton_CreateAccount);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 20, 201, 21));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        groupBox->setTitle(QApplication::translate("Login", "Login", nullptr));
        label_username->setText(QApplication::translate("Login", "UserName", nullptr));
        lineEdit_Username->setPlaceholderText(QApplication::translate("Login", "Enter Username", nullptr));
        label_password->setText(QApplication::translate("Login", "Password", nullptr));
        lineEdit_Password->setPlaceholderText(QApplication::translate("Login", "Enter Password", nullptr));
        pushButton_Login->setText(QApplication::translate("Login", "Login", nullptr));
        label_Status->setText(QApplication::translate("Login", "Status", nullptr));
        groupBox_2->setTitle(QApplication::translate("Login", "Account Openning Form", nullptr));
        label_Name->setText(QApplication::translate("Login", "Name", nullptr));
        lineEdit_name->setPlaceholderText(QApplication::translate("Login", "Enter Full Name", nullptr));
        label_Email->setText(QApplication::translate("Login", "Email-Id", nullptr));
        lineEdit_Email->setPlaceholderText(QApplication::translate("Login", "Enter email", nullptr));
        label_Deposit_Amount->setText(QApplication::translate("Login", "Deposit Amount", nullptr));
        lineEdit_deposit->setPlaceholderText(QApplication::translate("Login", "Enter Deposit Amount", nullptr));
        label_fusername->setText(QApplication::translate("Login", "Username", nullptr));
        lineEdit_fusername->setPlaceholderText(QApplication::translate("Login", "Enter Email", nullptr));
        label_fpassword->setText(QApplication::translate("Login", "Password", nullptr));
        lineEdit_fpassword->setPlaceholderText(QApplication::translate("Login", "Enter Password", nullptr));
        pushButton_CreateAccount->setText(QApplication::translate("Login", "Create Account", nullptr));
        label->setText(QApplication::translate("Login", "Banking Application", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
