#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include "LimitedTwowayCounter.h"
class Semaphore : public LimitedTwowayCounter {
public:
	Semaphore();
	Semaphore(bool flag);
	bool isAvailable() const;
	void wait();
	void signal();
};
#endif
