#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "accountinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
            mydb=QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("/home/bill/Documents/C++ projects/database.db");

            if(!mydb.open()){
                qDebug()<<("Failed to open database");
                return false;
            }
            else{
                qDebug()<<("Connected.....");
                return  true;
            }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_label_4_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
