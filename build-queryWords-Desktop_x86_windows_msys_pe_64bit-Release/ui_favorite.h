/********************************************************************************
** Form generated from reading UI file 'favorite.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAVORITE_H
#define UI_FAVORITE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Favorite
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_back;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Favorite)
    {
        if (Favorite->objectName().isEmpty())
            Favorite->setObjectName(QString::fromUtf8("Favorite"));
        Favorite->resize(648, 520);
        Favorite->setStyleSheet(QString::fromUtf8("#Favorite{\n"
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
"font-size:16px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(Favorite);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(Favorite);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.8);\n"
"border-radius:15px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_back = new QToolButton(frame);
        toolButton_back->setObjectName(QString::fromUtf8("toolButton_back"));
        toolButton_back->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/backicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_back->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton_back);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(frame);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        horizontalLayout->addWidget(frame);


        retranslateUi(Favorite);

        QMetaObject::connectSlotsByName(Favorite);
    } // setupUi

    void retranslateUi(QWidget *Favorite)
    {
        Favorite->setWindowTitle(QCoreApplication::translate("Favorite", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
        toolButton_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Favorite: public Ui_Favorite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAVORITE_H
