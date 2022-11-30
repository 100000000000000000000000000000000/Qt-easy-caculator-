#include "surprise_window.h"
#include "ui_surprise_window.h"
#include "correct.h"
#include "ui_correct.h"
surprise_window::surprise_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::surprise_window)
{
    ui->setupUi(this);
}

surprise_window::~surprise_window()
{
    delete ui;
}



void surprise_window::on_yes_clicked(){
    correct * wd = new correct();
    wd->ui->texta->setText("恭喜你答对了!!!!!!!!!!!!!!");
    wd->show();
}

void surprise_window::on_no_clicked(){
    correct *wd = new correct();
    wd->ui->texta->setText("我劝你思考清楚再做决定哦！！！！！！！！");
    wd->show();
};
