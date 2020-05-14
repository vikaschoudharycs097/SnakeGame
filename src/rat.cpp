#include <stdint.h>
#include "rat.h"

Rat::Rat(Point<double> head, int grid_x, int grid_y, int amount):
Animal(head, 0.0), _random_x(0, grid_x - 1), _random_y(0, grid_y - 1), _amount(amount)
{
    updateHead();
}

void Rat::updateHead(void)
{
    _head.x = _random_x(_mt);
    _head.y = _random_y(_mt);
}

// Getters
int Rat::getAmount(void)
{
    return _amount;
}

double Rat::getX(void)
{
    return _head.x;
}

double Rat::getY(void)
{
    return _head.y;
}