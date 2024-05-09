#define _CRT_SECURE_NO_WARNINGS
#include "FMIChallenge.h"
#include <iostream>

FMIChallenge::FMIChallenge(Person** participants, Person* hostOfTheShow, char** games)
	: TVFormat(participants, hostOfTheShow, new char* [10] {nullptr}, NUM_PARTICIPANTS,0)
{
	if (NUM_PARTICIPANTS != numParticipants) {
		throw std::invalid_argument("Number of participants must be 14");
	}
	for (size_t i = 0; i < NUM_GAMES; i++)
	{
		if (games[i] != nullptr) {
			this->games[i] = new char[MAX_ARR_SIZE];
			strcpy(this->games[i], games[i]);
		}
	}

}

void FMIChallenge::doEvent()
{
	if (games[0] == nullptr) {
		std::cout << "No more games";
		return;
	}
	char* newEvent = new char[MAX_ARR_SIZE];
	strcpy(newEvent, "Game was ");
	strcat(newEvent, games[0]);
	for (size_t i = 0; i < NUM_GAMES; i++)
	{
		games[i] = games[i + 1];
	}
	games[NUM_GAMES - 1] = nullptr;
	events[numEvents++] = newEvent;
	int indexEliminate = 0;
	double ratio = DBL_MAX;
	for (int i = 0; i < NUM_PARTICIPANTS; i++)
	{
		if (participants[i] != nullptr) {
			if (participants[i]->GetSkills() / participants[i]->GetAge() < ratio) {
				ratio = participants[i]->GetSkills() / participants[i]->GetAge();
				indexEliminate = i;
			}
		}
	}
	if (participants[indexEliminate] == nullptr) {
		std::cout << "No more participants";
		return;
	}
	strcat(newEvent, " ");
	strcat(newEvent, participants[indexEliminate]->GetName());
	strcat(newEvent, " was eliminated");
	participants[indexEliminate] = nullptr;

}

FMIChallenge::~FMIChallenge()
{
	for (int i = 0; i < NUM_GAMES; i++) {
		delete[] games[i];
	}
}



FMIChallenge::FMIChallenge(const FMIChallenge& other)
	: TVFormat(other) {
	for (int i = 0; i < NUM_GAMES; i++) {
		if (games[i] == nullptr) {
			throw std::invalid_argument("Number of games must be 10");
		}
		this->games[i] = new char[strlen(other.games[i]) + 1];
		strcpy(this->games[i], other.games[i]);

	}
}

FMIChallenge& FMIChallenge::operator=(const FMIChallenge& other)
{
	if (this != &other) {

	TVFormat::operator=(other);

	// Delete old games
	for (int i = 0; i < NUM_GAMES; i++) {
		delete[] games[i];
	}

	// Copy games from other
	for (int i = 0; i < NUM_GAMES; i++) {
		if (games[i] == nullptr) {
			throw std::invalid_argument("Number of games must be 10");
		}
		this->games[i] = new char[MAX_ARR_SIZE];
		strcpy(this->games[i], other.games[i]);
	}
}
return *this;
}

FMIChallenge::FMIChallenge(FMIChallenge&& other)
	:TVFormat(std::move(other))
{
	for (int i = 0; i < NUM_GAMES; i++) {
		this->games[i] = other.games[i];
		other.games[i] = nullptr;
	}
}

FMIChallenge& FMIChallenge::operator=(FMIChallenge&& other)
{
	if (this != &other) {
		TVFormat::operator=(std::move(other));

		for (size_t i = 0; i < NUM_GAMES; i++)
		{
			delete[] games[i];
		}
		for (int i = 0; i < NUM_GAMES; i++) {
			this->games[i] = other.games[i];
			other.games[i] = nullptr;
		}
	}
	return *this;
}
