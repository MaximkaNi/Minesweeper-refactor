#include <iostream>
#include "Input.h"

void MinesweeperInput::enterMove(int* r, int* c)
{
    std::cout << "Enter row and column:";
    std::cin >> *r >> *c;
}