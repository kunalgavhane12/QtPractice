/********************************************************************************
** Form generated from reading UI file 'accountopen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTOPEN_H
#define UI_ACCOUNTOPEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountOpen
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AccountOpen)
    {
        if (AccountOpen->objectName().isEmpty())
            AccountOpen->setObjectName(QString::fromUtf8("AccountOpen"));
        AccountOpen->resize(414, 374);
        label = new QLabel(AccountOpen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 281, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        widget = new QWidget(AccountOpen);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 60, 361, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        widget1 = new QWidget(AccountOpen);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 140, 311, 21));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);

        widget2 = new QWidget(AccountOpen);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(20, 110, 241, 21));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        widget3 = new QWidget(AccountOpen);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(20, 170, 192, 22));
        horizontalLayout_5 = new QHBoxLayout(widget3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEdit_5 = new QLineEdit(widget3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_5->addWidget(lineEdit_5);

        widget4 = new QWidget(AccountOpen);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(20, 210, 291, 41));
        horizontalLayout_3 = new QHBoxLayout(widget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        retranslateUi(AccountOpen);

        QMetaObject::connectSlotsByName(AccountOpen);
    } // setupUi

    void retranslateUi(QDialog *AccountOpen)
    {
        AccountOpen->setWindowTitle(QApplication::translate("AccountOpen", "Dialog", nullptr));
        label->setText(QApplication::translate("AccountOpen", "Account Opening Form", nullptr));
        label_2->setText(QApplication::translate("AccountOpen", "Name", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("AccountOpen", "Full Name", nullptr));
        label_5->setText(QApplication::translate("AccountOpen", "Email Id", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("AccountOpen", "xyz@email.com", nullptr));
        label_3->setText(QApplication::translate("AccountOpen", "Mobile No.", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("AccountOpen", "Mobile Number", nullptr));
        label_6->setText(QApplication::translate("AccountOpen", "Addhar No", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("AccountOpen", "Adhar", nullptr));
        pushButton->setText(QApplication::translate("AccountOpen", "Save", nullptr));
        pushButton_2->setText(QApplication::translate("AccountOpen", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountOpen: public Ui_AccountOpen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTOPEN_H
