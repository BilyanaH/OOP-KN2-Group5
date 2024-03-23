#include "student.hpp"
#include <iostream>

const char* CourseToString(int course) {
	switch (course) {
	case 1: return "first";
	case 2: return "second";
	case 3: return "third";
	case 4: return "forth";
	default: return "Invalid course";
	}
}
void Student::Print() {
	for (int i = 0; i < 5; i++)
	{
		std::cout << facNum[i];
	}
	std::cout << " " << CourseToString(course) << " " << grade;
}
void Student::initStudent() {
	facNum = new char[5];
	for (int i = 0; i < 5; i++)
	{
		facNum[i] = '0';
	}
	course = 1;
	grade = 6;
}

void Group::AddStudents() {
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		students[i] = Student();
		char* facNum = new char[5];
		for (int j = 0; j < 5; j++)
		{
			std::cin >> facNum[j];
		}		
		students[i].facNum=facNum;
		std::cin >> students[i].course;
		std::cin>>students[i].grade;
	}
	Average();
}
void  Group::Average() {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += students[i].grade;
	}
	average = sum / n;
}
int  Group::ScholarShip(double min) {
	int count = 0;
	Student* newStudents = new Student[n];
	for (int i = 0; i < n; i++)
	{
		if (students[i].grade >= min) {			
			for (size_t j = 0; j <= count; j++)
			{	
				if (j == count) {
					newStudents[j] = students[i];
					break;
				}
				if (students[i].grade < newStudents[j].grade) {
					continue;
				}
				for (int k = count+1; k > j; k--)
				{
					newStudents[k] = newStudents[k - 1];
				}
				newStudents[j] = students[i];
				break;
			}	
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << newStudents[i].facNum[j];
		}
		std::cout << std::endl;
	}
	delete[] newStudents;
	return count;
}