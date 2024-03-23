#ifndef TRIANGLES_HPP
#define TRIANGLES_HPP
struct Triangle {
	double x1;
	double y1;	
	double x2;
	double y2;	
	double x3;
	double y3;
	double Area();
};
struct Triangles {
	int n;
	Triangle* triangles = new Triangle[n];
	void Sort();
	void Print();
};
#endif // !TRIANGLES_HPP
