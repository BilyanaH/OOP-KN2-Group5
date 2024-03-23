#include "dynamic.h"
#include <iostream>

// dynamic array with a specified capacity and with certain number of elements (size)

// reason why the input argument for the array is of type int*&?
// create a header file with the declarations of the functions,
// move the definitions to a .cpp file
// show how they are used in main.cpp


int main()
{

	Dynamic dynamic = Dynamic();
	dynamic.allocateMemory();

	dynamic.addElement(1);
	dynamic.addElement(2);
	dynamic.addElement(3);

	std::cout << "The capacity of the array is " << dynamic.getCapacity() << std::endl;
	std::cout << "The real count of the elements in the array is " << dynamic.getSize() << std::endl;
	dynamic.print();

	dynamic.addElement(4, 2);

	std::cout << "\nThe capacity of the array is " << dynamic.getCapacity() << std::endl;
	std::cout << "The real count of the elements in the array is " << dynamic.getSize() << std::endl;
	dynamic.print();

	dynamic.removeElement(0);
	dynamic.removeElement(0);
	dynamic.removeElement(0);

	std::cout << "\nThe capacity of the array is " << dynamic.getCapacity()<< std::endl;
	std::cout << "The real count of the elements in the array is " << dynamic.getSize() << std::endl;

	dynamic.print();

	// Additional method calls
	dynamic.assign(5, 10); // Assign 5 elements with value 10
	dynamic.print();

	dynamic.pushBack(1); // Add the size of the array to the end
	dynamic.print();

	dynamic.popBack(); // Remove the last element
	dynamic.print();

	dynamic.removeAt(2); // Remove the element at position 2
	dynamic.print();

	dynamic.freeMemory();
}