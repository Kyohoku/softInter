#include "register.h"
#include "ui_register.h"
#include <QStyleOption>
#include <QPainter>
#include "login.h"
#include "sqliteOp.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

}

Register::~Register()
{
    delete ui;
}

void Register::paintEvent(QPaintEvent *e)
{
    assert(nullptr != e);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Register::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    if(username.count()>10)
    {
        QMessageBox::warning(this, tr("提示"),tr("用户名过长!"));
        return;
    }

    qDebug() << username.count();

    QString pwd1 = ui->lineEdit_pwd->text();
    QString pwd2 = ui->lineEdit_pwd->text();

    if(pwd1.count() == 0 || pwd2.count() == 0)
    {
         QMessageBox::warning(this, tr("提示"),tr("密码不能为空!"));
         return;
    }

    if(pwd1 != pwd2)
    {
        QMessageBox::warning(this, tr("提示"),tr("两次输入的密码不一致!"));
        return;
    }

    if(SqliteOp::getDataBase()->addRegiserUser(username,pwd1))
    {
        QMessageBox::information(this, tr("提示"),tr("注册成功"));
    }
    else
    {
        QMessageBox::information(this, tr("提示"),tr("注册失败!"));
    }
}

void Register::on_pushButton_back_clicked()
{
    this->close();
    Login* login = new Login;
    login->show();
}
