#ifndef MY_PUBLIC_H
#define MY_PUBLIC_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include<QDateTime>
#include<QPushButton>

namespace Ui {
class my_public;
}

class my_public : public QWidget
{
    Q_OBJECT

public:
    explicit my_public(QWidget *parent = nullptr);
    void show_public();
    void design_public_record();
    void connectsql();
    QString id;
    ~my_public();

private slots:
    void on_pushButton_clicked();
    void delete_not();
signals:
    void send_admin_back();

private:
    Ui::my_public *ui;
    QSqlDatabase db;
    int recnum;
};

#endif // MY_PUBLIC_H
