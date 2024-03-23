#include "dynamic.h"
#include <iostream>

// allocate the memory
void Dynamic::allocateMemory()
{
	array = new int[capacity];
}

// delete the allocated memory
void Dynamic::freeMemory()
{
	if (array == nullptr) return;
	std::cout << array;
	delete[] array;
	array = nullptr;
	size = 0;
	capacity = 3;
}

// reallocate memory with different capacity
bool Dynamic::reallocateMemory(size_t newCapacity)
{
	int* newArray = new int[newCapacity];
	if (newArray) {
		if (size > 0) {
		for (size_t i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		delete[] array;
		}
		capacity = newCapacity;
		array = newArray;
		return true;
	}
	return false;
}

// resize the array, if necessary
// double the size
bool Dynamic::resize()
{
	if (size >= capacity) {
		capacity = capacity * 2;
		return reallocateMemory(capacity);
	}
	if (size * 4 < capacity) {
		capacity = capacity * 1 / 2;
		return reallocateMemory(capacity);
	}
	return false;
}

// add element at the end of the array
// if the size is less than the capacity, the array should be resized
// resize the array, if necessary
bool Dynamic::addElement(int newElem)
{
	if (size >= capacity) {
		if (!resize()) {
			return false;
		}
	}
	array[size++] = newElem;
	return true;
}

// add element at a specified position of the array
// resize if necessary
bool Dynamic::addElement(int newElem, size_t position)
{
	if (position > size) return false;
	if (size >= capacity) {
		resize();
	}
	for (size_t i = size; i > position; --i) {
		array[i] = array[i - 1];
	}
	array[position] = newElem;
	++size;
	return true;
}

// print the elements of the array
void Dynamic::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << " " << array[i];
	}
	std::cout << std::endl;
}

// remove the element at the specified position
// if the number of elements are less than 1/4 of the capacity,
// resize the array, use half of its capacity
bool Dynamic::removeElement(size_t position)
{
	if (position >= size) return false;
	for (size_t i = position; i < size - 1; ++i) {
		array[i] = array[i + 1];
	}
	--size;
	if (size <= capacity / 4) {
		resize();
	}
	return true;
}

int Dynamic::getCapacity() const
{
	return capacity;
}

int Dynamic::getSize() const
{
	return size;
}

bool Dynamic::isEmpty()
{
	if (size == 0) return true;
	return false;
}

int Dynamic::getAt(int position)
{
	return array[position];
}

int Dynamic::getFirst()
{
	return array[0];
}

int Dynamic::getLast()
{
	return array[size-1];
}

void Dynamic::assign(int n, int x)
{
	freeMemory();	
	capacity = 2;	
	size = n;

	while (size > capacity) {
		capacity *= 2;
	}
	array = new int[capacity];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = x;
	}

}
void Dynamic::pushBack(int element)
{
	addElement(element);
}

void Dynamic::popBack()
{
	removeElement(size - 1);
}

void Dynamic::removeAt(int position)
{
	removeElement(position);
}
