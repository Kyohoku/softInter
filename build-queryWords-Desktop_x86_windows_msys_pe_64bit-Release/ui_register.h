/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_username;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_pwd;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_pwd_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_register;
    QPushButton *pushButton_back;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(480, 320);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Register->setWindowIcon(icon);
        Register->setStyleSheet(QString::fromUtf8("#Register{\n"
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
        horizontalLayout = new QHBoxLayout(Register);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(Register);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0.8);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEdit_username = new QLineEdit(frame);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setMinimumSize(QSize(300, 0));
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(lineEdit_username);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        lineEdit_pwd = new QLineEdit(frame);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));
        lineEdit_pwd->setMinimumSize(QSize(300, 0));
        lineEdit_pwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(lineEdit_pwd);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        lineEdit_pwd_2 = new QLineEdit(frame);
        lineEdit_pwd_2->setObjectName(QString::fromUtf8("lineEdit_pwd_2"));
        lineEdit_pwd_2->setMinimumSize(QSize(300, 0));
        lineEdit_pwd_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_pwd_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEdit_pwd_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_register = new QPushButton(frame);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_register->sizePolicy().hasHeightForWidth());
        pushButton_register->setSizePolicy(sizePolicy);
        pushButton_register->setMinimumSize(QSize(120, 40));
        pushButton_register->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_register);

        pushButton_back = new QPushButton(frame);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        sizePolicy.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy);
        pushButton_back->setMinimumSize(QSize(120, 40));
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_back);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addWidget(frame);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Register", "UserName", nullptr));
        lineEdit_pwd->setPlaceholderText(QCoreApplication::translate("Register", "PassWord", nullptr));
        lineEdit_pwd_2->setPlaceholderText(QCoreApplication::translate("Register", "Verify Password", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Register", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
