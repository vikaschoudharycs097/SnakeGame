#include <iostream>
#include <cmath>
#include "snake.h"
#include "point.h"

Snake::Snake(Point<double> head, double speed, int grid_x, int grid_y, MoveDirection dir):
Animal(head, speed), _GRID_X(grid_x), _GRID_Y(grid_y), _dir(dir)
{

}

// Update the _body and _head of snake according to _speed
void Snake::update()
{
    Point<int> prev_head(static_cast<int>(_head.x), static_cast<int>(_head.y));
    updateHead();
    Point<int> curr_head(static_cast<int>(_head.x), static_cast<int>(_head.y));

    if (prev_head != curr_head)
    {
        updateBody(curr_head, prev_head);
    }
}

// Update the snake direction based on current direction
void Snake::updateDir(MoveDirection new_dir)
{
    if ((_dir == MoveDirection::LEFT || _dir == MoveDirection::RIGHT) && (new_dir == MoveDirection::UP || new_dir == MoveDirection::DOWN))
    {
        _dir = new_dir;
    }
    else if ((_dir == MoveDirection::UP || _dir == MoveDirection::DOWN) && (new_dir == MoveDirection::LEFT || new_dir == MoveDirection::RIGHT))
    {
        _dir = new_dir;
    }
    else 
    {
        std::cout << "Error: Invalid direction based on current direction\n"; 
    }
}

// Updating snake head
void Snake::updateHead(void)
{
    switch(_dir)
    {
        case MoveDirection::UP:
            _head.y -= getSpeed();
            break;
        case MoveDirection::DOWN:
            _head.y += getSpeed();
            break;
        case MoveDirection::LEFT:
            _head.x -= getSpeed();
            break;
        case MoveDirection::RIGHT:
            _head.x += getSpeed();
            break;
    }

    _head.x = fmod(_head.x + _GRID_X, _GRID_X);
    _head.y = fmod(_head.y + _GRID_Y, _GRID_Y);
}

// Update Body
void Snake::updateBody(const Point<int> &curr_head, const Point<int> &prev_head)
{
    if (!(_growing || _body.empty()))
    {
        _body.erase(_body.begin());
    }
    else 
    {
        _growing = false;
    }
    _body.push_back(prev_head);

    for (auto &point: _body)
    {
        if (point == curr_head)
        {
            setAlive(false);
        }
    }
}

// Checking that given cell has part of snake or not
bool Snake::snakeCell(const Point<int> &p)
{
    if (p.x == static_cast<int>(_head.x) && p.y == static_cast<int>(_head.y))
    {
        return true;
    }

    for (auto &point: _body)
    {
        if (point == p)
        {
            return true;
        }
    }
    return false;
}

// Returning body of snake
std::vector<Point<int>> Snake::getBody(void)
{
    return _body;
}

void Snake::growBody(void)
{
    _growing = true;
}