#include "widget.h"
#include "ui_widget.h"
#include <QStyleOption>
#include <QPainter>
#include "userinfo.h"
#include "study.h"
#include "review.h"
#include "voiceop.h"
#include <QDebug>
#include "sqliteOp.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->toolButton_cet4->setChecked(true);
    ui->label_meaning->setVisible(false);
    ui->toolButton_sent->setVisible(false);

    completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setMaxVisibleItems(10);
    ui->lineEdit_word->setCompleter(completer);
    model = new QStringListModel(this);

    connect(completer,SIGNAL(activated ( const QString &)), this, SLOT(onCompleterActivated(const QString&)));
    connect(completer,SIGNAL(highlighted ( const QString &)), this, SLOT(onCompleterHighlighted(const QString&)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Widget::init(const QString& username)
{
    setUsername(username);

    //查询用户设置的单词本，设置单词本状态
    SqliteOp::getDataBase()->queryuserLevel(username,m_selLevel);
    if(m_selLevel == "4")
    {
        ui->toolButton_cet4->setChecked(true);
        ui->toolButton_cet6->setChecked(false);
    }
    else if(m_selLevel == "6")
    {
        ui->toolButton_cet4->setChecked(false);
        ui->toolButton_cet6->setChecked(true);
    }
}

void Widget::setUsername(const QString& username)
{
    ui->label_username->setText(username);
    m_username = username;
}

void Widget::on_toolButton_cet4_clicked()
{
    ui->toolButton_cet4->setChecked(true);
    ui->toolButton_cet6->setChecked(false);
    m_selLevel = "4";
    //更新选择的单词本
    SqliteOp::getDataBase()->updateuserLevel(m_username,m_selLevel);
}

void Widget::on_toolButton_cet6_clicked()
{
    ui->toolButton_cet4->setChecked(false);
    ui->toolButton_cet6->setChecked(true);
    //更新选择的单词本
    m_selLevel = "6";
    SqliteOp::getDataBase()->updateuserLevel(m_username,m_selLevel);
}

void Widget::on_pushButton_query_clicked()
{
    QString word = ui->lineEdit_word->text();
    QString wordMeaning;
    QString wordSent;
    if(SqliteOp::getDataBase()->queryWord(word,wordMeaning,wordSent))
    {
        ui->label_meaning->setVisible(true);
        ui->toolButton_sent->setVisible(true);
        ui->label_meaning->setText(wordMeaning);
        ui->toolButton_sent->setText(wordSent);
    }
    else
    {
        ui->label_meaning->setVisible(false);
        ui->toolButton_sent->setVisible(false);
    }
}

void Widget::on_pushButton_study_clicked()
{
    this->close();
    Study *s = new Study;
    s->init(m_username);
    s->show();
}

void Widget::on_pushButton_review_clicked()
{
    //根据遗忘公式更新当前用户的熟练度，更新时间粒度为分钟
    SqliteOp::getDataBase()->updateReciteWord(m_username,m_selLevel);

    //查询用户学习单词熟练度不为100的数量，若为0提醒用户去学习
    int32_t num = 0;
    SqliteOp::getDataBase()->queryReciteNum(m_username,m_selLevel,num);
    if(num == 0)
    {
       QMessageBox::warning(this, tr("提示"),tr("没有可以复习的单词，先去学习吧"));
       return;
    }

    this->close();
    Review *r = new Review;
    r->init(m_username);
    r->show();
}

void Widget::on_toolButton_user_clicked()
{
    this->close();
    UserInfo *u = new UserInfo;
    u->init(m_username,m_selLevel);
    u->show();
}

void Widget::on_toolButton_sent_clicked()
{
    const QString& words = ui->lineEdit_word->text();
    VoiceOp::getInstance()->sayWords(words);
}

void Widget::on_lineEdit_word_textEdited(const QString &arg1)
{
    //根据内容查询模糊sqlite
    QStringList words;
    SqliteOp::getDataBase()->queryWords(arg1,words);

    model->setStringList(words);
    completer->setModel(model);

    //qDebug()<<"textEdited:"<<arg1;
}

void Widget::onCompleterActivated(const QString& content)
{
    //选中之后查询触发显示
    QStringList tempStringList = content.split(" ");
    if(tempStringList.count() < 2)
    {
       qDebug()<<"onCompleterActivated error:";
       return;
    }

    QString word = tempStringList[0];
    QString wordMeaning;
    QString wordSent;
    if(SqliteOp::getDataBase()->queryWord(word,wordMeaning,wordSent))
    {
        ui->label_meaning->setVisible(true);
        ui->toolButton_sent->setVisible(true);
        ui->label_meaning->setText(wordMeaning);
        ui->toolButton_sent->setText(wordSent);
    }
    else
    {
        ui->label_meaning->setVisible(false);
        ui->toolButton_sent->setVisible(false);
    }

    qDebug()<<"Activated:"<<content;
}

void Widget::onCompleterHighlighted(const QString& content)
{

    //qDebug()<<"Highlighted:"<<content;
}

void Widget::on_lineEdit_word_editingFinished()
{
    //on_pushButton_query_clicked();
}

void Widget::on_lineEdit_word_textChanged(const QString &arg1)
{
    if(arg1.count() == 0)
    {
        ui->label_meaning->setVisible(false);
        ui->toolButton_sent->setVisible(false);
    }

    QStringList tempStringList = arg1.split(" ");
    if(tempStringList.count() >= 2)
    {//textChanged 最后触发 将搜索框只设置为单词
        ui->lineEdit_word->setText(tempStringList[0]);
    }

}

void Widget::on_lineEdit_word_returnPressed()
{
    on_pushButton_query_clicked();
    qDebug()<<"returnPressed:";
}
