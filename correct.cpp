#include "correct.h"
#include "ui_correct.h"

correct::correct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::correct)
{
    ui->setupUi(this);
    f.setPixelSize(36);
    ui->texta->setFont(f);
}

correct::~correct()
{
    delete ui;
}


void correct::on_ok_clicked(){
    close();
}
