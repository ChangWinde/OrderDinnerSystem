#ifndef APPEARANCE_H
#define APPEARANCE_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class Appearance;
}

class Appearance : public QDialog
{
    Q_OBJECT

public:
    explicit Appearance(QWidget *parent = 0);
    ~Appearance();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Appearance *ui;
    Menu *_menu;
};

#endif // APPEARANCE_H
