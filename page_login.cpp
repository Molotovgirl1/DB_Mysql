#include "page_login.h"
#include "ui_page_login.h"

page_login::page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_login)
{
    ui->setupUi(this);
    connectsql();//登录界面进行数据库连接
}

page_login::~page_login()
{
    delete ui;
}
//连接数据库
void page_login::connectsql()
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

//按动登录按钮时的反应
void page_login::on_button_login_clicked()
{
    //数据库中查找学号和密码
    QSqlQuery query(db);
    query.exec(QString("select * from student where id='%1' and password='%2'").arg(ui->line_id_input->text()).arg(ui->line_pwd_input->text()));  //建立查询
     if(query.next())
       {
        id=query.value(0).toString();
        send_login_success();
       }
    else {
        QMessageBox::information(this,"infor", "登录失败，学号或密码错误！");
    }
}

//按动退出按钮时的反应
void page_login::on_button_logout_clicked()
{
    //退出
    exit(0);
}
