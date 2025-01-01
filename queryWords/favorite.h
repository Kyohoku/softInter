#ifndef FAVORITE_H
#define FAVORITE_H

#include <QWidget>

namespace Ui {
class Favorite;
}

class Favorite : public QWidget
{
    Q_OBJECT

public:
    explicit Favorite(QWidget *parent = nullptr);
    ~Favorite();

    void paintEvent(QPaintEvent *);

    void init(const QString& username,const QString& selLevel);

private slots:
    void on_toolButton_back_clicked();

private:
    Ui::Favorite *ui;

    QString m_username;
    QString m_selLevel = "4"; //选择的单词本
};

#endif // FAVORITE_H
