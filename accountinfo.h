#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AccountInfo;
}

class AccountInfo : public QDialog
{
    Q_OBJECT

public:

    explicit AccountInfo(QWidget *parent = nullptr);
    ~AccountInfo();

private slots:
    void on_pushBtn_save_clicked();

    void on_pushButton_clicked();

private:
    Ui::AccountInfo *ui;
};

#endif // ACCOUNTINFO_H
