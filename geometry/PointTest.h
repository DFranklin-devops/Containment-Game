// PointTest.h
#ifndef POINTTEST_H
#define POINTTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <math.h>
#include "point.h"

class PointTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( PointTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testSet );
  CPPUNIT_TEST( testOpEquals );
  CPPUNIT_TEST( testDistance );
  CPPUNIT_TEST( testCrossProduct );
  CPPUNIT_TEST( testInOrOut );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testSet();
  void testDistance();
  void testCrossProduct();
  void testInOrOut();
  void testOpEquals();

private:
    double ax=1.0;
    double ay=1.0;
    double bx=4.0;
    double by=2.0;
    double cx=2.0;
    double cy=7.0;
    double ab_dist = sqrt( (bx-ax)*(bx-ax) + (by-ay)*(by-ay));
    double ac_dist = sqrt( (cx-ax)*(cx-ax) + (cy-ay)*(cy-ay));
    double bc_dist = sqrt( (bx-cx)*(bx-cx) + (by-cy)*(by-cy));
    double a_cross_b = ax*by - ay*bx;
    double b_cross_a = bx*ay - by*ax;
    double a_cross_c = ax*cy - ay*cx;
    double c_cross_a = cx*ay - cy*ax;
    double b_cross_c = bx*cy - by*cx;
    double c_cross_b = cx*by - cy*bx;

};

#endif  // POINTTEST_H
