#ifndef _BOARD_
#define _BOARD_
#include "Header.h"
#include "Minesweeper.h"

class MinesweeperBoard : public Minesweeper
{
private:
    int mines[MINES][2];
    char hiddenTable[EDGE][EDGE];
    char visibleTable[EDGE][EDGE];
    int stepsLeft;

public:
    MinesweeperBoard();
    int getStepsLeft() { return stepsLeft; }
    void enterMove(int* r, int* c);
    void printTable();
    bool isInside(int row, int column);
    bool isMine(int row, int column);
    int scanMinesAround(int row, int column);
    bool checkStep(int row, int column);
};
#endif