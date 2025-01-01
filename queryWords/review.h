#ifndef REVIEW_H
#define REVIEW_H

#include <QWidget>
#include "sqliteOp.h"

namespace Ui {
class Review;
}

class Review : public QWidget
{
    Q_OBJECT

public:
    explicit Review(QWidget *parent = nullptr);
    ~Review();

    void paintEvent(QPaintEvent *);

    void init(const QString& username);

    void getNewGroupWords(); //获取新的一组单词

    void getNextWord();

    void messageBoxShow();

    void messageBoxShow2();

private slots:
    void on_toolButton_back_clicked();

    void on_toolButton_known_clicked();

    void on_toolButton_unknown_clicked();

    void on_toolButton_sent_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::Review *ui;
    QString m_username;
    int32_t m_reviewNum = 0;
    int32_t m_reviewLimit = 0;
    QString m_selLevel = "4"; //选择的单词本
    int32_t m_wordIndex = 0; //当前单词索引
    std::vector<int32_t> m_wordIds; //当前学习的单词组
    int32_t m_wordId;  //当前的单词id信息
    WordInfo m_wordInfo; //当前的单词信息
};

#endif // REVIEW_H
