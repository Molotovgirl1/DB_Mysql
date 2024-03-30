#ifndef USER_CONCALL_H
#define USER_CONCALL_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include<QValidator>
#include<QRegExp>


namespace Ui {
class user_concall;
}

class user_concall : public QWidget
{
    Q_OBJECT

public:
    explicit user_concall(QWidget *parent = nullptr);
    ~user_concall();
    QString id;
    void design_user_connect();
     void connectsql();
     bool IsValidPhoneNumber(const QString & phoneNum);
     bool IsValidEmailNumber(const QString & emailNum);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

signals:
    void send_user_back();

private:
    Ui::user_concall *ui;
    QSqlDatabase db;
    QString callnum;
    QString email;
};

#endif // USER_CONCALL_H
