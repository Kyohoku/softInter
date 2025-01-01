/********************************************************************************
** Form generated from reading UI file 'review.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEW_H
#define UI_REVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Review
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_group;
    QToolButton *toolButton_back;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_word;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_sent;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_word_detail;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_known;
    QToolButton *toolButton_unknown;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_next;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Review)
    {
        if (Review->objectName().isEmpty())
            Review->setObjectName(QString::fromUtf8("Review"));
        Review->resize(648, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Review->setWindowIcon(icon);
        Review->setStyleSheet(QString::fromUtf8("#Review{\n"
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
"}"));
        horizontalLayout = new QHBoxLayout(Review);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(Review);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:15px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_group = new QLabel(frame);
        label_group->setObjectName(QString::fromUtf8("label_group"));
        label_group->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        horizontalLayout_2->addWidget(label_group);

        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QString::fromUtf8("toolButton_back"));
        toolButton_back->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/backicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_back->setIcon(icon1);

        horizontalLayout_2->addWidget(toolButton_back);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_word = new QLabel(frame);
        label_word->setObjectName(QString::fromUtf8("label_word"));
        label_word->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);\n"
"font: 87 36pt \"Arial\";"));
        label_word->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_word);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        toolButton_sent = new QToolButton(frame);
        toolButton_sent->setObjectName(QString::fromUtf8("toolButton_sent"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_sent->sizePolicy().hasHeightForWidth());
        toolButton_sent->setSizePolicy(sizePolicy);
        toolButton_sent->setContextMenuPolicy(Qt::PreventContextMenu);
        toolButton_sent->setLayoutDirection(Qt::RightToLeft);
        toolButton_sent->setAutoFillBackground(false);
        toolButton_sent->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:12px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/sound2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_sent->setIcon(icon2);
        toolButton_sent->setIconSize(QSize(24, 24));
        toolButton_sent->setPopupMode(QToolButton::DelayedPopup);
        toolButton_sent->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(toolButton_sent);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_word_detail = new QLabel(frame);
        label_word_detail->setObjectName(QString::fromUtf8("label_word_detail"));
        label_word_detail->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);\n"
"font-size:18px;"));
        label_word_detail->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_word_detail);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButton_known = new QToolButton(frame);
        toolButton_known->setObjectName(QString::fromUtf8("toolButton_known"));
        toolButton_known->setMinimumSize(QSize(100, 100));
        toolButton_known->setLayoutDirection(Qt::LeftToRight);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/smile.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_known->setIcon(icon3);
        toolButton_known->setIconSize(QSize(56, 56));
        toolButton_known->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_known);

        toolButton_unknown = new QToolButton(frame);
        toolButton_unknown->setObjectName(QString::fromUtf8("toolButton_unknown"));
        toolButton_unknown->setMinimumSize(QSize(100, 100));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/sad.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_unknown->setIcon(icon4);
        toolButton_unknown->setIconSize(QSize(56, 56));
        toolButton_unknown->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_unknown);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButton_next = new QPushButton(frame);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setMinimumSize(QSize(80, 30));
        pushButton_next->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(pushButton_next);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout->addWidget(frame);


        retranslateUi(Review);

        QMetaObject::connectSlotsByName(Review);
    } // setupUi

    void retranslateUi(QWidget *Review)
    {
        Review->setWindowTitle(QCoreApplication::translate("Review", "\345\244\215\344\271\240", nullptr));
        label_group->setText(QCoreApplication::translate("Review", "\346\234\254\347\273\204\345\244\215\344\271\240 0/20", nullptr));
        toolButton_back->setText(QString());
        label_word->setText(QCoreApplication::translate("Review", "therefore", nullptr));
        toolButton_sent->setText(QCoreApplication::translate("Review", "/\342\200\230\303\260e\311\231f\311\224:/", nullptr));
        label_word_detail->setText(QCoreApplication::translate("Review", "ad.\345\233\240\346\255\244\357\274\214\346\211\200\344\273\245\343\200\220\347\273\235\345\257\271\344\270\215\345\217\257\344\273\245\347\233\264\346\216\245\350\277\236\346\216\245\344\270\244\344\270\252\347\213\254\347\253\213\347\232\204\345\217\245\345\255\220\343\200\221", nullptr));
        toolButton_known->setText(QCoreApplication::translate("Review", "\350\256\244\350\257\206", nullptr));
        toolButton_unknown->setText(QCoreApplication::translate("Review", "\344\270\215\350\256\244\350\257\206", nullptr));
        pushButton_next->setText(QCoreApplication::translate("Review", "\344\270\213\344\270\252\345\215\225\350\257\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Review: public Ui_Review {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEW_H
