#include "Semaphore.h"

Semaphore::Semaphore() :LimitedTwowayCounter(0, 1, 0, 1)
{
}

Semaphore::Semaphore(bool flag):LimitedTwowayCounter(0, 1, flag, 1)
{
	
}

bool Semaphore::isAvailable() const
{
	return !initial;
}

void Semaphore::wait()
{
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal()
{
	LimitedTwowayCounter::increment();
}
