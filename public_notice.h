#ifndef PUBLIC_NOTICE_H
#define PUBLIC_NOTICE_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include<QDateTime>

namespace Ui {
class public_notice;
}

class public_notice : public QWidget
{
    Q_OBJECT

public:
    explicit public_notice(QWidget *parent = nullptr);
    void public_yes();
    void connectsql();
    QString id;
    ~public_notice();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void send_admin_back();
private:
    Ui::public_notice *ui;
    QSqlDatabase db;
};

#endif // PUBLIC_NOTICE_H
