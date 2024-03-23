#include "Line.h"

Line::Line() :p1(Point()), p2(Point(1, 0)) {}

Line::Line(Point p1, Point p2){

	p1 = Point(p1);
	p2 = Point(p2);
}
double Line::Length() const
{
	return p1.Distance(p2);
}


