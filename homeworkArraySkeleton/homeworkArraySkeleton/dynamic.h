#ifndef DYNAMIC_H
#define DYNAMIC_H
class Dynamic {
private:
	// dynamically allocated array which can be resized
	int* array{ nullptr };

	// capacity of the array
	size_t capacity = 3;

	// exact number of elements in the array
	size_t size = 0;
public:
	void allocateMemory();
	void freeMemory();
	bool reallocateMemory(size_t newCapacity);
	bool resize();
	bool addElement(int newElem);
	bool addElement(int newElem, size_t position);
	void print();
	bool removeElement(size_t position);

	int getCapacity() const;
	int getSize() const;
	bool isEmpty();
	int getAt(int position);
	int getFirst();
	int getLast();
	void assign(int n, int x);
	void pushBack(int element);
	void popBack();
	void removeAt(int position);
};
#endif