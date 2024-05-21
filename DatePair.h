#pragma once
#include "Pair.h"
struct Date {
	int day;
	int month;
	int year;
	Date(int day,int  month, int year);
};
class DatePair :public virtual Pair<Date> {
public:
	DatePair(const char* key, int day, int month, int year) :Pair(key, Date{ day, month,year }) {};

};
