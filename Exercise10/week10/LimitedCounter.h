#ifndef LIMITEDCOUNTER_H
#define LIMITEDCOUNTER_H
#include "Counter.h"
class LimitedCounter :public virtual Counter {
	unsigned max;
public:
	LimitedCounter(unsigned max);
	LimitedCounter(unsigned max, int initial);
	LimitedCounter(unsigned max, int initial, unsigned step);
	void increment() override;
	unsigned getMax() const ;

};
#endif
