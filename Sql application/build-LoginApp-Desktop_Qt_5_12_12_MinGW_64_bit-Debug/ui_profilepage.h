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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
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
    QWidget *layoutWidget;
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_balance;
    QLineEdit *lineEdit_balance;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QTableView *tableView;
    QListView *listView;
    QComboBox *comboBox;

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
        pushButton_load->setGeometry(QRect(390, 270, 75, 23));
        pushButton_update = new QPushButton(ProfilePage);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));
        pushButton_update->setGeometry(QRect(100, 200, 75, 23));
        pushButton_delete = new QPushButton(ProfilePage);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(190, 200, 75, 23));
        layoutWidget = new QWidget(ProfilePage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 251, 164));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_surname = new QLabel(layoutWidget);
        label_surname->setObjectName(QString::fromUtf8("label_surname"));

        horizontalLayout_2->addWidget(label_surname);

        lineEdit_surname = new QLineEdit(layoutWidget);
        lineEdit_surname->setObjectName(QString::fromUtf8("lineEdit_surname"));

        horizontalLayout_2->addWidget(lineEdit_surname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_email = new QLabel(layoutWidget);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        horizontalLayout_3->addWidget(label_email);

        lineEdit_email = new QLineEdit(layoutWidget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        horizontalLayout_3->addWidget(lineEdit_email);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_balance = new QLabel(layoutWidget);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));

        horizontalLayout_5->addWidget(label_balance);

        lineEdit_balance = new QLineEdit(layoutWidget);
        lineEdit_balance->setObjectName(QString::fromUtf8("lineEdit_balance"));

        horizontalLayout_5->addWidget(lineEdit_balance);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_username = new QLabel(layoutWidget);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        horizontalLayout_6->addWidget(label_username);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));

        horizontalLayout_6->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_password = new QLabel(layoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        horizontalLayout_4->addWidget(label_password);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_4->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_4);

        tableView = new QTableView(ProfilePage);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(440, 40, 181, 211));
        listView = new QListView(ProfilePage);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(280, 40, 141, 211));
        comboBox = new QComboBox(ProfilePage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(330, 300, 171, 41));

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
        lineEdit_name->setPlaceholderText(QApplication::translate("ProfilePage", "Name", nullptr));
        label_surname->setText(QApplication::translate("ProfilePage", "Surname", nullptr));
        lineEdit_surname->setPlaceholderText(QApplication::translate("ProfilePage", "Surname", nullptr));
        label_email->setText(QApplication::translate("ProfilePage", "Email Id", nullptr));
        lineEdit_email->setPlaceholderText(QApplication::translate("ProfilePage", "Email", nullptr));
        label_balance->setText(QApplication::translate("ProfilePage", "Balance", nullptr));
        lineEdit_balance->setPlaceholderText(QApplication::translate("ProfilePage", "0.0", nullptr));
        label_username->setText(QApplication::translate("ProfilePage", "Username", nullptr));
        lineEdit_username->setPlaceholderText(QApplication::translate("ProfilePage", "Email", nullptr));
        label_password->setText(QApplication::translate("ProfilePage", "PassWord", nullptr));
        lineEdit_password->setPlaceholderText(QApplication::translate("ProfilePage", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfilePage: public Ui_ProfilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEPAGE_H
