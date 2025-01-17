#ifndef INSTAPROFILE_HPP
#define INSTAPROFILE_HPP
#include "InstaPost.hpp"

class InstaProfile {
private:
	char* username;
	InstaPost** posts;
	unsigned size = 0;
public:
	InstaProfile();
	InstaProfile(const InstaProfile& other);
	InstaProfile& operator=(const InstaProfile& other);
	~InstaProfile();
	InstaProfile(InstaProfile&& other);
	InstaProfile& operator=(InstaProfile&& other);
	void operator+=(InstaPost post);
	InstaPost operator[](int index) const;
	bool isEmpty(int index) const;
	InstaProfile(const char* username,const char* fileName, int size);
};
#endif