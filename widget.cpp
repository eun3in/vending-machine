#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    }
    if (money < 150) {
        ui->pbTea->setEnabled(false);
    }
    if (money < 200) {
        ui->pbMilk->setEnabled(false);
    }
    else {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::resetMoney()
{
    money = 0;
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QString msg = QString("500: %1\n100: %2\n50: %3\n10: %4")
                      .arg(money / 500)
                      .arg(money %500/100)
                      .arg(money %100/50)
                      .arg(money %50/10);

    QMessageBox mb;
    mb.information(nullptr, "jandon", msg);
    resetMoney();
}

