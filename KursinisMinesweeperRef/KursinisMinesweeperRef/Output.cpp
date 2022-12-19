#include <iostream>
#include "Output.h"

void MinesweeperOutput::printTable(char visibleTable[][EDGE])
{
    std::cout << "X ";

    for (int i = 0; i < EDGE; i++)
    {
        if (i == EDGE - 1) std::cout << i << std::endl;
        else std::cout << i << " ";
    }

    for (int i = 0; i < EDGE; i++)
    {
        std::cout << i << " ";

        for (int j = 0; j < EDGE; j++)
            std::cout << visibleTable[i][j] << " ";
        std::cout << std::endl;
    }
}