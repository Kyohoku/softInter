/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_username;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_pwd;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_login;
    QPushButton *pushButton_register;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(440, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QString::fromUtf8("#Login{\n"
"border-image: url(:/res/bluebackground.jpg);\n"
"border-width : 1px;\n"
"\n"
"border-color : #1ea4f2;\n"
"\n"
"border-style : solid;\n"
"\n"
"border-width : 1px;\n"
"}\n"
"\n"
"\n"
"*{\n"
"font-size:22px;\n"
"}\n"
"\n"
"#frame{border-radius:15px;}"));
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Login);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0.8);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEdit_username = new QLineEdit(frame);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_username->sizePolicy().hasHeightForWidth());
        lineEdit_username->setSizePolicy(sizePolicy);
        lineEdit_username->setMinimumSize(QSize(300, 0));
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(lineEdit_username);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        lineEdit_pwd = new QLineEdit(frame);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));
        lineEdit_pwd->setMinimumSize(QSize(300, 0));
        lineEdit_pwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEdit_pwd);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_login = new QPushButton(frame);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_login->sizePolicy().hasHeightForWidth());
        pushButton_login->setSizePolicy(sizePolicy1);
        pushButton_login->setMinimumSize(QSize(120, 40));
        pushButton_login->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_login);

        pushButton_register = new QPushButton(frame);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        sizePolicy1.setHeightForWidth(pushButton_register->sizePolicy().hasHeightForWidth());
        pushButton_register->setSizePolicy(sizePolicy1);
        pushButton_register->setMinimumSize(QSize(120, 40));
        pushButton_register->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_register);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(frame);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Login", "UserName", nullptr));
        lineEdit_pwd->setPlaceholderText(QCoreApplication::translate("Login", "PassWord", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
