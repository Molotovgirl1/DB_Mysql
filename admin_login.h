#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>

namespace Ui {
class admin_login;
}

class admin_login : public QWidget
{
    Q_OBJECT

public:
    explicit admin_login(QWidget *parent = nullptr);
    void connectsql();
    QString id;
    ~admin_login();

private slots:
    void on_button_login_clicked();

    void on_button_logout_clicked();
signals:
    void send_login_success();

private:
    Ui::admin_login *ui;
    QSqlDatabase db;

};

#endif // ADMIN_LOGIN_H
