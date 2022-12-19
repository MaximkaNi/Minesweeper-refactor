#ifndef _GAME_
#define _GAME_
#include "Board.h"

class MinesweeperGame : public MinesweeperBoard
{
public:
    MinesweeperGame();
    void play();
};
#endif