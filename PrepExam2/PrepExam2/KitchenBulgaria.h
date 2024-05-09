#ifndef KITCHENBULGARIA_H
#define KITCHENBULGARIA_H
#include "KitchenFormat.h"
#include "TVFormat.h"

template <typename T>
class KitchenBulgaria :public KitchenFormat {
	T hiddenChallenge;
public: 
	KitchenBulgaria(Person** participants, unsigned** team1, unsigned** team2, T hiddenChallenge)
		:KitchenFormat(participants, team1, team2), hiddenChallenge(hiddenChallenge) {}
	void printFormatInformation() const override{
		TVFormat::printFormatInformation();
		std::cout << "Hidden Challenge: " << hiddenChallenge << std::endl;
	}
};

#endif 
