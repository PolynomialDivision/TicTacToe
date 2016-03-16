#ifndef GAME_H
#define GAME_H

#include "field.h"

class Game
{
public:
    Game();
    int setField(int x,int y);

private:
    int switch_player(int player);
    int player;
    Field* world;
};

#endif // GAME_H
