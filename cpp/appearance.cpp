#include "appearance.h"
#include "ui_appearance.h"
#include <QMessageBox>
#include<QDebug>
#include<QPixmap>
#include<QPalette>
#include<QPainter>
Appearance::Appearance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appearance)
{
    ui->setupUi(this);
    //提升窗口等级
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置背景
    this->setStyleSheet("QWidget {background-image:url(:/new/bj/5.png)}");
}

Appearance::~Appearance()
{
    delete ui;
}
//进入菜单
void Appearance::on_pushButton_1_clicked()
{
    //隐藏主界面
    this->hide();
    //生成新的界面
    _menu = new Menu(ui->lineEdit->text());
    _menu->show();
}
//退出菜单
void Appearance::on_pushButton_2_clicked()
{
    this->hide();
    QMessageBox::about(this,tr("提示信息"),tr("欢迎您下次使用~"));
    this->close();
}
