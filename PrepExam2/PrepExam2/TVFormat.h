#ifndef TVFORMAT_H 
#define TVFORMAT_H 
#include "Person.h"
const int MAX_ARR_SIZE = 1024;
class TVFormat {
protected:
	Person* participants[MAX_ARR_SIZE];
	Person* hostOfTheShow;
	char* events[MAX_ARR_SIZE];
	int numEvents, numParticipants;
public:	
	TVFormat(Person** participants, Person* hostOfTheShow, char** events, const int numParticipants,const int numEventsChild);
	TVFormat(const TVFormat& other);
	TVFormat& operator=(const TVFormat& other);
//	TVFormat(TVFormat&& other);
//	TVFormat& operator=(TVFormat&& other);
	virtual ~TVFormat();
	void showEvents(unsigned limit) const;
	virtual void printFormatInformation() const;
	virtual void doEvent() = 0;
};
#endif
