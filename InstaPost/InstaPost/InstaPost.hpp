#ifndef INSTAPOST_HPP
#define INSTAPOST_HPP
#include <fstream>
#include <iostream>

const int MAX_DESCRIPTION_SIZE = 1025;
const int MAX_PHOTO_PATH_SIZE = 65;

class InstaPost {
private:
	char description[MAX_DESCRIPTION_SIZE];
	unsigned likes;
	char photoPath[MAX_PHOTO_PATH_SIZE];
public:
	InstaPost();
	InstaPost(const char* description, unsigned likes, const char* photoPath);
	//    void printPhoto(std::ostream &os = std::cout) const;
	bool printPhoto(std::ostream& os) const;
	void like();
	friend std::ostream& operator<< (std::ostream& file, const InstaPost& instaPost);
};
#endif // !INSTAPOST_HPP