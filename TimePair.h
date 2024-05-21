#pragma once
#include "Pair.h"
struct Time {
	int hours;
	int minutes;
};
class TimePair :public virtual Pair<Time> {
public:
	TimePair(const char* key, int hours, int minutes) :Pair(key, Time{ hours,minutes }) {};
};
