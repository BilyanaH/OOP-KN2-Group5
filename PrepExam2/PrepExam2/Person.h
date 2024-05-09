#ifndef PERSON_H
#define PERSON_H 
class Person {
	static int nextID;
	unsigned id;
	char name[201];
	unsigned age;
	char businessCard[501];
	double skills;

public:
	Person(char* name, unsigned age, char* businessCard, double skills);
	void Print() const;
	const char* GetName() const;
	const unsigned GetAge() const;
	const double GetSkills() const;
	const unsigned GetId() const;
};	
#endif
