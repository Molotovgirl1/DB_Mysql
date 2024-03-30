#include "admin_mainwindow.h"
#include "ui_admin_mainwindow.h"

admin_MainWindow::admin_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_MainWindow)
{
    ui->setupUi(this);
    m_login.show();
    connectsql();

    //成功登录界面后转到主界面
    auto mainwindow_show=[&]()
    {
        this->id=m_login.id;//把登录界面的学号传到界面中
        mypublic.id=m_login.id;
        public_not.id=m_login.id;
        this->show();
        m_login.hide();
        init_page();
    };
     connect(&m_login,&admin_login::send_login_success,this,mainwindow_show);

     //从我的发布回来
     auto mainwindow_show1=[&]()
     {
         this->show();
         mypublic.hide();
      };
      connect(&mypublic,&my_public::send_admin_back,this,mainwindow_show1);

      //从发布通知回来
      auto mainwindow_show2=[&]()
      {
          this->show();
          public_not.hide();
       };
       connect(&public_not,&public_notice::send_admin_back,this,mainwindow_show2);

       //从回复反馈回来
       auto mainwindow_show3=[&]()
       {
           this->show();
           reply_feed.hide();
        };
        connect(&reply_feed,&reply_feedback::send_admin_back,this,mainwindow_show3);

}

admin_MainWindow::~admin_MainWindow()
{
    delete ui;
}
//连接数据库
void admin_MainWindow::connectsql()
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
void admin_MainWindow::init_page()
{
    QSqlQuery query(db);
    query.exec(QString("select * from admin where id='%1'").arg(id));
    if(query.next())
    {
        ui->label1->setText(query.value(2).toString());
        ui->label2->setText(query.value(0).toString());
        ui->label6->setText(query.value(3).toString());
        ui->label_2->setText(query.value(4).toString());
    }
}
//我的发布槽函数
void admin_MainWindow::on_pushButton_5_clicked()
{
    this->hide();
    mypublic.show();
    mypublic.design_public_record();
}
//发布的槽函数
void admin_MainWindow::on_pushButton_6_clicked()
{
    this->hide();
    public_not.show();
}

void admin_MainWindow::on_pushButton_7_clicked()
{
    this->hide();
    m_login.show();
}
//回复反馈
void admin_MainWindow::on_pushButton_8_clicked()
{
    this->hide();
    reply_feed.show_reply();
    reply_feed.show();

}
