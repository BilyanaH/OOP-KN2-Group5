#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point();
	Point(double x, double y);
	double GetX ()const;
	double GetY ()const;
	double Distance(const Point& other) const;
private:
	double x, y;
};
#endif 
