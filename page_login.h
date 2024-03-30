#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>

namespace Ui {
class page_login;
}

class page_login : public QWidget
{
    Q_OBJECT

public:
    explicit page_login(QWidget *parent = nullptr);
    void connectsql();
     QString id;
    ~page_login();

private slots:
    void on_button_login_clicked();
    void on_button_logout_clicked();

signals:
    void send_login_success();

private:
    Ui::page_login *ui;
    QSqlDatabase db;
};

#endif // PAGE_LOGIN_H
