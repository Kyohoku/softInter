#include "favorite.h"
#include "ui_favorite.h"
#include <QStyleOption>
#include <QPainter>
#include "userinfo.h"
#include "sqliteOp.h"

Favorite::Favorite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Favorite)
{
    ui->setupUi(this);
}

Favorite::~Favorite()
{
    delete ui;
}

void Favorite::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Favorite::init(const QString& username,const QString& selLevel)
{
    m_username = username;
    m_selLevel = selLevel;

    std::vector<WordInfo> words;
    SqliteOp::getDataBase()->queryFavoriteWords(username,words);

    ui->tableWidget->setColumnCount(3);

    //表头标题用QStringList来表示
    QStringList headerText;
    headerText<<"单词"<<"音标"<<"释义";
    ui->tableWidget->setHorizontalHeaderLabels(headerText);

    //设置列宽
    //ui->tableWidget->setColumnWidth(0,100);
    //ui->tableWidget->setColumnWidth(1,100);
    //ui->tableWidget->setColumnWidth(2,300);

    //设置列内容自适应宽度
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Interactive);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Interactive);

    //设置整行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //设置不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(int32_t i = 0; i < words.size(); ++i)
    {
       WordInfo word = words[i];
       ui->tableWidget->insertRow(i);
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(word.english));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(word.sent));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(word.chinese));
    }

}

void Favorite::on_toolButton_back_clicked()
{
    this->close();
    UserInfo* u = new UserInfo;
    u->init(m_username,m_selLevel);
    u->show();
}

