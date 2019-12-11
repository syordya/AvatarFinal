/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username;
    QCheckBox *checkMan;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QCheckBox *checkWoman;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *email;
    QPushButton *pushButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(685, 467);
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 340, 121, 31));
        QFont font;
        font.setPointSize(16);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:rgb(52, 101, 164)"));
        horizontalLayoutWidget = new QWidget(Register);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(170, 40, 311, 72));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        username = new QLineEdit(horizontalLayoutWidget);
        username->setObjectName(QString::fromUtf8("username"));
        QFont font1;
        font1.setPointSize(18);
        username->setFont(font1);

        horizontalLayout->addWidget(username);

        checkMan = new QCheckBox(Register);
        checkMan->setObjectName(QString::fromUtf8("checkMan"));
        checkMan->setGeometry(QRect(220, 280, 101, 23));
        checkMan->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(Register);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(170, 120, 311, 72));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(horizontalLayoutWidget_2);
        password->setObjectName(QString::fromUtf8("password"));
        password->setFont(font1);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password);

        checkWoman = new QCheckBox(Register);
        checkWoman->setObjectName(QString::fromUtf8("checkWoman"));
        checkWoman->setGeometry(QRect(370, 280, 92, 23));
        checkWoman->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(Register);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(170, 200, 311, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        email = new QLineEdit(horizontalLayoutWidget_3);
        email->setObjectName(QString::fromUtf8("email"));
        email->setFont(font1);

        horizontalLayout_3->addWidget(email);

        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 420, 101, 31));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(239, 41, 41)"));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Register", "Registrarse", nullptr));
        label->setText(QCoreApplication::translate("Register", "Username:", nullptr));
        checkMan->setText(QCoreApplication::translate("Register", "Hombre", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "Password:", nullptr));
        checkWoman->setText(QCoreApplication::translate("Register", "Mujer", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "Email:", nullptr));
        pushButton->setText(QCoreApplication::translate("Register", "Ingresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
