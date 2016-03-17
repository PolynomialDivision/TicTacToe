#include "tictactoe.h"
#include "ui_tictactoe.h"
#include "options.h"

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
        case 0:
            break;
        case -1:
            field->setText("X");
            won('X');
            break;
        case -2:
            field->setText("O");
            won('O');
            break;
        case 1:
            field->setText("X");
            break;
        case 2:
            field->setText("O");
            break;

    }
}

void TicTacToe::won(char winner){
    (void) winner;
    QList<QPushButton *> buttonsList = this->findChildren<QPushButton *>();
    for (int i = 0; i < buttonsList.count(); i++){
        buttonsList.at(i)->setEnabled(false);
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

void TicTacToe::on_actionNew_Game_triggered()
{
    resetGame();
}

void TicTacToe::resetGame(void){

    game->resetFields();

    QList<QPushButton *> buttonsList = this->findChildren<QPushButton *>();
    for (int i = 0; i < buttonsList.count(); i++){
        buttonsList.at(i)->setText("");
        buttonsList.at(i)->setEnabled(true);
    }
}

void TicTacToe::on_actionOptions_triggered()
{
    options = new Options(this);
    options->show();
}
