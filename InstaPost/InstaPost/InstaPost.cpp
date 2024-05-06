#define _CRT_SECURE_NO_WARNINGS
#include "InstaPost.hpp"
#include <iostream>
InstaPost::InstaPost()
{
	likes = 0;
	strcpy(photoPath, "test.txt");
}

InstaPost::InstaPost(const char* description, unsigned likes, const char* photoPath) : likes(likes)
{
	strcpy(this->description, description);
	strcpy(this->photoPath, photoPath);
};


bool InstaPost::printPhoto(std::ostream& os) const
{
	std::ifstream file(photoPath);
	if (!file.is_open()) {
		std::cout << "Can't open file" << std::endl;
		return false;
	}
	while (!file.eof()) {
		const unsigned buffSize = 1024;
		char buff[buffSize];
		file.getline(buff, buffSize);
		if (!file.good()) {
			return false;
		}
		std::cout << buff << std::endl;
	}
	file.close();
}

void InstaPost::like()
{
	likes++;
}

std::ostream& operator<<(std::ostream& file, const InstaPost& instaPost)
{
	instaPost.printPhoto(file);
	std::cout << instaPost.likes << std::endl << instaPost.description << std::endl;
	return file;
}