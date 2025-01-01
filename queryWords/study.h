#ifndef STUDY_H
#define STUDY_H

#include <QWidget>
#include "sqliteOp.h"
namespace Ui {
class Study;
}

class Study : public QWidget
{
    Q_OBJECT

public:
    explicit Study(QWidget *parent = nullptr);
    ~Study();

    void init(const QString& username);

    void getNewGroupWords(); //获取新的一组单词

    void getNextWord();

    QString getWrongChinesesBegin(std::vector<QString>& wrongChineses);

    void paintEvent(QPaintEvent *);

    void messageBoxShow();

private slots:
    void on_toolButton_back_clicked();

    void on_toolButton_1_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_sent_clicked();

    void on_pushButton_next_clicked();

    void on_toolButton_favorite_clicked();

private:
    Ui::Study *ui;
    QString m_username;
    QString m_selLevel = "4"; //选择的单词本
    int32_t m_wordNum = 0;
    std::vector<WordInfo> m_words; //当前学习的单词组
    int32_t m_wordIndex = 0; //当前单词索引
    std::vector<int32_t> m_selIndexs = {0,1,2,3}; //待选择索引
    int32_t m_correctSelIndex = 0; //正确的选择索引
    WordInfo m_wordInfo;  //当前的单词信息
};

#endif // STUDY_H
