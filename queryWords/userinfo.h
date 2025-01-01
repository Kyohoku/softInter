#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include "chart.h"
#include "chartview.h"
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

    void init(const QString& username,const QString& selLevel);

    void paintEvent(QPaintEvent *);

    void closeEvent(QCloseEvent *event);

    void createLineChart();

private slots:
    void on_toolButton_back_clicked();

    void on_toolButton_clicked();

private:
    Ui::UserInfo *ui;

    Chart *m_chart;
    //QSplineSeries* m_lineSeries;
    QLineSeries* m_lineSeries;
    qreal yMax = 10;
    qreal yMin = 0;

    QString m_username;
    QString m_selLevel = "4"; //选择的单词本
    int32_t m_selLevelTotalCount = 0; //选择的单词本总数量

};

#endif // USERINFO_H
