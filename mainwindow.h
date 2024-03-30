#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<page_login.h>
#include<QStackedWidget>
#include<user_concall.h>
#include<design_user_rec.h>
#include<user_change_passwd.h>
#include<classroom_book.h>
#include<QVariant>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void switchpage();
    void initpage();
    void connectsql();
    void design_welcome();
    void design_user();
    void init_book();
    bool isexist;
    void release_washroom();
    void result_yes();
    void show_not();
    void show_notice();
    void show_feed();
    void show_feedback();
    ~MainWindow();

public slots:
    void design_mybook();

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

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;
    page_login m_Login;
    user_concall m_user_call;
    design_user_rec m_user_rec;
    classroom_book m_book;
    QSqlDatabase db;
    QString id;
    QString name;
    QString major;
    QString sex;
    user_change_passwd m_user_passwd;
    QDateTime current_time;
    QString washroom_num;
    int num;
    QDateTime begin_time;
    QDateTime end_time;
    QTimer *timer;
    int recnum;
    int recnum1;
};

#endif // MAINWINDOW_H
