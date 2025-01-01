#include "userinfo.h"
#include "ui_userinfo.h"
#include <QStyleOption>
#include <QPainter>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>
#include "widget.h"
#include "favorite.h"
#include "sqliteOp.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);

    ui->lineEdit_study_num->setValidator(new QIntValidator(1,9999,this));//编辑只接受从1到9999的整数
    ui->lineEdit_review_num->setValidator(new QIntValidator(1,9999,this));//编辑只接受从1到9999的整数
}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::init(const QString& username,const QString& selLevel)
{
    m_username = username;
    m_selLevel = selLevel;

    ui->label_username->setText(username);
    //根据用户名查询用户基本信息
    int32_t wordNum = 1;
    int32_t reviewNum = 1;
    SqliteOp::getDataBase()->queryUserNum(username,wordNum,reviewNum);

    QString strWordNum = QString::number(wordNum);
    QString strReviewNum = QString::number(reviewNum);
    ui->lineEdit_study_num->setText(strWordNum);
    ui->lineEdit_review_num->setText(strReviewNum);

    //查询当前单词本总的词数量
    SqliteOp::getDataBase()->queryWordCount(m_selLevel,m_selLevelTotalCount);
    //查询当前单词本总的学习词数量
    int32_t  totalReciteNum = 0;
    SqliteOp::getDataBase()->queryTotalReciteNum(m_username,m_selLevel,totalReciteNum);

    //设置进度条
    QString strTotalProcess = "%1/%2";
    strTotalProcess = strTotalProcess.arg(totalReciteNum).arg(m_selLevelTotalCount);
    ui->label_total_process->setText(strTotalProcess);
    ui->progressBar_total->setMaximum(m_selLevelTotalCount);
    ui->progressBar_total->setValue(totalReciteNum);

    //查询当前单词本当天的学习数量
    int32_t  todayReciteNum = 0;
    SqliteOp::getDataBase()->queryTodayReciteNum(m_username,m_selLevel,todayReciteNum);

    //设置进度条
    QString strTodayProcess = "%1/%2";
    strTodayProcess = strTodayProcess.arg(todayReciteNum).arg(wordNum);
    ui->label_today_process->setText(strTodayProcess);
    ui->progressBar_today->setMaximum(wordNum);
    ui->progressBar_today->setValue(todayReciteNum);
    if(todayReciteNum>wordNum)
    {
       ui->progressBar_today->setValue(wordNum);
    }

    ChartView *chartView;
    createLineChart();
    chartView = new ChartView(m_chart);
    ui->gridLayout_chart->addWidget(chartView, 0, 0);
}

void UserInfo::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void UserInfo::closeEvent(QCloseEvent *event)
{
    assert(nullptr != event);
    //修改设置的数据
    QString strWordNum = ui->lineEdit_study_num->text();
    if(strWordNum.toInt() > m_selLevelTotalCount)
    {
        QMessageBox::warning(this, tr("提示"),tr("每日学习数量不能大于总数量!"));
        return;
    }
    QString strReviewNum = ui->lineEdit_review_num->text();
    QString username = ui->label_username->text();
    SqliteOp::getDataBase()->updateUserNum(username,strWordNum.toInt(),strReviewNum.toInt());
}


void UserInfo::createLineChart()
{
     m_chart = new Chart();
     m_chart->setTitle("用户每日学习单词数量曲线(近30天)");
     m_chart->createDefaultAxes();

     QDateTimeAxis *axisX = new QDateTimeAxis;
     axisX->setFormat("yyyy-MM-dd");
     axisX->setTitleText("时间");
     QValueAxis *axisY = new QValueAxis();
     axisY->setTitleText("个数");
     axisY->setRange(0, 10);

     m_chart->addAxis(axisX, Qt::AlignBottom);
     m_chart->addAxis(axisY, Qt::AlignLeft);

     m_lineSeries = new QLineSeries(m_chart);
     m_lineSeries->setName("Series");

     connect(m_lineSeries, &QLineSeries::pointAdded, [=](int index){
            qreal y = m_lineSeries->at(index).y();

            if(y< yMin || y > yMax){
                if(y < yMin)
                    yMin=y;
                if(y> yMax)
                    yMax = y;
                axisY->setRange(yMin, yMax+10);
            }

        });

     //设置曲线数据
     std::vector<DayCountInfo> dayCountInfos;
     SqliteOp::getDataBase()->queryGroupReciteNum(m_username,m_selLevel,dayCountInfos);

     for(auto& info:dayCountInfos)
     {
         QDateTime lastStudyTime = QDateTime::fromString(info.lastStudyTime.left(10), "yyyy-MM-dd");

         QPointF value(lastStudyTime.toMSecsSinceEpoch(),info.count);
         m_lineSeries->append(value);
     }

     axisX->setTickCount(dayCountInfos.size());

     m_chart->addSeries(m_lineSeries);
     m_lineSeries->attachAxis(axisX);
     m_lineSeries->attachAxis(axisY);



}

void UserInfo::on_toolButton_back_clicked()
{
    //修改设置的数据
    QString strWordNum = ui->lineEdit_study_num->text();
    if(strWordNum.toInt() > m_selLevelTotalCount)
    {
        QMessageBox::warning(this, tr("提示"),tr("每日学习数量不能大于总数量!"));
        return;
    }
    QString strReviewNum = ui->lineEdit_review_num->text();
    QString username = ui->label_username->text();
    SqliteOp::getDataBase()->updateUserNum(username,strWordNum.toInt(),strReviewNum.toInt());

    this->close();
    Widget* w = new Widget;
    w->init(username);
    w->show();
}

void UserInfo::on_toolButton_clicked()
{
    this->close();
    Favorite* f = new Favorite;
    f->init(m_username,m_selLevel);
    f->show();
}
