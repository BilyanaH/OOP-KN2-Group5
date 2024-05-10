#include <iostream>
#include "Semaphore.h"

int main() {
    // Example usage
    Semaphore semaphore(true);
    std::cout << "Semaphore is available: " << semaphore.isAvailable() << std::endl;
    semaphore.wait();
    std::cout << "Semaphore is available: " << semaphore.isAvailable() << std::endl;
    semaphore.signal();
    std::cout << "Semaphore is available: " << semaphore.isAvailable() << std::endl;

    return 0;
}