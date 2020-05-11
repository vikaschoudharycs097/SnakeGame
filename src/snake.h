#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "point.h"

// Defining Direction enum
enum class MoveDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake
{
private:
    const int _GRID_COUNT_X;
    const int _GRID_COUNT_Y;
    Point<double> _head;
    double _speed;
    MoveDirection _dir;
    std::vector<Point<int>> _body;
    bool _alive{true};
    bool _growing{false};

public:
    // Constructor
    Snake(int grid_count_x, int grid_count_y, const Point<double> &head, double speed, MoveDirection dir);
    void update(void);
    void updateHead(void);
    void updateBody(const Point<int> &curr_head, const Point<int> &prev_head);
    void updateDir(MoveDirection _dir);
    bool isAlive(void);
    bool snakeCell(const Point<int> &p);
    const Point<double> &getHead(void);
    const std::vector<Point<int>> &getBody(void);
    void updateSpeed(double increment);
    void growBody(void);
};

#endif