#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(unsigned max):Counter()
{
	this->max=max;
}

LimitedCounter::LimitedCounter(unsigned max, int initial):Counter(initial)
{
	this->max = max;
}

LimitedCounter::LimitedCounter(unsigned max, int initial, unsigned step) :Counter(initial, step)
{
	this->max = max;
}

void LimitedCounter::increment()
{
	if (initial+step<=max) {
		Counter::increment();
	}
}

unsigned LimitedCounter::getMax() const
{
	return max;
}
