#include "reply_feedback.h"
#include "ui_reply_feedback.h"

reply_feedback::reply_feedback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reply_feedback)
{
    ui->setupUi(this);
}

reply_feedback::~reply_feedback()
{
    delete ui;
}

void reply_feedback::on_pushButton_clicked()
{
    send_admin_back();
}

void reply_feedback::show_rep()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"反馈序号"<<"反馈学生"<<"学生专业"<<"反馈内容"<<"回复状态"<<"是否回复";
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
    ui->tableWidget->setColumnWidth(0, 85);
    ui->tableWidget->setColumnWidth(1, 110);
    ui->tableWidget->setColumnWidth(2, 130);
    ui->tableWidget->setColumnWidth(3, 254);
    ui->tableWidget->setColumnWidth(4, 110);
    ui->tableWidget->setColumnWidth(5, 120);
}
//连接数据库
void reply_feedback::connectsql()
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
void reply_feedback::show_reply()
{
    connectsql();
    QSqlQuery query(db);
    query.exec(QString("select feedback_num,feedback.id,major,feedback_text,reply_text from feedback,student where feedback.id=student.id"));
    recnum=0;
    show_rep();
    while(query.next())
     {
         recnum++;
               ui->tableWidget->setRowCount(recnum);
                QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(query.value(0).toInt()));
               QTableWidgetItem *item1 = new QTableWidgetItem(query.value(1).toString());
               QTableWidgetItem *item2 = new QTableWidgetItem(query.value(2).toString());
               QTableWidgetItem *item3 = new QTableWidgetItem(query.value(3).toString());
               QTableWidgetItem *item4;
               if(!query.value(4).isNull())
               {
                   item4 = new QTableWidgetItem(QString("已回复"));
                   item4->setTextColor("GREEN");
               }
               else
               {
                   item4 = new QTableWidgetItem(QString("未回复"));
                   item4->setTextColor("RED");
               }
               QPushButton *button_del=new QPushButton(QString("确定回复"), this);
               //绑定相应的槽函数
               connect(button_del, SIGNAL(clicked()), this, SLOT(reply_yes()));
                 ui->tableWidget->setItem(recnum-1,0,item0);
               ui->tableWidget->setItem(recnum-1,1,item1);
                ui->tableWidget->setItem(recnum-1,2,item2);
                 ui->tableWidget->setItem(recnum-1,3,item3);
                  ui->tableWidget->setItem(recnum-1,4,item4);
                  ui->tableWidget->setCellWidget(recnum-1,5,button_del);
    }
}
//确定回复
void reply_feedback::reply_yes()
{

    QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (button == nullptr)
        {
            return;
        }
        QModelIndex qIndex = ui->tableWidget->indexAt(QPoint(button->frameGeometry().x(),button->frameGeometry().y()));
        int row = qIndex.row();
        QSqlQuery query(db);
        query.exec(QString("select * from feedback where feedback_num='%1'").arg(ui->tableWidget->item(row,0)->text().toInt()));
        if(query.next())
        {
            //未回复进行回复
            if(query.value(4).isNull())
            {

                bool ok;
                QString text = QInputDialog::getText(NULL,"infor","请输入回复内容", QLineEdit::Normal,0, &ok);
                    if (ok && !text.isEmpty())
                    {
                        QSqlQuery query1(db);
                        query1.exec(QString("update feedback set reply_text='%1' where feedback_num='%2'").arg(text).arg(query.value(0).toInt()));
                        QMessageBox::information(this,"infor","回复成功！");
                        ui->tableWidget->item(row,4)->setText("已回复");
                        ui->tableWidget->item(row,4)->setTextColor("GREEN");
                    }
                    else {
                        QMessageBox::information(this,"infor","回复失败！");
                    }
            }
            else {
                //已回复不能再回复
                QMessageBox::information(this,"infor", "已回复，不能重复回复！");
            }
        }

}



