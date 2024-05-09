#define _CRT_SECURE_NO_WARNINGS
#include "TVFormat.h"
#include<iostream>

TVFormat::TVFormat(Person** participants, Person* hostOfTheShow, char** events, const int numParticipantsChild, const int numEventsChild)
{
	this->hostOfTheShow = hostOfTheShow;
	this->numEvents = 0;
	this->numParticipants = 0;
	for (int i = 0; i < numParticipantsChild; i++) {
		if (participants[i] != nullptr) {
			this->participants[numParticipants++] = participants[i];
		}
	}
	for (int i = 0; i <= numEventsChild; i++) {
		if (events[i] != nullptr) {
			this->events[numEvents] = new char[MAX_ARR_SIZE];
			strcpy(this->events[numEvents++], events[i]);
		}
	}
}

TVFormat::TVFormat(const TVFormat& other)
{
	numEvents = other.numEvents;
	numParticipants = other.numParticipants;
	hostOfTheShow = new Person(*(other.hostOfTheShow));
	for (size_t i = 0; i < numParticipants; i++)
	{
		participants[i] = new Person(*(other.participants[i]));
	}
	for (size_t i = 0; i < numEvents; i++)
	{
		events[i] = new char[strlen(other.events[i]) + 1];
		strcpy(events[i], other.events[i]);
	}
}

TVFormat& TVFormat::operator=(const TVFormat& other)
{
	if (this != &other) {
		hostOfTheShow = nullptr;
		for (size_t i = 0; i < MAX_ARR_SIZE; i++)
		{
			participants[i] = nullptr;
		}
		for (size_t i = 0; i < MAX_ARR_SIZE; i++)
		{
			delete[] events[i];
		}

		numEvents = other.numEvents;
		numParticipants = other.numParticipants;
		hostOfTheShow = new Person(*(other.hostOfTheShow));
		for (size_t i = 0; i < numParticipants; i++)
		{
			participants[i] = new Person(*(other.participants[i]));
		}
		for (size_t i = 0; i < numEvents; i++)
		{
			events[i] = new char[strlen(other.events[i]) + 1];
			strcpy(events[i], other.events[i]);
		}
	}
	return *this;
}

//TVFormat::TVFormat(TVFormat&& other) : numEvents(other.numEvents), numParticipants(other.numParticipants), hostOfTheShow(other.hostOfTheShow) {
//	for (size_t i = 0; i < numEvents; i++)
//	{
//		events[i] = other.events[i];
//	}
//	for (size_t i = 0; i < numParticipants; i++)
//	{
//		participants[i] = other.participants[i];
//	}
//	other.numEvents = 0;
//	other.numParticipants = 0;
//	other.hostOfTheShow = nullptr;
//	for (size_t i = 0; i < MAX_ARR_SIZE; i++)
//	{
//		other.participants[i] = nullptr;
//		other.events[i] = nullptr;
//	}
//}
//
//TVFormat& TVFormat::operator=(TVFormat&& other)
//{
//	if (this != &other) {
//		other.numEvents = 0;
//		other.numParticipants = 0;
//		other.hostOfTheShow = nullptr;
//		for (size_t i = 0; i < numEvents; i++)
//		{
//			events[i] = other.events[i];
//		}
//		for (size_t i = 0; i < numParticipants; i++)
//		{
//			participants[i] = other.participants[i];
//		}
//		numEvents = other.numEvents;
//		numParticipants = other.numParticipants;
//		hostOfTheShow = other.hostOfTheShow;
//		for (size_t i = 0; i < MAX_ARR_SIZE; i++)
//		{
//			other.participants[i] = nullptr;
//			other.events[i] = nullptr;
//		}
//	}
//	return *this;
//
//}

TVFormat::~TVFormat()
{
	for (size_t i = 0; i < MAX_ARR_SIZE; i++)
	{
		delete[] events[i];
	}
}

void TVFormat::showEvents(unsigned limit) const
{
	if (numEvents == 0) {
		std::cout << "No events" << std::endl;
		return;
	}
	if (limit < numEvents) {
		limit = numEvents;
	}
	for (size_t i = 0; i < limit; i++)
	{
		std::cout << events[i] << " ";
	}
	if (numEvents < limit) {
		std::cout << "No more events";
	}
	std::cout << std::endl;
}

void TVFormat::printFormatInformation() const
{
	if (hostOfTheShow!=nullptr) {
		std::cout << "Host: " << hostOfTheShow->GetName() << std::endl;
	}
	std::cout << "Participants: " << std::endl;
	for (size_t i = 0; i < numParticipants; i++)
	{
		if (participants[i] != nullptr) {
			std::cout << participants[i]->GetName() << std::endl;
		}
	}
}
