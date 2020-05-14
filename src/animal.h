#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>
#include "point.h"

class Animal
{
private:
    double _speed;
    bool _alive{true};

protected:
    Point<double> _head;

public:
    Animal(Point<double> head, double speed);

    // Getters
    Point<double> getHead(void);
    double getSpeed(void);
    bool isAlive(void);

    // Setters
    void setHead(Point<double> head);
    void setSpeed(double new_speed);
    void setAlive(bool alive);

    // Update functions 
    virtual void updateHead() = 0;
    void updateSpeed(double increment);
};

#endif