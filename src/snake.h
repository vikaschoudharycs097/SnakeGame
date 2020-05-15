#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "point.h"
#include "animal.h"

// Defining Direction enum
enum class MoveDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake: public Animal
{
private:
    std::vector<Point<int>> _body;
    MoveDirection _dir;
    bool _growing{false};
    const int _GRID_X;
    const int _GRID_Y;

public:
    // Constructor
    Snake(Point<double> head, double speed, int grid_x, int grid_y, MoveDirection dir);
    std::vector<Point<int>> getBody(void);
    void update(void);
    void updateHead(void);
    void updateBody(const Point<int> &curr_head, const Point<int> &prev_head);
    void updateDir(MoveDirection _dir);
    bool snakeCell(const Point<int> &p);
    void growBody(void);
    void reset(void);
};

#endif