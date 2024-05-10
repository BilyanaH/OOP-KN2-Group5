#ifndef TWOWAYCOUNTER_H
#define TWOWAYCOUNTER_H
#include "Counter.h"
class TwowayCounter : virtual public Counter{
public:
	virtual void decrement();
};
#endif
