#include "Timestamp.h"
#include <iostream>

Timestamp::Timestamp(int sec)
{
	hours = sec / 3600;
	sec = sec % 3600;
	minutes = sec / 60;
	sec = sec % 60;
	seconds = sec;
}

void Timestamp::Print() const
{
	std::cout << hours << ":" << minutes << ":" << seconds<<std::endl;
}

void Timestamp::Add(Timestamp timestamp)
{
	seconds += timestamp.seconds;
	if (seconds >= 60) {
		seconds -= 60;
		minutes++;
	}
	minutes += timestamp.minutes;
	if (minutes >= 60) {
		minutes -= 60;
		hours++;
	}
	hours += timestamp.hours;

}

int Timestamp::ToSeconds() const
{
	return (hours * 60 + minutes) * 60 + seconds;
}
