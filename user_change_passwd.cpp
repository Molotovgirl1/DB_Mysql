#include "user_change_passwd.h"
#include "ui_user_change_passwd.h"

user_change_passwd::user_change_passwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_change_passwd)
{
    ui->setupUi(this);
}

user_change_passwd::~user_change_passwd()
{
    delete ui;
}
//修改密码界面按动返回按钮的槽
void user_change_passwd::on_pushButton_clicked()
{
    send_user_back();
}
//连接数据库
void user_change_passwd::connectsql()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
    bool ok=db.open();
    if(ok)
    {
        qDebug()<<"数据库连接成功！";
    }
    else
    {
       QMessageBox::information(this,"infor", "link failed");
       qDebug()<<"error open database because"<<db.lastError().text();
    }
}
//确认修改密码按动按钮的槽
void user_change_passwd::on_pushButton_2_clicked()
{
    connectsql();
    QSqlQuery query(db);
    query.exec(QString("select * from student where id='%1' and password='%2'").arg(id).arg(ui->lineEdit->text()));
     if(query.next())
       {
             if((ui->lineEdit_2->text()==ui->lineEdit_3->text())&&(ui->lineEdit_2->text()!=NULL))
             {
                 password=ui->lineEdit_2->text();
                 //在数据库中修改密码
                 QSqlQuery query1(db);
                 query1.exec(QString("update student set password='%1' where id='%2'").arg(password).arg(id));
                 QMessageBox::information(this,"infor", "密码修改成功！");
             }
             else {
                  QMessageBox::information(this,"infor", "密码修改失败，请确保新密码和确认密码输入相同并且非空。");
             }
           }
     else {
         QMessageBox::information(this,"infor", "密码修改失败，当前密码输入错误！。");
     }
}
