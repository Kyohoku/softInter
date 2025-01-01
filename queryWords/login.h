#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include"register.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();
    Ui::Login *ui;
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);
    void setUsername(QString name);
    void setPwd(QString psw);

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

private:

    Register *reg; //注册
};

#endif // LOGIN_H
