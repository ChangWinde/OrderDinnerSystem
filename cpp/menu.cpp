#include "menu.h"
#include "ui_menu.h"
#include<QDebug>
#include"appearance.h"
Menu::Menu(QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    //提升窗口等级
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置背景
    this->setStyleSheet("QWidget {background-image:url(:/new/bj/5.png)}");
    //设置用户名
    ui->label_e_0->setText(name);
    //数据初始化
    _price[1] = 8;
    _price[2] = 12;
    _price[3] = 18;
    _price[4] = 16;
    _price[5] = 22;
    _price[6] = 22;
    _price[7] = 8;
    _price[8] = 12;
    _price[9] = 12;
    _price[10] = 38;
    //这里是程序的开始
    start();
}
//初始化数据
void Menu::start()
{
    ui->pushButton_l11->setEnabled(false);
    ui->pushButton_l21->setEnabled(false);
    ui->pushButton_l31->setEnabled(false);
    ui->pushButton_l41->setEnabled(false);
    ui->pushButton_l51->setEnabled(false);
    ui->pushButton_r11->setEnabled(false);
    ui->pushButton_r21->setEnabled(false);
    ui->pushButton_r31->setEnabled(false);
    ui->pushButton_r41->setEnabled(false);
    ui->pushButton_r51->setEnabled(false);
    //初始化数据
    for(int i = 1;i<=10;i++)
        _num[i]= 0;
    _total = 0;
}

Menu::~Menu()
{
    delete ui;
}
//下面是button(-|+）的响应函数;顺序：逐行，每一行先左后右
void Menu::on_pushButton_l11_clicked()
{
    int num = ui->label_l12->text().toInt()-1;
    ui->label_l12->setText(QString::number(num));
    if(!num)
        ui->pushButton_l11->setEnabled(false);
    _num[1]--;
    calculateMoney();
}

void Menu::on_pushButton_l12_clicked()
{
    int num = ui->label_l12->text().toInt()+1;
    ui->label_l12->setText(QString::number(num));
    if(num)
        ui->pushButton_l11->setEnabled(true);
    _num[1]++;
    calculateMoney();
}

void Menu::on_pushButton_r11_clicked()
{
    int num = ui->label_r12->text().toInt()-1;
    ui->label_r12->setText(QString::number(num));
    if(!num)
        ui->pushButton_r11->setEnabled(false);
    _num[2]--;
    calculateMoney();
}

void Menu::on_pushButton_r12_clicked()
{
    int num = ui->label_r12->text().toInt()+1;
    ui->label_r12->setText(QString::number(num));
    if(num)
        ui->pushButton_r11->setEnabled(true);
    _num[2]++;
    calculateMoney();
}
//第二行
void Menu::on_pushButton_l21_clicked()
{
    int num = ui->label_l22->text().toInt()-1;
    ui->label_l22->setText(QString::number(num));
    if(!num)
        ui->pushButton_l21->setEnabled(false);
    _num[3]--;
    calculateMoney();
}

void Menu::on_pushButton_l22_clicked()
{
    int num = ui->label_l22->text().toInt()+1;
    ui->label_l22->setText(QString::number(num));
    if(num)
        ui->pushButton_l21->setEnabled(true);
    _num[3]++;
    calculateMoney();
}

void Menu::on_pushButton_r21_clicked()
{
    int num = ui->label_r22->text().toInt()-1;
    ui->label_r22->setText(QString::number(num));
    if(!num)
        ui->pushButton_r21->setEnabled(false);
    _num[4]--;
    calculateMoney();
}

void Menu::on_pushButton_r22_clicked()
{
    int num = ui->label_r22->text().toInt()+1;
    ui->label_r22->setText(QString::number(num));
    if(num)
        ui->pushButton_r21->setEnabled(true);
    _num[4]++;
    calculateMoney();
}
//第三行
void Menu::on_pushButton_l31_clicked()
{
    int num = ui->label_l32->text().toInt()-1;
    ui->label_l32->setText(QString::number(num));
    if(!num)
        ui->pushButton_l31->setEnabled(false);
    _num[5]--;
    calculateMoney();
}

void Menu::on_pushButton_l32_clicked()
{
    int num = ui->label_l32->text().toInt()+1;
    ui->label_l32->setText(QString::number(num));
    if(num)
        ui->pushButton_l31->setEnabled(true);
    _num[5]++;
    calculateMoney();
}

void Menu::on_pushButton_r31_clicked()
{
    int num = ui->label_r32->text().toInt()-1;
    ui->label_r32->setText(QString::number(num));
    if(!num)
        ui->pushButton_r31->setEnabled(false);
    _num[6]--;
    calculateMoney();
}

void Menu::on_pushButton_r32_clicked()
{
    int num = ui->label_r32->text().toInt()+1;
    ui->label_r32->setText(QString::number(num));
    if(num)
        ui->pushButton_r31->setEnabled(true);
    _num[6]++;
    calculateMoney();
}
//第四行
void Menu::on_pushButton_l41_clicked()
{
    int num = ui->label_l42->text().toInt()-1;
    ui->label_l42->setText(QString::number(num));
    if(!num)
        ui->pushButton_l41->setEnabled(false);
    _num[7]--;
    calculateMoney();
}

void Menu::on_pushButton_l42_clicked()
{
    int num = ui->label_l42->text().toInt()+1;
    ui->label_l42->setText(QString::number(num));
    if(num)
        ui->pushButton_l41->setEnabled(true);
    _num[7]++;
    calculateMoney();
}

void Menu::on_pushButton_r41_clicked()
{
    int num = ui->label_r42->text().toInt()-1;
    ui->label_r42->setText(QString::number(num));
    if(!num)
        ui->pushButton_r41->setEnabled(false);
    _num[8]--;
    calculateMoney();
}

void Menu::on_pushButton_r42_clicked()
{
    int num = ui->label_r42->text().toInt()+1;
    ui->label_r42->setText(QString::number(num));
    if(num)
        ui->pushButton_r41->setEnabled(true);
    _num[8]++;
    calculateMoney();
}
//第五行
void Menu::on_pushButton_l51_clicked()
{
    int num = ui->label_l52->text().toInt()-1;
    ui->label_l52->setText(QString::number(num));
    if(!num)
        ui->pushButton_l51->setEnabled(false);
    _num[9]--;
    calculateMoney();
}

void Menu::on_pushButton_l52_clicked()
{
    int num = ui->label_l52->text().toInt()+1;
    ui->label_l52->setText(QString::number(num));
    if(num)
        ui->pushButton_l51->setEnabled(true);
    _num[9]++;
    calculateMoney();
}

void Menu::on_pushButton_r51_clicked()
{
    int num = ui->label_r52->text().toInt()-1;
    ui->label_r52->setText(QString::number(num));
    if(!num)
        ui->pushButton_r51->setEnabled(false);
    _num[10]--;
    calculateMoney();
}

void Menu::on_pushButton_r52_clicked()
{
    int num = ui->label_r52->text().toInt()+1;
    ui->label_r52->setText(QString::number(num));
    if(num)
        ui->pushButton_r51->setEnabled(true);
    _num[10]++;
    calculateMoney();
}
//计算金额
int Menu::calculateMoney()
{
   int total = 0;
   for(int i = 1;i<=10;i++){
       total+=_price[i]*_num[i];
       //qDebug()<<"this is "<<i<<"    price: "<<_price[i]<<"    num: "<<_num[i];
   }
   _total = total;
   ui->label_e_2->setText(QString::number(total));
}
//清空购物车
void Menu::on_pushButton_e1_2_clicked()
{
    ui->label_l12->setText("0");
    ui->label_r12->setText("0");
    ui->label_l22->setText("0");
    ui->label_r22->setText("0");
    ui->label_l32->setText("0");
    ui->label_r32->setText("0");
    ui->label_l42->setText("0");
    ui->label_r42->setText("0");
    ui->label_l52->setText("0");
    ui->label_r52->setText("0");
    ui->label_e_2->setText("0");
    start();
}
//订单生成
void Menu::on_pushButton_e1_clicked()
{
    if(_total == 0)
         QMessageBox::about(this,tr("提示信息"),tr("您未点菜~"));
    else
    {
        this->hide();
        _order = new Order(ui->label_e_0->text(),_num,_price,_total);
        _order->show();
        //当订单_order关闭时，重新让父窗口menu show出来
        connect(_order,SIGNAL(exitChild()),this,SLOT(show()));
    }
}
