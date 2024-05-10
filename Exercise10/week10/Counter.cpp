#include "Counter.h"

Counter::Counter()
{
	initial = 0;
	step = 1;
}

Counter::Counter(int initial)
{
	this->initial = initial;
	step = 1;
}

Counter::Counter(int initial, unsigned step)
{
	this->step = step;
	this->step = step;
}

void Counter::increment()
{
	initial += step;
}

unsigned Counter::getTotal() const
{
	return initial;
}

unsigned Counter::getStep() const
{
	return step;
}
