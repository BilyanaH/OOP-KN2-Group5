#pragma once
#include "DatePair.h"
#include "TimePair.h"
struct TimeDate {
	int minutes;	
	int hours;
	int day;
	int month;
	int year;
};
class DateTimePair :public DatePair, public TimePair {
public:
	DateTimePair(const char* key, int hours, int minutes, int day, int month, int year) :Pair<TimeDate>(key, TimeDate{ minutes, hours, day,  month,  year }), DatePair(key, day, month, year), TimePair(key, hours, minutes) {};

};
