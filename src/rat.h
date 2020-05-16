#ifndef RAT_H
#define RAT_H

#include <random>
#include <cstdint>
#include "animal.h"
#include "snake.h"

class Rat: public Animal
{
private:
    double _amount; // It is used for score;
    std::random_device _rd;
    std::mt19937 _mt{_rd()};
    std::uniform_int_distribution<int> _random_x;
    std::uniform_int_distribution<int> _random_y;

public:
    Rat(Point<double> head, int grid_x, int grid_y, double _amount);
    int getAmount(void);
    void setAmount(double amount);
    void updateHead(void);
    void updateAmount(double increment);
    double getX(void);
    double getY(void);
    bool checkCollision(const std::vector<Point<int>> &obstacle);
};

#endif