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
    const int _GRID_X;
    const int _GRID_Y;
    MoveDirection _dir;
    std::vector<Point<int>> _body;
    bool _growing{false};

public:
    // Constructor
    Snake(Point<double> head, double speed, int grid_x, int grid_y, MoveDirection dir);
    std::vector<Point<int>> getBody(void);
    void update(const std::vector<Point<int>> &obstacle);
    void updateHead(void);
    void updateBody(const Point<int> &curr_head, const Point<int> &prev_head);
    void updateDir(MoveDirection _dir);
    bool snakeCell(const Point<int> &p);
    void growBody(void);
    void reset(void);
    void checkCollision(const std::vector<Point<int>> &obstacle);
};

#endif