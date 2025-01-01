#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCompleter>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *);

    void init(const QString& username);

    void setUsername(const QString& username);

private slots:
    void on_toolButton_cet4_clicked();

    void on_toolButton_cet6_clicked();

    void on_pushButton_query_clicked();

    void on_pushButton_study_clicked();

    void on_pushButton_review_clicked();

    void on_toolButton_user_clicked();

    void on_toolButton_sent_clicked();

    void on_lineEdit_word_textEdited(const QString &arg1);

    void onCompleterActivated(const QString& content);
    void onCompleterHighlighted(const QString& content);

    void on_lineEdit_word_editingFinished();

    void on_lineEdit_word_textChanged(const QString &arg1);

    void on_lineEdit_word_returnPressed();

private:
    Ui::Widget *ui;
    QCompleter *completer;
    QStringListModel* model;
    QString m_username;
    QString m_selLevel = "4";
};
#endif // WIDGET_H
