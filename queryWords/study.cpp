#include "study.h"
#include "ui_study.h"
#include <QStyleOption>
#include <QPainter>
#include "widget.h"
#include "voiceop.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>

Study::Study(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Study)
{
    ui->setupUi(this);
}

Study::~Study()
{
    delete ui;
}

void Study::init(const QString& username)
{
    m_username = username;
    //查询学习数量
    //根据用户名查询用户基本信息
    int32_t wordNum = 1;
    int32_t reviewNum = 1;
    SqliteOp::getDataBase()->queryUserNum(username,wordNum,reviewNum);
    m_wordNum = wordNum;

    //查询单词本
    SqliteOp::getDataBase()->queryuserLevel(m_username,m_selLevel);

    //查询背诵表里面的当天的学习单词量数据
    int32_t todayNum = 0;
    m_wordIndex = todayNum;
    getNewGroupWords();
    getNextWord();
}

QString Study::getWrongChinesesBegin(std::vector<QString>& wrongChineses)
{
    if(wrongChineses.size() == 0)
    {
        qDebug()<<"getWrongChinesesBegin error";
        return "";
    }

    auto it = wrongChineses.begin();
    QString str = *it;

    wrongChineses.erase(it);

    return str;
}

void Study::getNewGroupWords()
{
    //随机查询一定单词，且不在背诵表里面，不够再去背诵表里面查询熟练度比较低的
     m_words.clear();
     SqliteOp::getDataBase()->queryStudyWords(m_username,m_selLevel,m_wordNum,m_words);
     if(m_wordNum != (int32_t)m_words.size())
     {
         qDebug()<<"words error";
     }

}

void Study::getNextWord()
{
    QString strGroup = "本组学习 %1/%2";
    strGroup = strGroup.arg(m_wordIndex).arg(m_wordNum);
    ui->label_group->setText(strGroup);

    ui->pushButton_next->setVisible(false);
    ui->toolButton_1->setChecked(false);
    ui->toolButton_2->setChecked(false);
    ui->toolButton_3->setChecked(false);
    ui->toolButton_4->setChecked(false);

    m_wordInfo = m_words[m_wordIndex];

    //判断收藏表是否存在
    if(SqliteOp::getDataBase()->checkFavoriteWordExist(m_username,m_wordInfo.id))
    {
        ui->toolButton_favorite->setIcon(QIcon(":/res/favorite_pressed.png"));
    }
    else
    {
        ui->toolButton_favorite->setIcon(QIcon(":/res/favorite_normal.png"));
    }


    //随机查询三个不正确的答案
    std::vector<QString> wrongChineses;
    SqliteOp::getDataBase()->queryAbstructWords(m_selLevel,m_wordInfo.chinese, wrongChineses);
    qDebug()<<"wrongChinese nunm:"<<wrongChineses.size();

    //显示
    ui->label_word->setText(m_wordInfo.english);
    ui->toolButton_sent->setText(m_wordInfo.sent);

    //随机生成正确答案的索引
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    m_correctSelIndex = qrand()%4; //[0,3]
    qDebug()<<"correctSelIndex:"<<m_correctSelIndex;

    //选项显示
    QString wrongStyle = "QToolButton{     \nbackground: rgba(0,0,0,0.2);\n}\nQToolButton:checked{    /*选中后*/  \nbackground: rgb(255, 0, 0); \n}";
    QString correctStyle = "QToolButton{     \nbackground: rgba(0,0,0,0.2);\n}\nQToolButton:checked{    /*选中后*/  \nbackground: rgb(0, 0, 255); \n}";
    for(auto& selIndex : m_selIndexs)
    {
        switch (selIndex) {
        case 0:
            if(selIndex == m_correctSelIndex)
            {
                ui->toolButton_1->setStyleSheet(correctStyle);
                ui->toolButton_1->setText(m_wordInfo.chinese);
            }else
            {
                ui->toolButton_1->setStyleSheet(wrongStyle);
                QString str = getWrongChinesesBegin(wrongChineses);
                qDebug()<<"111"<<str;
                ui->toolButton_1->setText(str);
            }
            break;
        case 1:
            if(selIndex == m_correctSelIndex)
            {
                ui->toolButton_2->setStyleSheet(correctStyle);
                ui->toolButton_2->setText(m_wordInfo.chinese);
            }else
            {
                ui->toolButton_2->setStyleSheet(wrongStyle);
                QString str = getWrongChinesesBegin(wrongChineses);
                qDebug()<<"222"<<str;
                ui->toolButton_2->setText(str);
            }
            break;
        case 2:
            if(selIndex == m_correctSelIndex)
            {
                ui->toolButton_3->setStyleSheet(correctStyle);
                ui->toolButton_3->setText(m_wordInfo.chinese);
            }else
            {
                ui->toolButton_3->setStyleSheet(wrongStyle);
                QString str = getWrongChinesesBegin(wrongChineses);
                qDebug()<<"333"<<str;
                ui->toolButton_3->setText(str);
            }
            break;
        case 3:
            if(selIndex == m_correctSelIndex)
            {
                ui->toolButton_4->setStyleSheet(correctStyle);
                ui->toolButton_4->setText(m_wordInfo.chinese);
            }else
            {
                ui->toolButton_4->setStyleSheet(wrongStyle);
                QString str = getWrongChinesesBegin(wrongChineses);
                qDebug()<<"444"<<str;
                ui->toolButton_4->setText(str);
            }
            break;
        }
    }

}

void Study::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Study::on_toolButton_back_clicked()
{
    this->close();
    Widget* w = new Widget;
    w->init(m_username);
    w->show();
}

void Study::messageBoxShow()
{

    m_wordIndex++;
    QString strGroup = "本组学习 %1/%2";
    strGroup = strGroup.arg(m_wordIndex).arg(m_wordNum);
    ui->label_group->setText(strGroup);
    ui->pushButton_next->setVisible(false);

    //存储当前学习的单词到背诵表
    SqliteOp::getDataBase()->addReciteWord(m_username,m_wordInfo.id,m_selLevel);

    QMessageBox msgbox(this);
    msgbox.setWindowTitle("恭喜当天任务已完成");
    msgbox.setText("当前组已学习完成");
    msgbox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgbox.button(QMessageBox::Yes)->setText("继续当前组");
    msgbox.button(QMessageBox::No)->setText("学习下一组");
    int res = msgbox.exec();
    if (res == QMessageBox::Yes)
    {
        m_wordIndex = 0;
        getNextWord();
        qWarning()<<"-----Yes------";
    }
    else if(res == QMessageBox::No)
    {
        m_wordIndex = 0;
        getNewGroupWords();
        getNextWord();
        qWarning()<<"-----No------";
    }
}

void Study::on_toolButton_1_clicked()
{
    ui->pushButton_next->setVisible(true);
    ui->toolButton_1->setChecked(true);
    ui->toolButton_2->setChecked(false);
    ui->toolButton_3->setChecked(false);
    ui->toolButton_4->setChecked(false);

    if(m_correctSelIndex == 0)
    {
        ui->toolButton_1->setChecked(true);
    }
    if(m_correctSelIndex == 1)
    {
        ui->toolButton_2->setChecked(true);
    }
    if(m_correctSelIndex == 2)
    {
        ui->toolButton_3->setChecked(true);
    }
    if(m_correctSelIndex == 3)
    {
        ui->toolButton_4->setChecked(true);
    }

    //存储当前学习的单词到背诵表
    SqliteOp::getDataBase()->addReciteWord(m_username,m_wordInfo.id,m_selLevel);

    if(m_wordIndex == m_wordNum - 1)
    {
         messageBoxShow();
    }
}

void Study::on_toolButton_2_clicked()
{
    ui->pushButton_next->setVisible(true);
    ui->toolButton_1->setChecked(false);
    ui->toolButton_2->setChecked(true);
    ui->toolButton_3->setChecked(false);
    ui->toolButton_4->setChecked(false);

    if(m_correctSelIndex == 0)
    {
        ui->toolButton_1->setChecked(true);
    }
    if(m_correctSelIndex == 1)
    {
        ui->toolButton_2->setChecked(true);
    }
    if(m_correctSelIndex == 2)
    {
        ui->toolButton_3->setChecked(true);
    }
    if(m_correctSelIndex == 3)
    {
        ui->toolButton_4->setChecked(true);
    }

    //存储当前学习的单词到背诵表
    SqliteOp::getDataBase()->addReciteWord(m_username,m_wordInfo.id,m_selLevel);

    if(m_wordIndex == m_wordNum - 1)
    {
         messageBoxShow();
    }
}

void Study::on_toolButton_3_clicked()
{
    ui->pushButton_next->setVisible(true);
    ui->toolButton_1->setChecked(false);
    ui->toolButton_2->setChecked(false);
    ui->toolButton_3->setChecked(true);
    ui->toolButton_4->setChecked(false);

    if(m_correctSelIndex == 0)
    {
        ui->toolButton_1->setChecked(true);
    }
    if(m_correctSelIndex == 1)
    {
        ui->toolButton_2->setChecked(true);
    }
    if(m_correctSelIndex == 2)
    {
        ui->toolButton_3->setChecked(true);
    }
    if(m_correctSelIndex == 3)
    {
        ui->toolButton_4->setChecked(true);
    }

    //存储当前学习的单词到背诵表
    SqliteOp::getDataBase()->addReciteWord(m_username,m_wordInfo.id,m_selLevel);

    if(m_wordIndex == m_wordNum - 1)
    {
         messageBoxShow();
    }

}

void Study::on_toolButton_4_clicked()
{
    ui->pushButton_next->setVisible(true);
    ui->toolButton_1->setChecked(false);
    ui->toolButton_2->setChecked(false);
    ui->toolButton_3->setChecked(false);
    ui->toolButton_4->setChecked(true);
    if(m_correctSelIndex == 0)
    {
        ui->toolButton_1->setChecked(true);
    }
    if(m_correctSelIndex == 1)
    {
        ui->toolButton_2->setChecked(true);
    }
    if(m_correctSelIndex == 2)
    {
        ui->toolButton_3->setChecked(true);
    }
    if(m_correctSelIndex == 3)
    {
        ui->toolButton_4->setChecked(true);
    }

    //存储当前学习的单词到背诵表
    SqliteOp::getDataBase()->addReciteWord(m_username,m_wordInfo.id,m_selLevel);

    if(m_wordIndex == m_wordNum - 1)
    {
         messageBoxShow();
    }
}

void Study::on_toolButton_sent_clicked()
{
    const QString& words = ui->label_word->text();
    VoiceOp::getInstance()->sayWords(words);
}

void Study::on_pushButton_next_clicked()
{
    m_wordIndex++;
    getNextWord();
}

void Study::on_toolButton_favorite_clicked()
{
    //判断收藏表是否存在
    if(SqliteOp::getDataBase()->checkFavoriteWordExist(m_username,m_wordInfo.id))
    {//存在则删除
       SqliteOp::getDataBase()->deleteFavoriteWord(m_username,m_wordInfo.id);
       ui->toolButton_favorite->setIcon(QIcon(":/res/favorite_normal.png"));
    }
    else
    {//不存在插入
        SqliteOp::getDataBase()->addFavoriteWord(m_username,m_wordInfo.id);
        ui->toolButton_favorite->setIcon(QIcon(":/res/favorite_pressed.png"));
    }
}

