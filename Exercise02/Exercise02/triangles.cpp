#include "triangles.hpp"
#include <iostream>
#include <cmath>

double Triangle::Area() {
	return   abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2  ;
}
void Triangles::Sort() {
	for (int i = 0; i < n-1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (triangles[j].Area() < triangles[minIndex].Area()) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
		Triangle swap = triangles[i];
		triangles[i] = triangles[minIndex];
		triangles[minIndex] = swap;
		}
	}
	Print();
}
void Triangles::Print() {
	for (int i = 0; i < n; i++)
	{
		std::cout << triangles[i].x1 << " " << triangles[i].y1<<" "
			<< triangles[i].x2 << " " << triangles[i].y2 << " "
			<< triangles[i].x3 << " " << triangles[i].y3<<" "<<triangles[i].Area() << std::endl;
	}
}