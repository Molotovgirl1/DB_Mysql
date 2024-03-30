#ifndef DESIGN_USER_REC_H
#define DESIGN_USER_REC_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include<QTime>


namespace Ui {
class design_user_rec;
}

class design_user_rec : public QWidget
{
    Q_OBJECT

public:
    explicit design_user_rec(QWidget *parent = nullptr);
    void design_user_record();
    void show_rec();
    void connectsql();
    ~design_user_rec();
      QString id;

private slots:
    void on_pushButton_clicked();

signals:
    void send_user_back();

private:
    Ui::design_user_rec *ui;
    QSqlDatabase db;
    int recnum;
};

#endif // DESIGN_USER_REC_H
