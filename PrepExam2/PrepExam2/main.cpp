#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
#include "FMIChallenge.h"
#include "KitchenBulgaria.h"
#include "KitchenFormat.h"
#include "TVFormat.h"

int main() {
	/*
	char name1[5] = "Ivan";
	char card1[7] = "123456";
	Person person1(name1, 18, card1, 0.5);
	person1.Print();	
	
	char name2[6] = "Mariq";
	char card2[9] = "12345678";
	Person person2(name2, 19, card2, -0.01);
	person2.Print();
	*/
    Person* participants2[14]{ nullptr };
    for (int i = 0; i < 14; ++i) {
        char name[201] = "Participant ";
        name[12] = 'A' + i;        
        char businessCard[501] = "Business Card";
        participants2[i] = new Person(name, 20 + i, businessCard, 0.5 * i);
    }
    Person* participants[12]{ nullptr };
    for (int i = 0; i < 12; ++i) {
        char name2[201] = "Participant ";
        name2[12] = 'A' + i;
        char businessCard2[501] = "Business Card";
        participants[i] = new Person(name2, 20 + i, businessCard2, 0.5 * i);
    }
    // Create teams for KitchenFormat
    unsigned team1[6];
    unsigned team2[6];
    for (int i = 0; i < 6; ++i) {
        team1[i] = participants[i]->GetId();
        team2[i] = participants[i+6]->GetId();
    }
    unsigned* ptrTeam1[6]{ nullptr };
    unsigned* ptrTeam2[6]{ nullptr };
    for (int i = 0; i < 6; ++i) {
        ptrTeam1[i] = &team1[i];
        ptrTeam2[i] = &team2[i];
    }

    // Create games for FMIChallenge
    char* games[10]{ nullptr};
    for (int i = 0; i < 10; ++i) {
        games[i] = new char[50] {'\0'};
        strcpy(games[i], "Game ");
        games[i][5] = 'A' + i;
    }

    // Create TV formats
    TVFormat* formats[3]{ nullptr };    
    formats[0] = new FMIChallenge(participants2, participants[0], games);
    formats[1] = new KitchenFormat(participants, ptrTeam1, ptrTeam2);
    formats[2] = new KitchenBulgaria<int>(participants, ptrTeam1, ptrTeam2, 42);

    // Execute events and print information
    for (int i = 0; i < 3; ++i) {
        formats[i]->doEvent();
        formats[i]->printFormatInformation();
    }

    // Cleanup
    for (int i = 0; i < 10; ++i) {
        delete[] games[i];
    }

	return 0;
}