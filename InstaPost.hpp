#ifndef INSTAPOST_HPP
#define INSTAPOST_HPP
#include <fstream>
#include <iostream>
class InstaPost {
private:
	char description[1025];
	unsigned likes;
	char photoPath[65];
public:
	InstaPost();
	InstaPost(char description[1025], unsigned likes, char photoPath[65]);
	bool printPhoto() const;
	void like();
	friend std::ostream& operator<< (std::iostream& file, const InstaPost& instaPost);
};
#endif // !INSTAPOST_HPP
