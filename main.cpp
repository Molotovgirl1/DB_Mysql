#include "mainwindow.h"
#include "admin_mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMessageBox choice(QMessageBox::Question,QString("身份"),QString("请选择要登录的身份："),QMessageBox::Yes| QMessageBox::No);
       choice.setButtonText(QMessageBox::Yes,QString("学生"));
        choice.setButtonText(QMessageBox::No,QString("管理员"));
       int res = choice.exec();
       if(res == QMessageBox::Yes)
       {
           MainWindow s;
           s.design_mybook();
           return a.exec();
       }
       else if(res==QMessageBox::No)
       {
           admin_MainWindow w;
           return a.exec();
       }
}

