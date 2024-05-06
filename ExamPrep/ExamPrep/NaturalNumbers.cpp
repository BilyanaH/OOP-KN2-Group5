#define _CRT_SECURE_NO_WARNINGS
#include "NaturalNumbers.hpp"
#include<cstring>

void NaturalNumbers::set_name(const char* name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* NaturalNumbers::get_name() const {
	return this->name;
}

void NaturalNumbers::set_numbers(const int* name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const int* NaturalNumbers::get_numbers() const {
	return this->numbers;
}

