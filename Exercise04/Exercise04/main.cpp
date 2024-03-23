// main.cpp
#include "UserInfo.h"
#include <iostream>

int main() {
    UserInfo user1;
    UserInfo user2("username");
    UserInfo user3("username", "password");
    UserInfo user4 = user3;
    std::cout << "User1: " << user1.getUsername() << ", " << user1.getPassword() << std::endl;
    std::cout << "User2: " << user2.getUsername() << ", " << user2.getPassword() << std::endl;
    std::cout << "User3: " << user3.getUsername() << ", " << user3.getPassword() << std::endl;
    std::cout << "User4: " << user4.getUsername() << ", " << user4.getPassword() << std::endl;

    return 0;
}
