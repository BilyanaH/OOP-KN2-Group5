#ifndef FMICHALLENGE_H
#define FMICHALLENGE_H
#include "TVFormat.h"
class FMIChallenge :public TVFormat {
	static const int NUM_PARTICIPANTS = 14;
	static const int NUM_GAMES = 10;
	char* games[NUM_GAMES];
public:
	FMIChallenge(Person** participants, Person* hostOfTheShow, char** games);
	void doEvent() override;


	~FMIChallenge();
	FMIChallenge(const FMIChallenge& other);
	FMIChallenge& operator=(const FMIChallenge& other);
	FMIChallenge(FMIChallenge&& other);
	FMIChallenge& operator=(FMIChallenge&& other);


};
#endif