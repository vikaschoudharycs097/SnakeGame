#ifndef FOOD_H
#define FOOD_H

#include "point.h"

enum class FoodType
{
    NORMAL = 1,
    SUPER = 5
};

class Food
{
private:
    int _amount; // It is used for score;
    Point<int> _pos;
    FoodType _food_type;

public:
    Food(int x, int y, FoodType food_type);
    int getX(void);
    int getY(void);
    int getAmount(void);
    void setX(int x);
    void setY(int y);
};

#endif