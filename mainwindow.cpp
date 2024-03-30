#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    initpage();//对主界面初始化
    m_Login.show();//展示登录界面
    connectsql();//主界面进行数据库连接

    //成功登录界面后转到主界面
    auto mainwindow_show=[&]()
    {
        this->id=m_Login.id;//把登录界面的学号传到主界面中
        m_user_call.id=m_Login.id;//把学号传到个人信息联系方式界面
        m_user_rec.id=m_Login.id;//把学号传到历史记录个人信用界面
        m_user_passwd.id=m_Login.id;//把学号传到修改密码界面
        m_book.id=m_Login.id;
        this->show();
        m_Login.hide();
        design_welcome();//主界面欢迎界面的设计
        design_user();//主界面个人中心的设计
        init_book();//进行预约界面初始化设计
        show_notice();//通知界面初始化设计
        show_feedback();

    };
     connect(&m_Login,&page_login::send_login_success,this,mainwindow_show);

    //用户个人中心联系方式返回到个人中心
    auto mainwindow_show1=[&]()
    {
        this->show();
        m_user_call.hide();
    };
    connect(&m_user_call,&user_concall::send_user_back,this,mainwindow_show1);

    //用户历史记录返回到个人中心
    auto mainwindow_show2=[&]()
    {
        this->show();
        m_user_rec.hide();
     };
     connect(&m_user_rec,&design_user_rec::send_user_back,this,mainwindow_show2);

     //密码修改界面返回到个人中心
     auto mainwindow_show3=[&]()
     {
         this->show();
         m_user_passwd.hide();
     };
     connect(&m_user_passwd,&user_change_passwd::send_user_back,this,mainwindow_show3);

     //选择预约界面返回进行预约界面
     auto mainwindow_show4=[&]()
     {
         this->show();
         m_book.hide();
     };
     connect(&m_book,&classroom_book::send_user_back,this,mainwindow_show4);

     //给我的预约界面设置一个时钟，方便随时更新
     timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(design_mybook()));
     timer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//用于主界面的初始化
void MainWindow::initpage()
{
    ui->stackedWidget->setCurrentIndex(0);

}

//用于主界面的转化
void MainWindow::switchpage()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button==ui->pushButton)
        ui->stackedWidget->setCurrentIndex(1);
    else if(button==ui->pushButton_2)
        ui->stackedWidget->setCurrentIndex(2);
    else if(button==ui->pushButton_3)
        ui->stackedWidget->setCurrentIndex(3);
    else if(button==ui->pushButton_4)
        ui->stackedWidget->setCurrentIndex(6);
    else if(button==ui->pushButton_17)
        ui->stackedWidget->setCurrentIndex(4);
    else if(button==ui->pushButton_18)
        ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_clicked()
{
    switchpage();
}

void MainWindow::on_pushButton_2_clicked()
{
    switchpage();
}

void MainWindow::on_pushButton_3_clicked()
{
    switchpage();
}

void MainWindow::on_pushButton_17_clicked()
{
    switchpage();
}
void MainWindow::on_pushButton_18_clicked()
{
    switchpage();
}

void MainWindow::on_pushButton_4_clicked()
{
    switchpage();
}

//连接数据库
void MainWindow::connectsql()
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
//主页面初始化界面的设计
void MainWindow::design_welcome()
{
    ui->label->setText(id);
}
//主页面个人中心的设计
void MainWindow::design_user()
{
    QSqlQuery query(db);
    query.exec(QString("select * from student where id='%1'").arg(id));  //建立查询
      if(query.next())
       {
               name=query.value(2).toString();
               major=query.value(3).toString();
               sex=query.value(4).toString();
               m_book.sex=sex;
       }
    ui->label2->setText(id);
    ui->label1->setText(name);
    ui->label3->setText(major);
    ui->label_14->setText(sex);
}
//个人页面转换到联系方式的页面的转换
void MainWindow::on_pushButton_5_clicked()
{
    m_user_call.show();
    this->hide();
     m_user_call.design_user_connect();
}

//个人页面转换到个人积分页面的转换
void MainWindow::on_pushButton_6_clicked()
{
    m_user_rec.show();
    this->hide();
    m_user_rec.design_user_record();

}
//个人页面转换到修改密码页面的转换
void MainWindow::on_pushButton_7_clicked()
{
    m_user_passwd.show();
    this->hide();
}
//个人页面按动退出登录后转换到登录页面
void MainWindow::on_pushButton_8_clicked()
{
    m_Login.show();
    this->hide();
}
//我的预约界面中历史记录按钮的槽
void MainWindow::on_pushButton_9_clicked()
{
    m_user_rec.show();
    this->hide();
    m_user_rec.design_user_record();
}
//我的预约界面中预约设计
void MainWindow::design_mybook()
{
    QSqlQuery query(db);
    query.exec(QString("select * from stu_rec where id='%1' and isend='%2'").arg(id).arg(QString::number(0)));
    isexist=false;
     if(query.next())
     {
               isexist=true;
               washroom_num=query.value(2).toString();
               ui->label_7->setText(query.value(2).toString());
               num=query.value(3).toInt();
               ui->label_17->setText(QString::number(query.value(3).toInt()));
               begin_time=query.value(4).toDateTime();
               ui->label_8->setText(query.value(4).toDateTime().toString("yyyy-MM-dd hh:mm"));
               end_time=query.value(5).toDateTime();
               ui->label_10->setText(query.value(5).toDateTime().toString("hh:mm"));
               if(query.value(6).toString()==QString::number(1))
               {
                   ui->label_11->setText(QString("已开始"));
               }
               else{
                   ui->label_11->setText(QString("未开始"));
               }
}
               current_time = QDateTime::currentDateTime();
               //在开始时间之前，取消预约按钮生效，设置数据库中isbegin值为0
                if(current_time<begin_time)
                {
                    ui->widget_10->show();
                    ui->pushButton_10->show();
                }
                //在开始时间之后，结束时间之前，取消预约按钮失效，未开始变为已开始，设置数据库中isbegin值为1
                else if((current_time>=begin_time)&&(current_time<=end_time))
                {
                    ui->widget_10->show();
                    ui->pushButton_10->hide();
                    ui->label_11->setText(QString("已开始"));
                    QSqlQuery query1(db);
                    query1.exec(QString("update stu_rec set isbegin='%1' where id='%2' and isend='%3'").arg(true).arg(id).arg(false));
                }
                //在结束时间之后，正在进行的记录都消失，释放名额
               else if(current_time>end_time)
                {
                    ui->widget_10->hide();
                    ui->pushButton_10->hide();
                    QSqlQuery query1(db);
                    query1.prepare(QString("call release_book(?)"));
                    query1.bindValue(0,id);
                    query1.exec();
                }
     if(isexist==false)
     {
         ui->widget_10->hide();
         ui->label_15->show();
     }
     else {
         ui->label_15->hide();

     }
     m_book.isexist=isexist;

}
//取消预约按钮的槽，释放名额
void MainWindow::on_pushButton_10_clicked()
{
    QSqlQuery query(db);
    query.exec(QString("update stu_rec set isend='%1' and isbegin='%2' where id='%3' and isend='%4'").arg(true).arg(false).arg(id).arg(false));
    release_washroom();

}

//进行预约界面的初始化
void MainWindow::init_book()
{
    if(sex==QString("男"))
    {
        ui->label_16->setText(QString("浴园洗浴男部预约"));
    }
    else if(sex==QString("女"))
    {
        ui->label_16->setText(QString("浴园洗浴女部预约"));
    }
}

//A区确定预约槽函数
void MainWindow::on_pushButton_12_clicked()
{
    m_book.washroom_num="A";
    m_book.show();
    this->hide();
}
//B区确定预约槽函数
void MainWindow::on_pushButton_13_clicked()
{
    m_book.washroom_num="B";
    m_book.show();
    this->hide();
}
//C区确定预约槽函数
void MainWindow::on_pushButton_14_clicked()
{
    m_book.washroom_num="C";
    m_book.show();
    this->hide();
}
//D区确定预约槽函数
void MainWindow::on_pushButton_15_clicked()
{
    m_book.washroom_num="D";
    m_book.show();
    this->hide();
}
//E区确定预约槽函数
void MainWindow::on_pushButton_16_clicked()
{
    m_book.washroom_num="E";
    m_book.show();
    this->hide();
}
//释放名额的函数
void MainWindow::release_washroom()
{
    QSqlQuery query(db);
    if(sex=="男")
    {
     query.exec(QString("update stu_mwashroom set rest_num=rest_num+1 where washroom_num='%1' and time_num='%2'").arg(washroom_num).arg(num));
    }
    if(sex=="女")
    {
     query.exec(QString("update stu_wwashroom set rest_num=rest_num+1 where washroom_num='%1' and time_num='%2'").arg(washroom_num).arg(num));
    }
}
//注销账号槽函数
void MainWindow::on_pushButton_11_clicked()
{
    //弹出窗口判断是否注销
    QMessageBox::StandardButton result=QMessageBox::information(NULL, "Title","是否确定注销账号", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
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
void MainWindow::result_yes()
{
    QSqlQuery query(db);
    db.transaction();//开始事务
    bool ok2=query.exec(QString("delete from feedback where id='%1'").arg(id));
    bool ok1=query.exec(QString("delete from student where id='%1'").arg(id));
           qDebug()<<ok1<<ok2;
            if(ok1&&ok2&&!isexist)
            {
                db.commit();//提交事务
                QMessageBox::information(this,"infor", "注销账号成功！");//窗口显示注销成功
                this->hide();
                m_Login.show();
            }else
            {
                db.rollback();//回滚
                 QMessageBox::information(this,"infor", "注销账号失败！");
            }
}
void MainWindow::show_not()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"通知类型"<<"通知内容"<<"发布时间";
    ui->tableWidget->setColumnCount(headerText.count());
    for (int i=0; i<ui->tableWidget->columnCount(); i++)
     {
            headerItem = new QTableWidgetItem(headerText.at(i));
            QFont font = headerItem->font();
            font.setBold(false);     //设置字体加粗
            font.setPointSize(9);  //设置字体字号
            headerItem->setTextColor(Qt::black); //设置颜色
            headerItem->setFont(font);
            ui->tableWidget->setHorizontalHeaderItem(i,headerItem);
      }
  //  ui->tableWidget ->setGeometry (0,58,825,342);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 371);
    ui->tableWidget->setColumnWidth(2, 180);
}
void MainWindow::show_notice()
{
    QSqlQuery query(db);
    query.exec(QString("select * from notice"));
    recnum=0;
    show_not();
    while(query.next())
     {
         recnum++;
               ui->tableWidget->setRowCount(recnum);
               QTableWidgetItem *item1 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem *item2 = new QTableWidgetItem(query.value(2).toString());
                 QTableWidgetItem *item3 = new QTableWidgetItem(query.value(4).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));

               ui->tableWidget->setItem(recnum-1,0,item1);
                ui->tableWidget->setItem(recnum-1,1,item2);
                 ui->tableWidget->setItem(recnum-1,2,item3);

      }
}


void MainWindow::on_pushButton_19_clicked()
{
    if(ui->lineEdit->text()!=NULL)
    {
        QSqlQuery query(db);
        query.exec(QString("insert into feedback(id,feedback_text,reply_text) values('%1','%2',NULL)").arg(id).arg(ui->lineEdit->text()));
         QMessageBox::information(this,"infor", "反馈成功！");
    }
    else {
         QMessageBox::information(this,"infor", "反馈失败！");
    }
}

void MainWindow::show_feed()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"反馈内容"<<"是否回复"<<"回复内容";
    ui->tableWidget_2->setColumnCount(headerText.count());
    for (int i=0; i<ui->tableWidget_2->columnCount(); i++)
     {
            headerItem = new QTableWidgetItem(headerText.at(i));
            QFont font = headerItem->font();
            font.setBold(false);     //设置字体加粗
            font.setPointSize(9);  //设置字体字号
            headerItem->setTextColor(Qt::black); //设置颜色
            headerItem->setFont(font);
            ui->tableWidget_2->setHorizontalHeaderItem(i,headerItem);
      }
   ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setColumnWidth(0, 250);
    ui->tableWidget_2->setColumnWidth(1, 100);
    ui->tableWidget_2->setColumnWidth(2, 305);
}

void MainWindow::show_feedback()
{
    QSqlQuery query(db);
    query.exec(QString("select * from feedback where id='%1'").arg(id));
    recnum1=0;
    show_feed();
    while(query.next())
     {
         recnum1++;
               ui->tableWidget_2->setRowCount(recnum1);
               QTableWidgetItem *item1 = new QTableWidgetItem(query.value(2).toString());
               QTableWidgetItem *item2;
               if(!query.value(3).isNull())
               {
                   item2 = new QTableWidgetItem(QString("已回复"));
                   item2->setTextColor("GREEN");
               }
               else
               {
                   item2 = new QTableWidgetItem(QString("未回复"));
                   item2->setTextColor("RED");
               }
                QTableWidgetItem *item3;
                if(query.value(3).isNull())
                {
                    item3=new QTableWidgetItem(QString("无"));
                }
                else {
                    item3=new QTableWidgetItem(query.value(3).toString());
                }
               ui->tableWidget_2->setItem(recnum1-1,0,item1);
                ui->tableWidget_2->setItem(recnum1-1,1,item2);
                 ui->tableWidget_2->setItem(recnum1-1,2,item3);

      }

}
