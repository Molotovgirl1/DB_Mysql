#include "my_public.h"
#include "ui_my_public.h"

my_public::my_public(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_public)
{
    ui->setupUi(this);
}

my_public::~my_public()
{
    delete ui;
}

void my_public::on_pushButton_clicked()
{
    send_admin_back();
}
//连接数据库
void my_public::connectsql()
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
//删除通知
void my_public::delete_not()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (button == nullptr)
        {
            return;
        }
        QModelIndex qIndex = ui->tableWidget->indexAt(QPoint(button->frameGeometry().x(),button->frameGeometry().y()));
        int row = qIndex.row();
        QSqlQuery query(db);
        db.transaction();//开始事务
        //查询是否为本人发布通知
        query.exec(QString("select * from notice where number='%1'").arg(ui->tableWidget->item(row,0)->text()));
        while(query.next())
        {
            if(query.value(3).toString()==id)
            {
                query.exec(QString("delete from notice where number='%1'").arg(ui->tableWidget->item(row,0)->text()));
                db.commit();//如果是本人，则删除并提交
                QMessageBox::information(this,"infor", "删除成功！");
            }
            else {
                db.rollback();//否则回归
                QMessageBox::information(this,"infor", "删除失败，不具有删除权限！");
            }
        }
}

//个人发布的通知
void my_public::design_public_record()
{
    connectsql();
    QSqlQuery query(db);
    query.exec(QString("select * from notice"));
    recnum=0;
    show_public();
    while(query.next())
     {
         recnum++;
               ui->tableWidget->setRowCount(recnum);
               QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(query.value(0).toInt()));
               QTableWidgetItem *item1 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem *item2 = new QTableWidgetItem(query.value(2).toString());
                 QTableWidgetItem *item3 = new QTableWidgetItem(query.value(4).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                QPushButton *button_del=new QPushButton(QString("删除"), this);
                //绑定相应的槽函数
                connect(button_del, SIGNAL(clicked()), this, SLOT(delete_not()));
               ui->tableWidget->setItem(recnum-1,0,item0);
                ui->tableWidget->setItem(recnum-1,1,item1);
                 ui->tableWidget->setItem(recnum-1,2,item2);
                  ui->tableWidget->setItem(recnum-1,3,item3);
                  ui->tableWidget->setCellWidget(recnum-1,4,button_del);
     }
      ui->label_4->setText(QString::number(recnum));
}

void my_public::show_public()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"通知序号"<<"通知类型"<<"通知内容"<<"发布时间"<<" ";
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
    ui->tableWidget->setColumnWidth(1, 139);
    ui->tableWidget->setColumnWidth(2, 310);
    ui->tableWidget->setColumnWidth(3, 170);
    ui->tableWidget->setColumnWidth(4, 85);

}
