#pragma once
#include "Pair.h"
class StringPair:public Pair<char*> {
public:
	StringPair(const char* key, char* value) :Pair(key, value) {};

};
