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

    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::Login *ui;
    Register *reg; //注册
};

#endif // LOGIN_H
