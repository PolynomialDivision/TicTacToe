#include "game.h"
#include <iostream>

Game::Game()
{
   world = new Field();
   player = 1;
}

int Game::setField(int x,int y){
    int tmp = player;
    world->set_field(x,y,player);

    if(world->player_win(player)){
        return -1*player;
    } else {
        std::cout << player << std::endl;
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

int main_loop(void){

}
