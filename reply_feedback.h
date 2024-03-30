#ifndef REPLY_FEEDBACK_H
#define REPLY_FEEDBACK_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include<QPushButton>
#include<QInputDialog>
#include<QVariant>

namespace Ui {
class reply_feedback;
}

class reply_feedback : public QWidget
{
    Q_OBJECT

public:
    explicit reply_feedback(QWidget *parent = nullptr);
    void show_rep();
    void show_reply();
    void connectsql();
    void isreply();
    ~reply_feedback();

private slots:
    void on_pushButton_clicked();
    void reply_yes();

signals:
    void send_admin_back();
private:
    Ui::reply_feedback *ui;
    QSqlDatabase db;
    int recnum;
};

#endif // REPLY_FEEDBACK_H
