/********************************************************************************
** Form generated from reading UI file 'study.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDY_H
#define UI_STUDY_H

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

class Ui_Study
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_back;
    QSpacerItem *horizontalSpacer;
    QLabel *label_group;
    QSpacerItem *verticalSpacer;
    QLabel *label_word;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_sent;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_favorite;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_next;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *Study)
    {
        if (Study->objectName().isEmpty())
            Study->setObjectName(QString::fromUtf8("Study"));
        Study->resize(648, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Study->setWindowIcon(icon);
        Study->setStyleSheet(QString::fromUtf8("#Study{\n"
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
"font-size:18px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(Study);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(Study);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setLayoutDirection(Qt::RightToLeft);
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:15px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QString::fromUtf8("toolButton_back"));
        toolButton_back->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/backicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_back->setIcon(icon1);

        horizontalLayout_2->addWidget(toolButton_back);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_group = new QLabel(frame);
        label_group->setObjectName(QString::fromUtf8("label_group"));
        label_group->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        horizontalLayout_2->addWidget(label_group);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        label_word = new QLabel(frame);
        label_word->setObjectName(QString::fromUtf8("label_word"));
        label_word->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);\n"
"font: 87 36pt \"Arial\";"));
        label_word->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_word);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        toolButton_sent = new QToolButton(frame);
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

        horizontalLayout_3->addWidget(toolButton_sent);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_5 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        toolButton_favorite = new QToolButton(frame);
        toolButton_favorite->setObjectName(QString::fromUtf8("toolButton_favorite"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/favorite_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_favorite->setIcon(icon3);
        toolButton_favorite->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(toolButton_favorite);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton_1 = new QToolButton(frame);
        toolButton_1->setObjectName(QString::fromUtf8("toolButton_1"));
        sizePolicy.setHeightForWidth(toolButton_1->sizePolicy().hasHeightForWidth());
        toolButton_1->setSizePolicy(sizePolicy);
        toolButton_1->setMinimumSize(QSize(0, 40));
        toolButton_1->setStyleSheet(QString::fromUtf8("QToolButton{     \n"
"background: rgba(0,0,0,0.2);\n"
"}\n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"background: rgb(255, 0, 0); \n"
"}"));
        toolButton_1->setCheckable(true);
        toolButton_1->setChecked(false);

        verticalLayout->addWidget(toolButton_1);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(0, 40));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{     \n"
"background: rgba(0,0,0,0.2);\n"
"}\n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"background: rgb(0, 0, 255); \n"
"}"));
        toolButton_2->setCheckable(true);
        toolButton_2->setChecked(false);

        verticalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        toolButton_3->setMinimumSize(QSize(0, 40));
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton{     \n"
"background: rgba(0,0,0,0.2);\n"
"}\n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"background: rgb(255, 0, 0); \n"
"}"));
        toolButton_3->setCheckable(true);
        toolButton_3->setChecked(false);

        verticalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        sizePolicy.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy);
        toolButton_4->setMinimumSize(QSize(0, 40));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{     \n"
"background: rgba(0,0,0,0.2);\n"
"}\n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"background: rgb(255, 0, 0); \n"
"}"));
        toolButton_4->setCheckable(true);
        toolButton_4->setChecked(false);

        verticalLayout->addWidget(toolButton_4);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        pushButton_next = new QPushButton(frame);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_next->sizePolicy().hasHeightForWidth());
        pushButton_next->setSizePolicy(sizePolicy1);
        pushButton_next->setMinimumSize(QSize(80, 30));
        pushButton_next->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(pushButton_next);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout->addWidget(frame);


        retranslateUi(Study);

        QMetaObject::connectSlotsByName(Study);
    } // setupUi

    void retranslateUi(QWidget *Study)
    {
        Study->setWindowTitle(QCoreApplication::translate("Study", "\345\255\246\344\271\240", nullptr));
        toolButton_back->setText(QString());
        label_group->setText(QCoreApplication::translate("Study", "\346\234\254\347\273\204\345\255\246\344\271\240 0/20", nullptr));
        label_word->setText(QCoreApplication::translate("Study", "therefore", nullptr));
        toolButton_sent->setText(QCoreApplication::translate("Study", "/\342\200\230\303\260e\311\231f\311\224:/", nullptr));
        toolButton_favorite->setText(QCoreApplication::translate("Study", "...", nullptr));
        toolButton_1->setText(QCoreApplication::translate("Study", "n.\350\210\252\350\241\214\357\274\233\350\210\252\346\265\267\346\234\257\357\274\233\345\257\274\350\210\252", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Study", "ad.\345\233\240\346\255\244\357\274\214\346\211\200\344\273\245\343\200\220\347\273\235\345\257\271\344\270\215\345\217\257\344\273\245\347\233\264\346\216\245\350\277\236\346\216\245\344\270\244\344\270\252\347\213\254\347\253\213\347\232\204\345\217\245\345\255\220\343\200\221", nullptr));
        toolButton_3->setText(QCoreApplication::translate("Study", "vi. (fml)\347\262\230\351\231\204;\350\277\275\351\232\217;\345\235\232\346\214\201(~ to sth)", nullptr));
        toolButton_4->setText(QCoreApplication::translate("Study", "n.\350\265\267\346\213\206\357\274\214\350\257\211\350\256\274\343\200\220\345\205\266\345\212\250\350\257\215\345\275\242\345\274\217\344\270\272sue\343\200\221vt.\351\200\202\345\220\210", nullptr));
        pushButton_next->setText(QCoreApplication::translate("Study", "\344\270\213\344\270\252\345\215\225\350\257\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Study: public Ui_Study {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDY_H
