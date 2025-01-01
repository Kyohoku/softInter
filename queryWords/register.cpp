#include "register.h"
#include "ui_register.h"
#include <QStyleOption>
#include <QPainter>
#include "login.h"
#include "sqliteOp.h"
#include <QMessageBox>
#include <QKeyEvent>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->installEventFilter(this);
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
    if(username.isEmpty()){
        QMessageBox::warning(this, tr("提示"),tr("用户名不能为空!"));
        return;
    }
    if(username.count()>10)
    {
        QMessageBox::warning(this, tr("提示"),tr("用户名过长!"));
        return;
    }

    qDebug() << username.count();

    QString pwd1 = ui->lineEdit_pwd->text();
    QString pwd2 = ui->lineEdit_pwd_2->text();

    if(pwd1.count() == 0 )
    {
         QMessageBox::warning(this, tr("提示"),tr("密码不能为空!"));
         ui->lineEdit_pwd->setFocus();
         return;
    }

    if(pwd1 != pwd2)
    {
        QMessageBox::warning(this, tr("提示"),tr("两次输入的密码不一致!"));
        ui->lineEdit_pwd_2->setFocus();
        return;
    }

    if(SqliteOp::getDataBase()->addRegiserUser(username,pwd1))
    {
        QMessageBox::information(this, tr("提示"),tr("注册成功"));
        this->close();
        Login* login =new Login;
        login->setUsername(username);
        login->setPwd(pwd1);
        login->show();

    }
    else
    {
        QMessageBox::information(this, tr("提示"),tr("注册失败,用户已存在!"));
        ui->lineEdit_username->setText(NULL);
        ui->lineEdit_username->setFocus();
    }
}

void Register::on_pushButton_back_clicked()
{
    this->close();
    Login* login = new Login;
    login->show();
}

bool Register::eventFilter(QObject *obj, QEvent *event)     //设置快捷键
{ if (event->type() == QEvent::KeyPress) {
     QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
     if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
{       // 触发按钮槽函数
        emit on_pushButton_register_clicked();
        return true;
     }
   }
 return QWidget::eventFilter(obj, event);
}
