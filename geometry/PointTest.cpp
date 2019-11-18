// PointTest.cpp

//#include "StdAfx.h"
#include <cppunit/config/SourcePrefix.h>
#include "Point.h"
#include "PointTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( PointTest );

void
PointTest::setUp()
{
}

void
PointTest::tearDown()
{
}

void
PointTest::testConstructor()
{
    Point a( ax, ay );
    Point b;

    CPPUNIT_ASSERT_EQUAL( ax, a.getX() );
    CPPUNIT_ASSERT_EQUAL( ay, a.getY() );
    CPPUNIT_ASSERT_EQUAL( 0.0, b.getX() );
    CPPUNIT_ASSERT_EQUAL( 0.0, b.getY() );
}


void
PointTest::testSet()
{
    Point d;
    d.set(bx, cy);

    CPPUNIT_ASSERT_EQUAL( bx, d.getX() );
    CPPUNIT_ASSERT_EQUAL( cy, d.getY() );
}


void
PointTest::testDistance()
{
    const Point a(ax, ay);
    const Point b(bx, by);
    const Point c(cx, cy);
    const Point d(cx, cy); // same as previous

    CPPUNIT_ASSERT_EQUAL( ab_dist, a.distance(b) );
    CPPUNIT_ASSERT_EQUAL( ab_dist, b.distance(a) );
    CPPUNIT_ASSERT_EQUAL( ac_dist, a.distance(c) );
    CPPUNIT_ASSERT_EQUAL( ac_dist, c.distance(a) );
    CPPUNIT_ASSERT_EQUAL( bc_dist, b.distance(c) );
    CPPUNIT_ASSERT_EQUAL( bc_dist, c.distance(b) );
    CPPUNIT_ASSERT_EQUAL( 0.0, d.distance(c) );
    CPPUNIT_ASSERT_EQUAL( 0.0, c.distance(d) );
}


void
PointTest::testCrossProduct()
{
    const Point a(ax, ay);
    const Point b(bx, by);
    const Point c(cx, cy);

    CPPUNIT_ASSERT_EQUAL( a_cross_b, a.crossProd(b) );
    CPPUNIT_ASSERT_EQUAL( b_cross_a, b.crossProd(a) );
    CPPUNIT_ASSERT_EQUAL( a_cross_c, a.crossProd(c) );
    CPPUNIT_ASSERT_EQUAL( c_cross_a, c.crossProd(a) );
    CPPUNIT_ASSERT_EQUAL( b_cross_c, b.crossProd(c) );
    CPPUNIT_ASSERT_EQUAL( c_cross_b, c.crossProd(b) );
}

void
PointTest::testOpEquals()
{
    Point a(ax, ay);
    Point b(bx, by);
    Point c(cx, cy);

    c -= a;
    b += a;
    CPPUNIT_ASSERT_EQUAL( cx-ax, c.getX());
    CPPUNIT_ASSERT_EQUAL( cy-ay, c.getY());
    CPPUNIT_ASSERT_EQUAL( bx+ax, b.getX());
    CPPUNIT_ASSERT_EQUAL( by+ay, b.getY());
    CPPUNIT_ASSERT_EQUAL( ax, a.getX());
    CPPUNIT_ASSERT_EQUAL( ay, a.getY());
    a -= a;
    CPPUNIT_ASSERT_EQUAL( 0.0, a.getX());
    CPPUNIT_ASSERT_EQUAL( 0.0, a.getY());
}

//    Point t1(2.0, 3.0); // this is bounded by triangle abc
//    Point t2(1.5, 5.0); // this is outside of triangle abc
// testing points and traingle bounds should be a different class.
// maybe we add a Triangle class and put some tests in there
// use Barycentric coordinates - see StackExchange "arbitrary point
// lies inside triangle". base everything on point a as frame of reference
void
PointTest::testInOrOut()
{
    Point a(ax, ay);
    Point b(bx, by);
    Point c(cx, cy);
    Point t1(2.0, 3.0); // this is bounded by triangle abc
    Point t2(1.5, 5.0); // this is outside of triangle abc
    Point t3(ax+(bx-ax)/2, ay+(by-ay)/2); // this is on the triangle.
    // use point A as reference
    b-=a;
    c-=a;
    // Three points to try: #1: inside
    t1-=a;
    double b_x_c = b.crossProd(c);

    double omegaA = t1.getX()*(b.getY()-c.getY()) +
                    t1.getY()*(c.getX()-b.getX()) +
                    b_x_c;
    omegaA /= b_x_c;
    double omegaB = t1.crossProd(c) / b_x_c;
    double omegaC = b.crossProd(t1) / b_x_c;
    // if all omegas >0 and <1, it's bounded
    CPPUNIT_ASSERT(omegaA > 0.0 && omegaA < 1.0);
    CPPUNIT_ASSERT(omegaB > 0.0 && omegaB < 1.0);
    CPPUNIT_ASSERT(omegaC > 0.0 && omegaC < 1.0);
    // Second one to try: outside
    t2-=a;
    omegaA = t2.getX()*(b.getY()-c.getY()) +
                    t2.getY()*(c.getX()-b.getX()) +
                    b_x_c;
    omegaA /= b_x_c;
    omegaB = t2.crossProd(c) / b_x_c;
    omegaC = b.crossProd(t2) / b_x_c;
    // if any omegas <0 or >1, the point is uncontained
    CPPUNIT_ASSERT(omegaA < 0.0 || omegaA > 1.0 ||
                   omegaB < 0.0 || omegaB > 1.0 ||
                   omegaC < 0.0 || omegaC > 1.0);

    // Third one to try: on the triangle itself
    // here, one of the omegas (at least) will be 0.0 or 1.0
    t3-=a;
    omegaA = t3.getX()*(b.getY()-c.getY()) +
                    t3.getY()*(c.getX()-b.getX()) +
                    b_x_c;
    omegaA /= b_x_c;
    omegaB = t3.crossProd(c) / b_x_c;
    omegaC = b.crossProd(t3) / b_x_c;
    // if one of the omegas is 0.0 or 1.0 the point is ON the boundary
    CPPUNIT_ASSERT(omegaA == 0.0 || omegaA == 1.0 ||
                   omegaB == 0.0 || omegaB == 1.0 ||
                   omegaC == 0.0 || omegaC == 1.0);
}
