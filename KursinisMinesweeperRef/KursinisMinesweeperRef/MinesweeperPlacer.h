#ifndef _PLACER_
#define _PLACER_
#include "Header.h"

class MinesweeperPlacer
{
public:
    static void placeMines(int mines[][2], char hiddenTable[][EDGE]);
};
#endif