#include "food.h"

Food::Food(int x, int y, FoodType food_type):
_pos(x, y), _food_type(food_type)
{
    if (food_type == FoodType::NORMAL)
    {
        _amount = 1;
    }
    else 
    {
        _amount = 5;
    }
}

// Getters
int Food::getX(void)
{
    return _pos.x;
}

int Food::getY(void)
{
    return _pos.y;
}

int Food::getAmount(void)
{
    return _amount;
}

void Food::setX(int x)
{
    _pos.x = x;
}

void Food::setY(int y)
{
    _pos.y = y;
}