/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_word;
    QPushButton *pushButton_query;
    QToolButton *toolButton_user;
    QLabel *label_username;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_sent;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_meaning;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_study;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_review;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_cet4;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButton_cet6;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(648, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("#Widget{\n"
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
""));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 40));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0.8);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_word = new QLineEdit(frame);
        lineEdit_word->setObjectName(QString::fromUtf8("lineEdit_word"));
        lineEdit_word->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit_word);

        pushButton_query = new QPushButton(frame);
        pushButton_query->setObjectName(QString::fromUtf8("pushButton_query"));
        sizePolicy.setHeightForWidth(pushButton_query->sizePolicy().hasHeightForWidth());
        pushButton_query->setSizePolicy(sizePolicy);
        pushButton_query->setMinimumSize(QSize(60, 30));
        pushButton_query->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_query);

        toolButton_user = new QToolButton(frame);
        toolButton_user->setObjectName(QString::fromUtf8("toolButton_user"));
        toolButton_user->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_user->setIcon(icon1);
        toolButton_user->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(toolButton_user);

        label_username = new QLabel(frame);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background:transparent;\n"
"font-size:12px;\n"
""));
        label_username->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_username);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        toolButton_sent = new QToolButton(Widget);
        toolButton_sent->setObjectName(QString::fromUtf8("toolButton_sent"));
        sizePolicy.setHeightForWidth(toolButton_sent->sizePolicy().hasHeightForWidth());
        toolButton_sent->setSizePolicy(sizePolicy);
        toolButton_sent->setContextMenuPolicy(Qt::PreventContextMenu);
        toolButton_sent->setLayoutDirection(Qt::RightToLeft);
        toolButton_sent->setAutoFillBackground(false);
        toolButton_sent->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:12px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/sound2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_sent->setIcon(icon2);
        toolButton_sent->setIconSize(QSize(24, 24));
        toolButton_sent->setPopupMode(QToolButton::DelayedPopup);
        toolButton_sent->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_sent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        label_meaning = new QLabel(Widget);
        label_meaning->setObjectName(QString::fromUtf8("label_meaning"));
        label_meaning->setStyleSheet(QString::fromUtf8("font-size:16px;"));

        horizontalLayout_5->addWidget(label_meaning);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:15px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_study = new QPushButton(frame_2);
        pushButton_study->setObjectName(QString::fromUtf8("pushButton_study"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_study->sizePolicy().hasHeightForWidth());
        pushButton_study->setSizePolicy(sizePolicy1);
        pushButton_study->setMinimumSize(QSize(120, 30));
        pushButton_study->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(pushButton_study);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_review = new QPushButton(frame_2);
        pushButton_review->setObjectName(QString::fromUtf8("pushButton_review"));
        sizePolicy1.setHeightForWidth(pushButton_review->sizePolicy().hasHeightForWidth());
        pushButton_review->setSizePolicy(sizePolicy1);
        pushButton_review->setMinimumSize(QSize(120, 30));
        pushButton_review->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(pushButton_review);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        toolButton_cet4 = new QToolButton(frame_2);
        toolButton_cet4->setObjectName(QString::fromUtf8("toolButton_cet4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton_cet4->sizePolicy().hasHeightForWidth());
        toolButton_cet4->setSizePolicy(sizePolicy2);
        toolButton_cet4->setMinimumSize(QSize(0, 0));
        toolButton_cet4->setLayoutDirection(Qt::RightToLeft);
        toolButton_cet4->setStyleSheet(QString::fromUtf8("QToolButton{     \n"
"background: rgba(0,0,0,0.4);\n"
"}\n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"background: rgb(255, 0, 0); \n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/bandfouricon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_cet4->setIcon(icon3);
        toolButton_cet4->setIconSize(QSize(160, 180));
        toolButton_cet4->setCheckable(true);
        toolButton_cet4->setChecked(false);
        toolButton_cet4->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_4->addWidget(toolButton_cet4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        toolButton_cet6 = new QToolButton(frame_2);
        toolButton_cet6->setObjectName(QString::fromUtf8("toolButton_cet6"));
        toolButton_cet6->setStyleSheet(QString::fromUtf8("QToolButton{     \n"
"background: rgba(0,0,0,0.4);\n"
"}\n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"background: rgb(255, 0, 0); \n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/bandsixicon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_cet6->setIcon(icon4);
        toolButton_cet6->setIconSize(QSize(160, 180));
        toolButton_cet6->setCheckable(true);
        toolButton_cet6->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_4->addWidget(toolButton_cet6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(frame_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lineEdit_word->setPlaceholderText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        pushButton_query->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
        toolButton_user->setText(QCoreApplication::translate("Widget", "...", nullptr));
        label_username->setText(QCoreApplication::translate("Widget", "\345\260\217\346\230\216\347\274\272\347\232\204\345\260\217\346\230\216\347\274\272\347\232\204\347\232\204\347\232\204", nullptr));
        toolButton_sent->setText(QCoreApplication::translate("Widget", "/\342\200\230\303\260e\311\231f\311\224:/", nullptr));
        label_meaning->setText(QCoreApplication::translate("Widget", "ad.\345\233\240\346\255\244\357\274\214\346\211\200\344\273\245\343\200\220\347\273\235\345\257\271\344\270\215\345\217\257\344\273\245\347\233\264\346\216\245\350\277\236\346\216\245\344\270\244\344\270\252\347\213\254\347\253\213\347\232\204\345\217\245\345\255\220\343\200\221", nullptr));
        pushButton_study->setText(QCoreApplication::translate("Widget", "\345\255\246\344\271\240", nullptr));
        pushButton_review->setText(QCoreApplication::translate("Widget", "\345\244\215\344\271\240", nullptr));
        toolButton_cet4->setText(QCoreApplication::translate("Widget", "CET4", nullptr));
        toolButton_cet6->setText(QCoreApplication::translate("Widget", "CET6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
