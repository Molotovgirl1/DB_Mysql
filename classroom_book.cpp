#include "classroom_book.h"
#include "ui_classroom_book.h"

classroom_book::classroom_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classroom_book)
{
    ui->setupUi(this);

    timer1= new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(design_isbook()));
    timer1->start(100);
    connectsql();
}

classroom_book::~classroom_book()
{
    delete ui;
}


//能否预约设计
void classroom_book::design_isbook()
{
    current_time = QDateTime::currentDateTime();
    ui->label_3->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_10->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_22->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_23->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_24->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_25->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_26->setText(current_time.toString("yyyy-MM-dd"));
    ui->label_27->setText(current_time.toString("yyyy-MM-dd"));
    //剩余名额设计
    QSqlQuery query(db);
    if(sex=="男")
    {
         query.exec("select * from stu_Mwashroom");
    }
   else if(sex=="女")
    {
        query.exec("select * from stu_Wwashroom");
    }

    while(query.next())
    {
        //A页面
     if((washroom_num=="A")&&(query.value(0).toString()=="A"))
     {
         if(query.value(3).toInt()==1)
         {
             ui->label_8->setText(QString::number(query.value(2).toInt()));
         }
         if(query.value(3).toInt()==2)
         {
             ui->label_15->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==3)
         {
             ui->label_52->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==4)
         {
             ui->label_53->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==5)
         {
             ui->label_54->setText(QString::number(query.value(2).toInt()));
         }
         if(query.value(3).toInt()==6)
         {
             ui->label_55->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==7)
         {
             ui->label_56->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==8)
         {
             ui->label_57->setText(QString::number(query.value(2).toInt()));

         }
     }
      //B页面
     if((washroom_num=="B")&&(query.value(0).toString()=="B"))
     {
         if(query.value(3).toInt()==1)
         {
             ui->label_8->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==2)
         {
             ui->label_15->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==3)
         {
             ui->label_52->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==4)
         {
             ui->label_53->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==5)
         {
             ui->label_54->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==6)
         {
             ui->label_55->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==7)
         {
             ui->label_56->setText(QString::number(query.value(2).toInt()));

         }
         if(query.value(3).toInt()==8)
         {
             ui->label_57->setText(QString::number(query.value(2).toInt()));

         }
     }
     //C页面
    if((washroom_num=="C")&&(query.value(0).toString()=="C"))
    {
        if(query.value(3).toInt()==1)
        {
            ui->label_8->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==2)
        {
            ui->label_15->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==3)
        {
            ui->label_52->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==4)
        {
            ui->label_53->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==5)
        {
            ui->label_54->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==6)
        {
            ui->label_55->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==7)
        {
            ui->label_56->setText(QString::number(query.value(2).toInt()));

        }
        if(query.value(3).toInt()==8)
        {
            ui->label_57->setText(QString::number(query.value(2).toInt()));

        }
    }
    //D页面
   if((washroom_num=="D")&&(query.value(0).toString()=="D"))
   {
       if(query.value(3).toInt()==1)
       {
           ui->label_8->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==2)
       {
           ui->label_15->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==3)
       {
           ui->label_52->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==4)
       {
           ui->label_53->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==5)
       {
           ui->label_54->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==6)
       {
           ui->label_55->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==7)
       {
           ui->label_56->setText(QString::number(query.value(2).toInt()));

       }
       if(query.value(3).toInt()==8)
       {
           ui->label_57->setText(QString::number(query.value(2).toInt()));

       }
   }
   //E页面
  if((washroom_num=="E")&&(query.value(0).toString()=="E"))
  {
      if(query.value(3).toInt()==1)
      {
          ui->label_8->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==2)
      {
          ui->label_15->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==3)
      {
          ui->label_52->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==4)
      {
          ui->label_53->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==5)
      {
          ui->label_54->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==6)
      {
          ui->label_55->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==7)
      {
          ui->label_56->setText(QString::number(query.value(2).toInt()));

      }
      if(query.value(3).toInt()==8)
      {
          ui->label_57->setText(QString::number(query.value(2).toInt()));

      }
  }
    }

    //在开始事件之前可以预约,否则不可预约
    //15:00
    if(current_time.toString("hh:mm")<"15:00")
    {
        isbook1=true;
        ui->label_58->setText("可预约");
        ui->label_58->setStyleSheet("color:blue;");
    }
    else{
        isbook1=false;
        ui->label_58->setText("不可预约");
        ui->label_58->setStyleSheet("color:red;");
    }
    //16:00
    if(current_time.toString("hh:mm")<"16:00")
    {
        isbook2=true;
        ui->label_59->setText("可预约");
        ui->label_59->setStyleSheet("color:blue;");
    }
    else{
        isbook2=false;
        ui->label_59->setText("不可预约");
        ui->label_59->setStyleSheet("color:red;");
    }
    //17:00
    if(current_time.toString("hh:mm")<"17:00")
    {
        isbook3=true;
        ui->label_60->setText("可预约");
        ui->label_60->setStyleSheet("color:blue;");
    }
    else{
        isbook3=false;
        ui->label_60->setText("不可预约");
        ui->label_60->setStyleSheet("color:red;");
    }
    //18:00
    if(current_time.toString("hh:mm")<"18:00")
    {
        isbook4=true;
        ui->label_61->setText("可预约");
        ui->label_61->setStyleSheet("color:blue;");
    }
    else{
        isbook4=false;
        ui->label_61->setText("不可预约");
        ui->label_61->setStyleSheet("color:red;");
    }
    //19:00
    if(current_time.toString("hh:mm")<"19:00")
    {
        isbook5=true;
        ui->label_62->setText("可预约");
        ui->label_62->setStyleSheet("color:blue;");
    }
    else{
        isbook5=false;
        ui->label_62->setText("不可预约");
        ui->label_62->setStyleSheet("color:red;");
    }
    //20:00
    if(current_time.toString("hh:mm")<"20:00")
    {
        isbook6=true;
        ui->label_63->setText("可预约");
        ui->label_63->setStyleSheet("color:blue;");
    }
    else{
        isbook6=false;
        ui->label_63->setText("不可预约");
        ui->label_63->setStyleSheet("color:red;");
    }
    //21:00
    if(current_time.toString("hh:mm")<"21:00")
    {
        isbook7=true;
        ui->label_64->setText("可预约");
        ui->label_64->setStyleSheet("color:blue;");
    }
    else{
        isbook7=false;
        ui->label_64->setText("不可预约");
        ui->label_64->setStyleSheet("color:red;");
    }
    //22:00
    if(current_time.toString("hh:mm")<"22:00")
    {
        isbook8=true;
        ui->label_65->setText("可预约");
        ui->label_65->setStyleSheet("color:blue;");
    }
    else{
        isbook8=false;
        ui->label_65->setText("不可预约");
        ui->label_65->setStyleSheet("color:red;");
    }
}
//选择预约界面返回按钮的槽函数
void classroom_book::on_pushButton_clicked()
{
   send_user_back();
}
//15:00-16:00
void classroom_book::on_pushButton_2_clicked()
{
    num=1;
    //如果能预约
    if(isbook1==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_3->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("15:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("16:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(this, "Title","是否确定预约?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//16:00-17:00
void classroom_book::on_pushButton_3_clicked()
{
    num=2;
    if(isbook2==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_10->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("16:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("17:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//17:00-18:00
void classroom_book::on_pushButton_4_clicked()
{
    num=3;
    if(isbook3==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //获取时间
     QDate date=QDate::fromString(ui->label_22->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("17:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("18:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//18:00-19:00
void classroom_book::on_pushButton_5_clicked()
{
    num=4;
    if(isbook4==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_23->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("18:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("19:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//19:00-20:00
void classroom_book::on_pushButton_6_clicked()
{
    num=5;
    if(isbook5==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_24->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("19:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("20:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//20:00-21:00
void classroom_book::on_pushButton_7_clicked()
{
    num=6;
    if(isbook6==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_25->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("20:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("21:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//21:00-22:00
void classroom_book::on_pushButton_8_clicked()
{
    num=7;
    if(isbook7==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_26->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("21:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("22:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}
//22:00-23:00
void classroom_book::on_pushButton_9_clicked()
{
    num=8;
    if(isbook8==false)
    {
        QMessageBox::information(this,"Title","已过预约时间,无法预约!");
    }
    else if(isexist==true)
    {
         QMessageBox::information(this,"Title","已经预约过了,无法预约!");
    }
    else{
    //设置时间
     QDate date=QDate::fromString(ui->label_27->text(),"yyyy-MM-dd");
     QTime begintime=QTime::fromString("22:00:00","hh:mm:ss");
     begin_time.setDate(date);
     begin_time.setTime(begintime);
     QTime endtime=QTime::fromString("23:00:00","hh:mm:ss");
     end_time.setDate(date);
     end_time.setTime(endtime);

     QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定预约", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     switch (result)
     {
     case QMessageBox::Yes:
         result_yes();
         break;
     case QMessageBox::No:
         qDebug()<<"NO";
         break;
     default:
         break;
     }
    }
}

//连接数据库
void classroom_book::connectsql()
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
//yes按钮按下后,把该条预约记录导入数据库中
void classroom_book::result_yes()
{
    QSqlQuery query(db);
    QString begintime=begin_time.toString("yyyy-MM-dd hh:mm");
    QString endtime=end_time.toString("yyyy-MM-dd hh:mm");
    if(query.exec( QString("insert into stu_rec(id,washroom_num,time_num,begintime,endtime,isbegin,isend) values('%1','%2','%3','%4','%5','%6','%7')").arg(id).arg(washroom_num).arg(num).arg(begintime).arg(endtime).arg(0).arg(0)))
    {
        QMessageBox::information(this,"infor","预约成功！");
    }
    else{
        QMessageBox::information(this,"infor","预约名额已满，预约失败！");
    }
}
