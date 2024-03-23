#ifndef TIMESPAN_H
#define TIMESPAN_H
class Timestamp {
private:
	unsigned hours;
	unsigned minutes;
	unsigned seconds;
public:
	Timestamp(int sec);
	void Print() const;
	void Add(Timestamp timestamp);
	int ToSeconds() const;
};
#endif