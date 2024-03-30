#ifndef CLASSROOM_BOOK_H
#define CLASSROOM_BOOK_H

#include <QWidget>
#include<QMessageBox>
#include<QString>
#include<QDateTime>
#include<QDebug>
#include<QTimer>
#include<QDate>
#include<QTime>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlDatabase>

namespace Ui {
class classroom_book;
}

class classroom_book : public QWidget
{
    Q_OBJECT

public:
    explicit classroom_book(QWidget *parent = nullptr);
    void result_yes();
    void connectsql();
    QString sex="女";
    QString washroom_num="A";
    QString id;
    bool isexist;
    ~classroom_book();

signals:
   void send_user_back();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

public slots:
    void design_isbook();

private:
    Ui::classroom_book *ui;
    QDateTime begin_time;
    QDateTime end_time;
    QDateTime current_time;
    QTimer *timer1;
    bool isbook1=true;
    bool isbook2=true;
    bool isbook3=true;
    bool isbook4=true;
    bool isbook5=true;
    bool isbook6=true;
    bool isbook7=true;
    bool isbook8=true;
    int num;
    QSqlDatabase db;
};

#endif // CLASSROOM_BOOK_H
