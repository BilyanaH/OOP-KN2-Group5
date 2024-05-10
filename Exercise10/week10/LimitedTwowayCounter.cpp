#include "LimitedTwowayCounter.h"

LimitedTwowayCounter::LimitedTwowayCounter(unsigned min, unsigned max):LimitedCounter(max)
{
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(unsigned min, unsigned max, int initial):LimitedCounter(max,initial)
{
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(unsigned min, unsigned max, int initial, unsigned step) :LimitedCounter(max, initial, step)
{
	this->min = min;
}

void LimitedTwowayCounter::increment()
{
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
	if (initial - step >= min) {
		TwowayCounter::decrement();
	}
}

unsigned LimitedTwowayCounter::getMin() const
{
	return min;
}
