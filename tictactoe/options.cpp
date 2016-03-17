#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_buttonBox_accepted()
{
    this->hide();
}

void Options::on_buttonBox_rejected()
{
    this->hide();
}
