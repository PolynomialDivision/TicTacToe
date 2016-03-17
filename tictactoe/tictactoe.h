#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include "ui_tictactoe.h"
#include "game.h"
#include "options.h"

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();

private slots:
    void on_Field_0_0_clicked();

    void on_Field_0_1_clicked();

    void on_Field_0_2_clicked();

    void on_Field_1_0_clicked();

    void on_Field_1_1_clicked();

    void on_Field_1_2_clicked();

    void on_Field_2_0_clicked();

    void on_Field_2_1_clicked();

    void on_Field_2_2_clicked();

    void on_actionNew_Game_triggered();

    void on_actionOptions_triggered();

private:
    Ui::TicTacToe *ui;
    void handleClick(int,int,  QPushButton *);
    void won(char winner);
    void resetGame(void);

    Options *options;
    Game *game;
};

#endif // TICTACTOE_H
