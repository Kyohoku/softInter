#include "login.h"
#include "ui_login.h"
#include <QStyleOption>
#include <QPainter>
#include "widget.h"
#include "sqliteOp.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    reg=new Register;
}

Login::~Login()
{
    delete ui;
}

void Login::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    //先判断用户是否存在
    if(!SqliteOp::getDataBase()->queryusername(username))
    {
        QMessageBox::warning(this, tr("提示"),tr("用户名不存在!"));
        return;
    }

    QString pwd = ui->lineEdit_pwd->text();
    //再判断用户密码是否正确
    if(!SqliteOp::getDataBase()->querypassword(username,pwd))
    {
        QMessageBox::warning(this, tr("提示"),tr("用户密码不正确!"));
        return;
    }

    this->close();
    Widget* w = new Widget;
    w->init(username);
    w->show();
}

void Login::on_pushButton_register_clicked()
{
    this->close();
    reg->show();
}
