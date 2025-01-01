#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
