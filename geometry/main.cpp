#include <math.h>
#include <stdio.h>
#include <iostream>
#include "point.h"
using namespace std;

main()
{
    Point a(1.0, 1.0);
    Point b(4.0, 2.0);
    Point c(2.0, 7.0);
    Point t1(2.0, 3.0); // this is bounded by triangle abc
    Point t2(1.5, 5.0); // this is outside of triangle abc

    double x = a.getX();
    double dist = a.distance(b);
    double xprod = b.crossProd(c);
    printf("X = %f, DIST = %f, XPROD = %f\n", x, dist, xprod);
    return 0;
}
