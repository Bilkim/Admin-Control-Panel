#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    if(!connOpen())
        ui->label->setText("Failed to open database");
    else
        ui->label->setText("Connected.....");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(!connOpen()){
        qDebug()<<("Failed to open database");
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from account where Username='"+username+"'and Password='"+password+"'");

    if(qry.exec())
    {
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is correct");
            connClose();
            this->hide();
            AccountInfo accountInfo;
            accountInfo.setModal(true);
            accountInfo.exec();

        }
        if(count>1)
            ui->label->setText("Duplicate username and password");
        if(count<1)
            ui->label->setText("Incorrect Username or password");
    }
}


