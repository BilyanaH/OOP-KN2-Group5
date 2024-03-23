#include <iostream>
#include "complexNumber.hpp"
#include "student.hpp"
#include "quadraticEquation.hpp"
#include "triangles.hpp"

int main() {
	//1
	ComplexNumber a = ComplexNumber();
	a.img = 1;
	a.real = 1.5;
	ComplexNumber b = ComplexNumber();
	b.img = 1;
	b.real = 1.5;
	(a.Sum(b)).Print();
	//2
	Student student = Student();
	student.initStudent();
	student.Print();
	delete[] student.facNum;
	//3, 4
	Group group = Group();
	group.AddStudents();
	/*
	6
12345
2
4.5
55555
1
5
99999
2
6
44444
4
4
33333
3
3
11111
1
4.5
4.5
	*/
	std::cout << group.average << std::endl;
	std::cout << group.ScholarShip(4.5) << std::endl;
	for (int i = 0; i < group.n; i++)
	{
		delete[] group.students[i].facNum;
	}
	//5
	Triangles triangles = Triangles();
	triangles.n = 3;
	std::cout << std::endl;
	for (int i = 0; i < triangles.n; i++)
	{
		triangles.triangles[i] = Triangle();
		std::cin >> triangles.triangles[i].x1 >> triangles.triangles[i].y1
			>> triangles.triangles[i].x2 >> triangles.triangles[i].y2
			>> triangles.triangles[i].x3 >> triangles.triangles[i].y3;
	}
	triangles.Sort();
	delete[] triangles.triangles;
	//6	
	QuadraticEquation equation = QuadraticEquation();
	equation.a = 2;
	equation.b = 11;
	equation.c = 5;
	double x1 = NULL, x2 = NULL;
	equation.Solve(x1, x2);
	std::cout << std::endl << x1 << " " << x2;
}