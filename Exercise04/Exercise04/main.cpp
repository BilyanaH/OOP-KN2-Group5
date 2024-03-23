#include <iostream>
#include "UserInfo.h"
#include "Point.h"
#include "Line.h"
#include "LicenseKey.h"

int main() {
    //1
    UserInfo user1;
    UserInfo user2("username");
    UserInfo user3("username", "password");
    UserInfo user4 = user3;
    std::cout << "User1: " << user1.getUsername() << ", " << user1.getPassword() << std::endl;
    std::cout << "User2: " << user2.getUsername() << ", " << user2.getPassword() << std::endl;
    std::cout << "User3: " << user3.getUsername() << ", " << user3.getPassword() << std::endl;
    std::cout << "User4: " << user4.getUsername() << ", " << user4.getPassword() << std::endl;

    //3 
    Point p1(0, 0);
    Point p2(3, 4);

    Line line(p1, p2);

    std::cout << "Length of the line: " << line.Length() << std::endl;
    //4
    LicenseKey key1(12345678); 
    std::cout << "Activation of key1: " << key1.activate() << std::endl; 

    LicenseKey key2 = key1; 
    std::cout << "Activation of key2: " << key2.activate() << std::endl;
    LicenseKey key3 = key1; 
    std::cout << "Activation of key3: " << key3.activate() << std::endl;
    LicenseKey key4 = key1; 
    std::cout << "Activation of key4: " << key4.activate() << std::endl;
    LicenseKey key5 = key1; 
    std::cout << "Activation of key5: " << key5.activate() << std::endl;

    return 0;
}
