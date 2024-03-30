#include "design_user_rec.h"
#include "ui_design_user_rec.h"

design_user_rec::design_user_rec(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::design_user_rec)
{
    ui->setupUi(this);
}

design_user_rec::~design_user_rec()
{
    delete ui;
}
//历史记录界面按动返回按钮的槽
void design_user_rec::on_pushButton_clicked()
{
    send_user_back();
}
//连接数据库
void design_user_rec::connectsql()
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
//个人历史记录设置
void design_user_rec::design_user_record()
{
    connectsql();
    QSqlQuery query(db);
    query.exec(QString("select * from stu_rec where id='%1' and isend='%2'").arg(id).arg(QString::number(1)));
    recnum=0;
    show_rec();
     while(query.next())
     {
               recnum++;
               ui->tableWidget->setRowCount(recnum);
               QTableWidgetItem *item0 = new QTableWidgetItem(query.value(2).toString());
               QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(query.value(3).toInt()));
                QTableWidgetItem *item2 = new QTableWidgetItem(query.value(4).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                 QTableWidgetItem *item3 = new QTableWidgetItem(query.value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                  QTableWidgetItem *item4;
                  if(query.value(6).toString()==QString::number(1))
                  {
                      item4 = new QTableWidgetItem(QString("已开始"));
                  }
                  else
                  {
                      item4 = new QTableWidgetItem(QString("未开始"));
                  }
                   QTableWidgetItem *item5=new QTableWidgetItem(QString("已结束"));
               ui->tableWidget->setItem(recnum-1,0,item0);
                ui->tableWidget->setItem(recnum-1,1,item1);
                 ui->tableWidget->setItem(recnum-1,2,item2);
                  ui->tableWidget->setItem(recnum-1,3,item3);
                   ui->tableWidget->setItem(recnum-1,4,item4);
                   ui->tableWidget->setItem(recnum-1,5,item5);
     }
    ui->label_4->setText(QString::number(recnum));
}
void design_user_rec::show_rec()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"区域号"<<"时间段号"<<"开始时间"<<"结束时间"<<"签到状态"<<"结束状态";
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
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止编辑
    ui->tableWidget->setColumnWidth(0, 100);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 180);
    ui->tableWidget->setColumnWidth(3, 180);
    ui->tableWidget->setColumnWidth(4, 130);
    ui->tableWidget->setColumnWidth(5,130);

}
