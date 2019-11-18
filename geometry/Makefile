#Makefile
CXX = gcc
LDLIBS = -lcppunit -lm -lstdc++
OBJS = Point.o PointTest.o pointapp.o
CPPFLAGS = -g

all : PointTest

PointTest: $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

point.o: Point.h
PointTest.o: Point.h PointTest.h

clean:
	rm *.o $(EXEC)

