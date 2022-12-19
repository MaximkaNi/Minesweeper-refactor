#include <iostream>
#include "Game.h"

MinesweeperGame::MinesweeperGame() : MinesweeperBoard() {}

void MinesweeperGame::play()
{
    while (true)
    {
        int row, column;
        enterMove(&row, &column);

        if (checkStep(row, column) == false)
            break;

        printTable();

        if (!getStepsLeft())
        {
            std::cout << "You won! :)" << std::endl;
            break;
        }
    }
}