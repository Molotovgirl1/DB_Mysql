#include "public_notice.h"
#include "ui_public_notice.h"

public_notice::public_notice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::public_notice)
{
    ui->setupUi(this);
}

public_notice::~public_notice()
{
    delete ui;
}

void public_notice::on_pushButton_clicked()
{
    send_admin_back();
}

//连接数据库
void public_notice::connectsql()
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
void public_notice::on_pushButton_2_clicked()
{
    public_yes();
}
//创建通知
void public_notice::public_yes()
{
    connectsql();
    if((ui->lineEdit->text()!=NULL)&&ui->lineEdit_2->text()!=NULL)
    {
        QSqlQuery query(db);
        query.exec(QString("insert into notice(notice_type,notice_text,id,public_time) values('%1','%2','%3','%4')").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(id).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
        QMessageBox::information(this,"infor", "发布成功！");
    }
    else {
        QMessageBox::information(this,"infor", "发布失败！");
    }
}
