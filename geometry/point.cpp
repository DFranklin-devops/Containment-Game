#include <iostream>
#include <math.h>
#include "point.h"
using namespace std;

Point::Point(double x, double y) {
    _x = x;
    _y = y;
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

double Point::crossProd(const Point& other) const {
    // Cross product a X b is: ax*by - bx*ay
    return _x*other.getY() - other.getX()*_y;
}

void Point::set(double newx, double newy) {
    _x = newx;
    _y = newy;
}

double Point::distance(const Point& other) const {
    double xt = _x - other.getX();
    double yt = _y - other.getY();
    return sqrt( xt*xt + yt*yt );
}
