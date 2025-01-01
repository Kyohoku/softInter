#include "review.h"
#include "ui_review.h"
#include <QStyleOption>
#include <QPainter>
#include "widget.h"
#include "voiceop.h"
#include "study.h"

Review::Review(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Review)
{
    ui->setupUi(this);
}

Review::~Review()
{
    delete ui;
}

void Review::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Review::init(const QString& username)
{
    m_username = username;
    //查询用户设置的复习数量
    int32_t wordNum = 1;
    int32_t reviewNum = 1;
    SqliteOp::getDataBase()->queryUserNum(m_username,wordNum,reviewNum);
    m_reviewNum = reviewNum;

    //查询单词本
    SqliteOp::getDataBase()->queryuserLevel(m_username,m_selLevel);

    //查询背诵表里面的当天的复习过的单词量数据
    int32_t todayNum = 0;
    m_wordIndex = todayNum;

    getNewGroupWords();
    getNextWord();
}

void Review::getNewGroupWords()
{
    //查询用户已经学习的单词 取去熟练度不为100的reviewNum个单词，按熟练度排序，越低的越靠前复习
    //若不够m_reviewNum个，则设置一个内部上限m_reviewLimit，达到提示用户没有可以复习的了
    m_wordIds.clear();
    SqliteOp::getDataBase()->queryReciteWords(m_username,m_selLevel,m_reviewNum,m_wordIds);
    m_reviewLimit = m_wordIds.size();
}

void Review::getNextWord()
{
    QString strGroup = "本组复习 %1/%2";
    strGroup = strGroup.arg(m_wordIndex).arg(m_reviewNum);
    ui->label_group->setText(strGroup);

    ui->label_word_detail->setVisible(false);
    ui->pushButton_next->setVisible(false);

    if(m_reviewLimit < m_reviewNum)
    {//当前组不够了
        if(m_wordIndex == m_reviewLimit)
        {
            messageBoxShow2();
            return;
        }
    }
    else
    {
        if(m_wordIndex == m_reviewNum)
        {
            messageBoxShow();
            return;
        }
    }

    m_wordId = m_wordIds[m_wordIndex];

    //根据id查询wordinfo信息
    SqliteOp::getDataBase()->queryStudyWordById(m_wordId,m_wordInfo);

    //显示单词 音标
    ui->label_word->setText(m_wordInfo.english);
    ui->toolButton_sent->setText(m_wordInfo.sent);
}

void Review::messageBoxShow()
{
    QMessageBox msgbox(this);
    msgbox.setWindowTitle("恭喜当天任务已完成");
    msgbox.setText("当前组已复习完成");
    msgbox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgbox.button(QMessageBox::Yes)->setText("继续当前组");
    msgbox.button(QMessageBox::No)->setText("复习下一组");
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

void Review::messageBoxShow2()
{
    QMessageBox msgbox(this);
    msgbox.setWindowTitle("恭喜当天任务已完成");
    msgbox.setText("已经没有可以复习的了");
    msgbox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgbox.button(QMessageBox::Yes)->setText("继续当前组");
    msgbox.button(QMessageBox::No)->setText("去学习");
    int res = msgbox.exec();
    if (res == QMessageBox::Yes)
    {
        m_wordIndex = 0;
        getNextWord();
        qWarning()<<"-----Yes------";
    }
    else if(res == QMessageBox::No)
    {
        this->close();
        Study *s = new Study;
        s->init(m_username);
        s->show();
        qWarning()<<"-----No------";
    }
}

void Review::on_toolButton_back_clicked()
{
    this->close();
    Widget* w = new Widget;
    w->init(m_username);
    w->show();
}

void Review::on_toolButton_known_clicked()
{
    //更新熟练度
    SqliteOp::getDataBase()->updateReciteWordById(m_username,m_wordId);

    on_pushButton_next_clicked();
}

void Review::on_toolButton_unknown_clicked()
{
    ui->label_word_detail->setVisible(true);
    ui->label_word_detail->setText(m_wordInfo.chinese);
    ui->pushButton_next->setVisible(true);
}

void Review::on_toolButton_sent_clicked()
{
    const QString& words = ui->label_word->text();
    VoiceOp::getInstance()->sayWords(words);
}

void Review::on_pushButton_next_clicked()
{
    m_wordIndex++;
    getNextWord();
}
