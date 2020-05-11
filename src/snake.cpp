#include <iostream>
#include <cmath>
#include "snake.h"
#include "point.h"

Snake::Snake(int grid_count_x, int grid_count_y, const Point<double> &head, double speed, MoveDirection dir):
_GRID_COUNT_X(grid_count_x), _GRID_COUNT_Y(grid_count_y), _head(head), _speed(speed), _dir(dir)
{
    int x = static_cast<int>(head.x);
    int y = static_cast<int>(head.y);
    Point<int> p(x, y);

    // Constructing initial body
    switch(_dir)
    {
        case MoveDirection::UP:
            p.y += 1;
            break;
        case MoveDirection::DOWN:
            p.y -= 1;
            break;
        case MoveDirection::LEFT:
            p.x += 1;
            break;
        case MoveDirection::RIGHT:
            p.x -= 1;
            break;
        default:
            break;
    }

    _body.push_back(p);
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
            _head.y -= _speed;
            break;
        case MoveDirection::DOWN:
            _head.y += _speed;
            break;
        case MoveDirection::LEFT:
            _head.x -= _speed;
            break;
        case MoveDirection::RIGHT:
            _head.x += _speed;
            break;
    }

    _head.x = fmod(_head.x + _GRID_COUNT_X, _GRID_COUNT_X);
    _head.y = fmod(_head.y + _GRID_COUNT_Y, _GRID_COUNT_Y);
}

// Update Body
void Snake::updateBody(const Point<int> &curr_head, const Point<int> &prev_head)
{
    if (!_growing)
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
            _alive = false;
        }
    }
}

// Return alive
bool Snake::isAlive(void)
{
    return _alive;
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

// Returning head of snake
const Point<double>& Snake::getHead(void)
{
    return _head;
}

// Returning body of snake
const std::vector<Point<int>>& Snake::getBody(void)
{
    return _body;
}

void Snake::updateSpeed(double increment)
{
    _speed += increment;
}

void Snake::growBody(void)
{
    _growing = true;
}