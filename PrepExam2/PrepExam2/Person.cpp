#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
#include <cstring>

int Person::nextID = 1;

Person::Person(char* name, unsigned age, char* businessCard, double skills):age(age)
{
	id = nextID++;
	strcpy(this->name, name);
	strcpy(this->businessCard, businessCard);
	if (skills < 0 ) {
		this->skills = 0;
	}
	else if (skills > 1) {
		this->skills = 1;
	}
	else {
		this->skills = skills;
	}
}

void Person::Print() const
{
	std::cout << id << " " << name << " " << age << " " << businessCard << " " << skills<<std::endl;
}

const char* Person::GetName() const
{
	return name;
}
const unsigned Person::GetAge() const
{
	return age;
}
const double Person::GetSkills() const
{
	return skills;
}
const unsigned Person::GetId() const
{
	if(businessCard!=nullptr)
	return id;
}
