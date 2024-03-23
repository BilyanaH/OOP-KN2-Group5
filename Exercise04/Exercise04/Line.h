#ifndef LINE_H
#define LINE_H
#include "Point.h"

class Line {
private:
	Point p1;
	Point p2;
public:
	Line();
	Line(Point p1, Point p2);
	double Length() const;
};

#endif 