#ifndef USER_CHANGE_PASSWD_H
#define USER_CHANGE_PASSWD_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>

namespace Ui {
class user_change_passwd;
}

class user_change_passwd : public QWidget
{
    Q_OBJECT

public:
    explicit user_change_passwd(QWidget *parent = nullptr);
    void connectsql();
    QString id;
    ~user_change_passwd();

signals:
    void send_user_back();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::user_change_passwd *ui;
    QSqlDatabase db;
    QString password;
};

#endif // USER_CHANGE_PASSWD_H
