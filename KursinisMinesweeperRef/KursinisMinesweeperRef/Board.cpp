#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "Board.h"
#include "Input.h"
#include "Output.h"
#include "MinesweeperPlacer.h"

MinesweeperBoard::MinesweeperBoard()
{
    stepsLeft = EDGE * EDGE - MINES;
    memset(visibleTable, '?', sizeof(visibleTable));
    memset(hiddenTable, ' ', sizeof(hiddenTable));
    MinesweeperPlacer::placeMines(mines, hiddenTable);
}

void MinesweeperBoard::enterMove(int* r, int* c)
{
    MinesweeperInput::enterMove(r, c);
}

void MinesweeperBoard::printTable()
{
    MinesweeperOutput::printTable(visibleTable);
}

bool MinesweeperBoard::isInside(int row, int column)
{
    return (row >= 0) && (row < EDGE) &&
        (column >= 0) && (column < EDGE);
}

bool MinesweeperBoard::isMine(int row, int column)
{
    if (hiddenTable[row][column] == 'X')
        return (true);
    else
        return (false);
}

int MinesweeperBoard::scanMinesAround(int row, int column)
{
    int amount = 0;

    if (isInside(row - 1, column) == true)
    {
        if (isMine(row - 1, column) == true)
            amount++;
    }

    if (isInside(row + 1, column + 1) == true)
    {
        if (isMine(row + 1, column + 1) == true)
            amount++;
    }

    if (isInside(row, column + 1) == true)
    {
        if (isMine(row, column + 1) == true)
            amount++;
    }

    if (isInside(row + 1, column) == true)
    {
        if (isMine(row + 1, column) == true)
            amount++;
    }

    if (isInside(row, column - 1) == true)
    {
        if (isMine(row, column - 1) == true)
            amount++;
    }

    if (isInside(row - 1, column + 1) == true)
    {
        if (isMine(row - 1, column + 1) == true)
            amount++;
    }

    if (isInside(row + 1, column - 1) == true)
    {
        if (isMine(row + 1, column - 1) == true)
            amount++;
    }

    if (isInside(row - 1, column - 1) == true)
    {
        if (isMine(row - 1, column - 1) == true)
            amount++;
    }
    return (amount);
}

bool MinesweeperBoard::checkStep(int row, int column)
{
    if (visibleTable[row][column] != '?')
        return (true);

    if (hiddenTable[row][column] == 'X')
    {
        for (int i = 0; i < MINES; i++)
        {
            visibleTable[mines[i][0]][mines[i][1]] = 'X';
        }

        this->printTable();
        std::cout << "\nBOOM! :(" << std::endl;
        return (false);
    }

    else
    {
        int amount = scanMinesAround(row, column);
        visibleTable[row][column] = amount + '0';
        stepsLeft--;

        if (!amount)
        {

            if (isInside(row - 1, column) == true)
            {
                if (isMine(row - 1, column) == false)
                    checkStep(row - 1, column);
            }

            if (isInside(row - 1, column + 1) == true)
            {
                if (isMine(row - 1, column + 1) == false)
                    checkStep(row - 1, column + 1);
            }

            if (isInside(row, column + 1) == true)
            {
                if (isMine(row, column + 1) == false)
                    checkStep(row, column + 1);
            }

            if (isInside(row + 1, column + 1) == true)
            {
                if (isMine(row + 1, column + 1) == false)
                    checkStep(row + 1, column + 1);
            }

            if (isInside(row + 1, column) == true)
            {
                if (isMine(row + 1, column) == false)
                    checkStep(row + 1, column);
            }

            if (isInside(row, column - 1) == true)
            {
                if (isMine(row, column - 1) == false)
                    checkStep(row, column - 1);
            }

            if (isInside(row + 1, column - 1) == true)
            {
                if (isMine(row + 1, column - 1) == false)
                    checkStep(row + 1, column - 1);
            }

            if (isInside(row - 1, column - 1) == true)
            {
                if (isMine(row - 1, column - 1) == false)
                    checkStep(row - 1, column - 1);
            }

        }

        return (true);
    }
}
