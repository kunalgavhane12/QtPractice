/********************************************************************************
** Form generated from reading UI file 'profilepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEPAGE_H
#define UI_PROFILEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfilePage
{
public:
    QPushButton *pushButton_save;
    QLabel *label_Profilepage_Status;
    QPushButton *pushButton_load;
    QPushButton *pushButton_update;
    QPushButton *pushButton_delete;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_surname;
    QLineEdit *lineEdit_surname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_password;
    QLineEdit *lineEdit_password;

    void setupUi(QDialog *ProfilePage)
    {
        if (ProfilePage->objectName().isEmpty())
            ProfilePage->setObjectName(QString::fromUtf8("ProfilePage"));
        ProfilePage->resize(637, 357);
        pushButton_save = new QPushButton(ProfilePage);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(10, 200, 75, 23));
        label_Profilepage_Status = new QLabel(ProfilePage);
        label_Profilepage_Status->setObjectName(QString::fromUtf8("label_Profilepage_Status"));
        label_Profilepage_Status->setGeometry(QRect(10, 240, 201, 31));
        pushButton_load = new QPushButton(ProfilePage);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(380, 280, 75, 23));
        pushButton_update = new QPushButton(ProfilePage);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));
        pushButton_update->setGeometry(QRect(100, 200, 75, 23));
        pushButton_delete = new QPushButton(ProfilePage);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(190, 200, 75, 23));
        widget = new QWidget(ProfilePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 211, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_name = new QLabel(widget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_surname = new QLabel(widget);
        label_surname->setObjectName(QString::fromUtf8("label_surname"));

        horizontalLayout_2->addWidget(label_surname);

        lineEdit_surname = new QLineEdit(widget);
        lineEdit_surname->setObjectName(QString::fromUtf8("lineEdit_surname"));

        horizontalLayout_2->addWidget(lineEdit_surname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_email = new QLabel(widget);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        horizontalLayout_3->addWidget(label_email);

        lineEdit_email = new QLineEdit(widget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        horizontalLayout_3->addWidget(lineEdit_email);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_password = new QLabel(widget);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        horizontalLayout_4->addWidget(label_password);

        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_4->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ProfilePage);

        QMetaObject::connectSlotsByName(ProfilePage);
    } // setupUi

    void retranslateUi(QDialog *ProfilePage)
    {
        ProfilePage->setWindowTitle(QApplication::translate("ProfilePage", "Dialog", nullptr));
        pushButton_save->setText(QApplication::translate("ProfilePage", "Save", nullptr));
        label_Profilepage_Status->setText(QApplication::translate("ProfilePage", "[+]Status", nullptr));
        pushButton_load->setText(QApplication::translate("ProfilePage", "Load", nullptr));
        pushButton_update->setText(QApplication::translate("ProfilePage", "Update", nullptr));
        pushButton_delete->setText(QApplication::translate("ProfilePage", "Delete", nullptr));
        label_name->setText(QApplication::translate("ProfilePage", "Name", nullptr));
        label_surname->setText(QApplication::translate("ProfilePage", "Surname", nullptr));
        label_email->setText(QApplication::translate("ProfilePage", "Email Id", nullptr));
        label_password->setText(QApplication::translate("ProfilePage", "PassWord", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfilePage: public Ui_ProfilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEPAGE_H
