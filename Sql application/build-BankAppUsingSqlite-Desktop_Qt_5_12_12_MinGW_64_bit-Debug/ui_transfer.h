/********************************************************************************
** Form generated from reading UI file 'transfer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transfer
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_FormAccountNo;
    QLineEdit *lineEdit_FromAccountNo;
    QLabel *label_ToAccountNo;
    QLineEdit *lineEdit_ToAccountNo;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Transfer;
    QLineEdit *lineEdit_Transfer;
    QPushButton *pushButton_TransferAmount;
    QLabel *label_Status;

    void setupUi(QDialog *Transfer)
    {
        if (Transfer->objectName().isEmpty())
            Transfer->setObjectName(QString::fromUtf8("Transfer"));
        Transfer->resize(400, 300);
        layoutWidget = new QWidget(Transfer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 321, 171));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_FormAccountNo = new QLabel(layoutWidget);
        label_FormAccountNo->setObjectName(QString::fromUtf8("label_FormAccountNo"));

        verticalLayout_2->addWidget(label_FormAccountNo);

        lineEdit_FromAccountNo = new QLineEdit(layoutWidget);
        lineEdit_FromAccountNo->setObjectName(QString::fromUtf8("lineEdit_FromAccountNo"));

        verticalLayout_2->addWidget(lineEdit_FromAccountNo);


        verticalLayout->addLayout(verticalLayout_2);

        label_ToAccountNo = new QLabel(layoutWidget);
        label_ToAccountNo->setObjectName(QString::fromUtf8("label_ToAccountNo"));

        verticalLayout->addWidget(label_ToAccountNo);

        lineEdit_ToAccountNo = new QLineEdit(layoutWidget);
        lineEdit_ToAccountNo->setObjectName(QString::fromUtf8("lineEdit_ToAccountNo"));

        verticalLayout->addWidget(lineEdit_ToAccountNo);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_Transfer = new QLabel(layoutWidget);
        label_Transfer->setObjectName(QString::fromUtf8("label_Transfer"));

        verticalLayout_3->addWidget(label_Transfer);

        lineEdit_Transfer = new QLineEdit(layoutWidget);
        lineEdit_Transfer->setObjectName(QString::fromUtf8("lineEdit_Transfer"));

        verticalLayout_3->addWidget(lineEdit_Transfer);


        verticalLayout_4->addLayout(verticalLayout_3);

        pushButton_TransferAmount = new QPushButton(layoutWidget);
        pushButton_TransferAmount->setObjectName(QString::fromUtf8("pushButton_TransferAmount"));

        verticalLayout_4->addWidget(pushButton_TransferAmount);

        label_Status = new QLabel(Transfer);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setGeometry(QRect(20, 260, 281, 31));

        retranslateUi(Transfer);

        QMetaObject::connectSlotsByName(Transfer);
    } // setupUi

    void retranslateUi(QDialog *Transfer)
    {
        Transfer->setWindowTitle(QApplication::translate("Transfer", "Dialog", nullptr));
        label_FormAccountNo->setText(QApplication::translate("Transfer", "Form Account Number", nullptr));
        label_ToAccountNo->setText(QApplication::translate("Transfer", "To Account Number", nullptr));
        label_Transfer->setText(QApplication::translate("Transfer", "Transfer Amount", nullptr));
        pushButton_TransferAmount->setText(QApplication::translate("Transfer", "Transfer Amount", nullptr));
        label_Status->setText(QApplication::translate("Transfer", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transfer: public Ui_Transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_H
