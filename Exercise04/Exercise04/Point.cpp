#include "Point.h"
#include <math.h>

Point::Point():x(0), y(0){}

Point::Point(double x, double y):x(x), y(y){}

double Point::GetX() const
{
	return x;
}

double Point::GetY() const
{
	return y;
}

double Point::Distance(const Point& other) const
{
	return sqrt(((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)));
}

