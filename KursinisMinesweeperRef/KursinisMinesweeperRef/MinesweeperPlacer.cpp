#include <iostream>
#include "MinesweeperPlacer.h"

void MinesweeperPlacer::placeMines(int mines[][2], char hiddenTable[][EDGE])
{
    srand(time(NULL));
    bool marked[EDGE * EDGE];

    memset(marked, false, sizeof(marked));

    for (int i = 0; i < MINES;)
    {
        int randomNumber = rand() % (EDGE * EDGE);
        int row = randomNumber / EDGE;
        int column = randomNumber % EDGE;

        if (!marked[randomNumber])
        {
            marked[randomNumber] = true;
            hiddenTable[row][column] = 'X';
            mines[i][0] = row;
            mines[i][1] = column;
            i++;
        }
    }
}