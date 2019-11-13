#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double = 0.0, double = 0.0);
    void set(double, double);
    double getX() const;
    double getY() const;
    double crossProd(const Point& other) const;
    double distance(const Point& other) const;
private:
    double _x, _y;
};

#endif
