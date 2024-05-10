#ifndef COUNTER_H
#define COUNTER_H
class Counter{
protected:
	unsigned initial;
	unsigned step;
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);
	virtual void increment();
	virtual unsigned getTotal()const;
	virtual unsigned getStep()const;
};
#endif
