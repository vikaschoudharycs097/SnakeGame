#ifndef POINT_H
#define POINT_H

// Structure to represesnt a point in 2-D
template<class T> 
struct Point
{
    T x;
    T y;

    // Constructor
    Point():x (0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    // Operator Overloading
    bool operator ==(const Point &p)
    {
        return x == p.x && y == p.y;
    }

    bool operator !=(const Point &p)
    {
        return !(*this == p);
    }
};

#endif