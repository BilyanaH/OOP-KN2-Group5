#ifndef STUDENT_HPP
#define STUDENT_HPP


struct Student {
	char* facNum;
	int course;
	double grade;
	void Print();
	void initStudent();
};
struct Group
{
	int n;
	Student* students = new Student[n];
	double average;
	void AddStudents();
	void Average();
	int ScholarShip(double min);
};
#endif