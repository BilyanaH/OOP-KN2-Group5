#ifndef LIMITEDTWOWAYCOUNTER_H
#define LIMITEDTWOWAYCOUNTER_H
#include "LimitedCounter.h"
#include "TwowayCounter.h"
class LimitedTwowayCounter :public LimitedCounter,public TwowayCounter {
	unsigned min;
public:
	LimitedTwowayCounter(unsigned min, unsigned max);
	LimitedTwowayCounter(unsigned min, unsigned max, int initial);
	LimitedTwowayCounter(unsigned min, unsigned max, int initial, unsigned step);
	void increment() override;
	void decrement() override;
	unsigned getMin() const;

};
#endif
