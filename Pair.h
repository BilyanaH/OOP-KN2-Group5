#pragma once
#include <iostream>
template<typename T>
class Pair {
	char* key;
	T value;
public:
	Pair(const char* key, const T value);
	Pair(const char* key, const char* value);
	~Pair();
	Pair(const Pair& other);
	Pair<T>& operator=(const Pair& other);
};

template<typename T>
inline Pair<T>::Pair(const char* key, const T value)
{
	this->key = new char[strlen(key) + 1];
	strcpy(this->key, key);
	this->value = value;
}

template<typename T>
inline Pair<T>::Pair(const char* key, const char* value)
{
	this->key = new char[strlen(key) + 1];
	strcpy(this->key, key);	
	this->value = new char[strlen(value) + 1];
	strcpy(this->value, value);
}

template<typename T>
inline Pair<T>::~Pair()
{
	delete key[];
}


template<typename T>
inline Pair<T>::Pair(const Pair& other)
{

	this->key = new char[strlen(other.key) + 1];
	strcpy(this->key, other.key);
	this->value = other.value;
}

template<typename T>
inline Pair<T>& Pair<T>::operator=(const Pair& other)
{
	if (this != &other) {
		delete[] key;
		strcpy(this->key, other.key);
	}
	return *this;
}
