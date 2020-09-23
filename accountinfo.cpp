#include "accountinfo.h"
#include "ui_accountinfo.h"
#include <QMessageBox>

AccountInfo::AccountInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountInfo)
{

    ui->setupUi(this);
    MainWindow conn;
        if(!conn.connOpen())
            ui->label_status->setText("Failed to open database");
        else
            ui->label_status->setText("Connected.....");
}

AccountInfo::~AccountInfo()
{
    delete ui;
}

void AccountInfo::on_pushBtn_save_clicked()
{
    MainWindow conn;
    QString username,password,id,age;
    id = ui->lineEdit_ID->text();
    username = ui->lineEdit_name->text();
    password = ui->lineEdit_pwd->text();
    age = ui->lineEdit_age->text();

    if(!conn.connOpen()){
        qDebug()<<("Failed to open database");
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into account (ID,Username,Password,Age) values('"+id+"', '"+username+"', '"+password+"', '"+age+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void AccountInfo::on_pushButton_clicked()
{
    MainWindow conn;
    QString username,password,id,age;
    id = ui->lineEdit_ID->text();
    username = ui->lineEdit_name->text();
    password = ui->lineEdit_pwd->text();
    age = ui->lineEdit_age->text();

    if(!conn.connOpen()){
        qDebug()<<("Failed to open database");
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update account set ID='"+id+"',  Password='"+password+"', Age='"+age+"' where Username='"+username+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Update complete"));
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}
