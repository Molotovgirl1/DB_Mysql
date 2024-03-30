#include "user_concall.h"
#include "ui_user_concall.h"

user_concall::user_concall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_concall)
{
    ui->setupUi(this);
}

user_concall::~user_concall()
{
    delete ui; 
}
//连接数据库
void user_concall::connectsql()
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
//把联系方式的电话号码和邮箱与数据库连接起来
void user_concall::design_user_connect()
{
    connectsql();
    QSqlQuery query(db);
    query.exec(QString("select * from student where id='%1'").arg(id));
       if(query.next())
       {
              callnum=query.value(5).toString();
              email=query.value(6).toString();
      }
      ui->lineEdit->setText(callnum);
      ui->lineEdit_2->setText(email);
      ui->lineEdit->setReadOnly(true);
      ui->lineEdit_2->setReadOnly(true);
}
//联系方式界面按动返回按钮的槽
void user_concall::on_pushButton_clicked()
{
   send_user_back();
}
//联系方式界面按动手机号修改的按钮的槽
void user_concall::on_pushButton_2_clicked()
{
    ui->lineEdit->setReadOnly(false);
}
//联系方式界面按动邮箱修改的按钮的槽
void user_concall::on_pushButton_3_clicked()
{
    ui->lineEdit_2->setReadOnly(false);
}
//联系方式界面按动手机号保存的按钮的槽
void user_concall::on_pushButton_4_clicked()
{
    //如果手机号格式正确，则能够保存，否则无法保存
    callnum=ui->lineEdit->text();
    if(IsValidPhoneNumber(callnum)==true)
    {
        qDebug()<<"格式正确";
        ui->lineEdit->setReadOnly(true);
        //在数据库中修改电话号码
        QSqlQuery query(db);
        query.exec(QString("update student set callnum='%1' where id='%2'").arg(callnum).arg(id));
    }
    else {
        QMessageBox::information(this,"infor", "手机号格式错误");
    }
}
//联系方式界面按动邮箱保存的按钮的槽
void user_concall::on_pushButton_5_clicked()
{
    //如果邮箱格式正确，则能够保存，否则无法保存
        email=ui->lineEdit_2->text();
        if(IsValidEmailNumber(email)==true)
        {
            qDebug()<<"格式正确";
            ui->lineEdit_2->setReadOnly(true);
            //在数据库中修改邮箱号码
            QSqlQuery query(db);
            query.exec(QString("update student set email='%1' where id='%2'").arg(email).arg(id));
        }
        else {
            QMessageBox::information(this,"infor", "邮箱格式错误");
        }
}
//判断手机号格式是否正确
bool user_concall::IsValidPhoneNumber(const QString & phoneNum)
{
    QRegExp regx("^1([358][0-9]|4[579]|66|7[0135678]|9[89])[0-9]{8}$");
    QRegExpValidator regs(regx, 0);
    QString pNum = phoneNum;
    int pos = 0;
    QValidator::State res = regs.validate(pNum, pos);
    if (QValidator::Acceptable == res) {
        return true;
    }
    else {
        return false;
    }
}
//判断邮箱格式是否正确
 bool user_concall::IsValidEmailNumber(const QString & emailNum)
 {
     QRegExp rx("^[a-z0-9A-Z]+[- | a-z0-9A-Z . _]+@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-z]{2,}$");
        if(!rx.exactMatch(emailNum))
            {
               return false;
            }
                else {
                return true;
 }
 }

