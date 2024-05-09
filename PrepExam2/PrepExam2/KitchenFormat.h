#ifndef KITCHENFORMAT_H
#define KITCHENFORMAT_H
#include "TVFormat.h"
class KitchenFormat :public TVFormat {
	static const int NUM_PARTICIPANTS = 12;
	unsigned* team1IDs[NUM_PARTICIPANTS / 2];
	unsigned* team2IDs[NUM_PARTICIPANTS / 2];
	unsigned NumTeam1 = 0, NumTeam2 = 0;
	Person* FindPersonWithId(unsigned* id);

public:
	KitchenFormat(Person** participants,  unsigned** team1,  unsigned** team2);
	void doEvent() override;
};
#endif