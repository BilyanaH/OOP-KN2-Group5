#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "KitchenFormat.h"

Person* KitchenFormat::FindPersonWithId(unsigned* id)
{
	if (id == nullptr)
		return nullptr;

	for (size_t i = 0; i < NUM_PARTICIPANTS; i++)
	{
		if (*id == participants[i]->GetId()) {
			return participants[i];
		}
	}
}

KitchenFormat::KitchenFormat(Person** participants, unsigned** team1, unsigned** team2)
	:TVFormat(participants, nullptr, new char* [NUM_PARTICIPANTS] {nullptr}, NUM_PARTICIPANTS, 0) {
	bool mask[NUM_PARTICIPANTS]{ false };
	for (size_t i = 0; i < NUM_PARTICIPANTS / 2; i++)
	{
		for (size_t j = 0; j < NUM_PARTICIPANTS; j++)
		{
			if (team1[i] != nullptr && *team1[i] == participants[j]->GetId()) {
				if (mask[j]) {
					throw std::invalid_argument("Invalid team1");
				}
				else {
					mask[j] = true;
					team1IDs[i] = team1[i];
					NumTeam1++;
				}

			}
			if (team2[i] != nullptr && *team2[i] == participants[j]->GetId()) {
				if (mask[j]) {
					throw std::invalid_argument("Invalid team2");
				}
				else {
					mask[j] = true;
					team2IDs[i] = team2[i];
					NumTeam2++;
				}

			}
		}
	}

}

void KitchenFormat::doEvent()
{	
	char* newEvent = new char[MAX_ARR_SIZE] {'\0'};
	int indexToEliminate = -1;
	double minSkills =2;
	if (NumTeam1 == 0 && NumTeam2 == 0) {
		throw std::invalid_argument("No more participants");
	}
	else if (NumTeam1 <= NumTeam2) {
		for (size_t i = 0; i <NumTeam1 ; i++)
		{
			if (FindPersonWithId(team1IDs[i])->GetSkills() < minSkills) {
				minSkills = FindPersonWithId(team1IDs[i])->GetSkills();
				indexToEliminate = i;
				strcpy(newEvent, FindPersonWithId(team1IDs[i])->GetName());
			}
		}
		NumTeam1--;
	}
	else {
		for (size_t i = 0; i < NumTeam2 ; i++)
		{
			if (FindPersonWithId(team2IDs[i])->GetSkills() < minSkills) {
				minSkills = FindPersonWithId(team2IDs[i])->GetSkills();
				indexToEliminate = i+6;
				strcpy(newEvent, FindPersonWithId(team2IDs[i])->GetName());
			}
		}
		NumTeam2--;
	}

	strcat(newEvent, " was eliminated");
	participants[indexToEliminate] = nullptr;
	events[numEvents++] = newEvent;
}
