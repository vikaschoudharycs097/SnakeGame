#include <vector>
#include "point.h"
#include "animal.h"

// Parameterized constructor
Animal::Animal(Point<double> head, double speed):
_head(head), _speed(speed), _alive(true)
{

}

// Getters
Point<double> Animal::getHead(void)
{
    return _head;
}

double Animal::getSpeed(void)
{
    return _speed;
}

bool Animal::isAlive(void)
{
    return _alive;
}

// Setters
void Animal::setHead(Point<double> head)
{
    _head = head;
}

void Animal::setSpeed(double speed)
{
    _speed = speed;
}

void Animal::setAlive(bool alive)
{
    _alive = alive;
}

// Update
void Animal::updateSpeed(double increment)
{
    _speed += increment;
}