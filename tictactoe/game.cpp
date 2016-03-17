#include "game.h"
#include <iostream>

Game::Game()
{
   world = new Field();
   player = 1;
}

void Game::resetFields(void){
    world->reset_field();
}

int Game::setField(int x,int y){
    int tmp = player;
    int err = world->set_field(x,y,player);

    if(err == -1){
        return 0;
    }

    if(world->player_win(player)){
        return -1*player;
    } else {
        player = switch_player(player);
        return tmp;
    }
}

int Game::switch_player(int player){
    if(player == 1){
        return 2;
    } else {
        return 1;
    }
}
