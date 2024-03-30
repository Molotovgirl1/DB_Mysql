#ifndef ADMIN_MAINWINDOW_H
#define ADMIN_MAINWINDOW_H

#include <QMainWindow>
#include<admin_login.h>
#include<my_public.h>
#include<public_notice.h>
#include<reply_feedback.h>

namespace Ui {
class admin_MainWindow;
}

class admin_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_MainWindow(QWidget *parent = nullptr);
      void connectsql();
      void init_page();
    ~admin_MainWindow();

private slots:
      void on_pushButton_5_clicked();

      void on_pushButton_6_clicked();

      void on_pushButton_7_clicked();

      void on_pushButton_8_clicked();

private:
    Ui::admin_MainWindow *ui;
    admin_login m_login;
    QString id;
    QSqlDatabase db;
    my_public mypublic;
    public_notice public_not;
    reply_feedback reply_feed;

};

#endif // ADMIN_MAINWINDOW_H
