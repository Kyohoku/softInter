/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_back;
    QGridLayout *gridLayout;
    QProgressBar *progressBar_today;
    QLineEdit *lineEdit_study_num;
    QLabel *label_5;
    QLabel *label_username;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_review_num;
    QProgressBar *progressBar_total;
    QLabel *label_total_process;
    QLabel *label_today_process;
    QToolButton *toolButton;
    QGridLayout *gridLayout_chart;

    void setupUi(QWidget *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QString::fromUtf8("UserInfo"));
        UserInfo->resize(648, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        UserInfo->setWindowIcon(icon);
        UserInfo->setStyleSheet(QString::fromUtf8("#UserInfo{\n"
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
        horizontalLayout = new QHBoxLayout(UserInfo);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(UserInfo);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:15px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 9, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QString::fromUtf8("toolButton_back"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_back->sizePolicy().hasHeightForWidth());
        toolButton_back->setSizePolicy(sizePolicy);
        toolButton_back->setMinimumSize(QSize(0, 0));
        toolButton_back->setLayoutDirection(Qt::LeftToRight);
        toolButton_back->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/backicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_back->setIcon(icon1);

        horizontalLayout_2->addWidget(toolButton_back);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        progressBar_today = new QProgressBar(frame);
        progressBar_today->setObjectName(QString::fromUtf8("progressBar_today"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar_today->sizePolicy().hasHeightForWidth());
        progressBar_today->setSizePolicy(sizePolicy1);
        progressBar_today->setMinimumSize(QSize(350, 0));
        progressBar_today->setValue(24);

        gridLayout->addWidget(progressBar_today, 8, 1, 1, 1);

        lineEdit_study_num = new QLineEdit(frame);
        lineEdit_study_num->setObjectName(QString::fromUtf8("lineEdit_study_num"));
        sizePolicy.setHeightForWidth(lineEdit_study_num->sizePolicy().hasHeightForWidth());
        lineEdit_study_num->setSizePolicy(sizePolicy);
        lineEdit_study_num->setMinimumSize(QSize(0, 30));
        lineEdit_study_num->setStyleSheet(QString::fromUtf8("border-radius:0px;"));

        gridLayout->addWidget(lineEdit_study_num, 3, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        label_username = new QLabel(frame);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        sizePolicy.setHeightForWidth(label_username->sizePolicy().hasHeightForWidth());
        label_username->setSizePolicy(sizePolicy);
        label_username->setMinimumSize(QSize(0, 30));
        label_username->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_username, 1, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEdit_review_num = new QLineEdit(frame);
        lineEdit_review_num->setObjectName(QString::fromUtf8("lineEdit_review_num"));
        sizePolicy.setHeightForWidth(lineEdit_review_num->sizePolicy().hasHeightForWidth());
        lineEdit_review_num->setSizePolicy(sizePolicy);
        lineEdit_review_num->setMinimumSize(QSize(0, 30));
        lineEdit_review_num->setStyleSheet(QString::fromUtf8("border-radius:0px;"));

        gridLayout->addWidget(lineEdit_review_num, 5, 1, 1, 1);

        progressBar_total = new QProgressBar(frame);
        progressBar_total->setObjectName(QString::fromUtf8("progressBar_total"));
        sizePolicy1.setHeightForWidth(progressBar_total->sizePolicy().hasHeightForWidth());
        progressBar_total->setSizePolicy(sizePolicy1);
        progressBar_total->setMinimumSize(QSize(350, 0));
        progressBar_total->setValue(24);

        gridLayout->addWidget(progressBar_total, 6, 1, 1, 1);

        label_total_process = new QLabel(frame);
        label_total_process->setObjectName(QString::fromUtf8("label_total_process"));
        label_total_process->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label_total_process, 6, 2, 1, 1);

        label_today_process = new QLabel(frame);
        label_today_process->setObjectName(QString::fromUtf8("label_today_process"));
        label_today_process->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));

        gridLayout->addWidget(label_today_process, 8, 2, 1, 1);

        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(0, 30));
        toolButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(toolButton, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_chart = new QGridLayout();
        gridLayout_chart->setObjectName(QString::fromUtf8("gridLayout_chart"));
        gridLayout_chart->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(gridLayout_chart);


        horizontalLayout->addWidget(frame);


        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QWidget *UserInfo)
    {
        UserInfo->setWindowTitle(QCoreApplication::translate("UserInfo", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        toolButton_back->setText(QString());
#if QT_CONFIG(tooltip)
        lineEdit_study_num->setToolTip(QCoreApplication::translate("UserInfo", "\344\270\252\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("UserInfo", "\345\275\223\346\227\245\345\255\246\344\271\240\350\277\233\345\272\246:", nullptr));
        label_username->setText(QCoreApplication::translate("UserInfo", "\345\260\217\346\230\216\347\241\256", nullptr));
        label_3->setText(QCoreApplication::translate("UserInfo", "\346\257\217\346\227\245\346\234\200\345\244\247\345\244\215\344\271\240\351\207\217:", nullptr));
        label_4->setText(QCoreApplication::translate("UserInfo", "\346\200\273\345\255\246\344\271\240\350\277\233\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("UserInfo", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("UserInfo", "\346\257\217\346\227\245\346\234\200\345\244\247\345\255\246\344\271\240\351\207\217:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_review_num->setToolTip(QCoreApplication::translate("UserInfo", "\344\270\252\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        label_total_process->setText(QCoreApplication::translate("UserInfo", "10/6500", nullptr));
        label_today_process->setText(QCoreApplication::translate("UserInfo", "2/20", nullptr));
        toolButton->setText(QCoreApplication::translate("UserInfo", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
