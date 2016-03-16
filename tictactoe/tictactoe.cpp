#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe)
{
    game = new Game();
    ui->setupUi(this);
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::handleClick(int x, int y, QPushButton *field)
{
    int ret = game->setField(x,y);
    switch(ret){
        case -1:
            field->setText("WON!");
            break;
        case -2:
            field->setText("WON!");
            break;
        case 1:
            field->setText("X");
            break;
        case 2:
            field->setText("O");
            break;

    }
}
void TicTacToe::on_Field_0_0_clicked()
{
    handleClick(0,0,ui->Field_0_0);
}

void TicTacToe::on_Field_0_1_clicked()
{
    handleClick(0,1,ui->Field_0_1);

}

void TicTacToe::on_Field_0_2_clicked()
{
    handleClick(0,2,ui->Field_0_2);

}

void TicTacToe::on_Field_1_0_clicked()
{
    handleClick(1,0,ui->Field_1_0);

}

void TicTacToe::on_Field_1_1_clicked()
{
    handleClick(1,1,ui->Field_1_1);

}

void TicTacToe::on_Field_1_2_clicked()
{
    handleClick(1,2,ui->Field_1_2);

}

void TicTacToe::on_Field_2_0_clicked()
{
    handleClick(2,0,ui->Field_2_0);

}

void TicTacToe::on_Field_2_1_clicked()
{
    handleClick(2,1,ui->Field_2_1);

}

void TicTacToe::on_Field_2_2_clicked()
{
    handleClick(2,2,ui->Field_2_2);

}
