#include "InstaProfile.hpp"
const int DEFAULT_SIZE = 10;
InstaProfile::InstaProfile()
{
	strcpy(username, "UserName");
	size = DEFAULT_SIZE;
	posts = new InstaPost*[size];
	for (size_t i = 0; i < size; i++)
	{
		posts[i] = nullptr;
	}
}

InstaProfile::InstaProfile(const InstaProfile& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(this->username, other.username);
	size = other.size;
}

InstaProfile& InstaProfile::operator=(const InstaProfile& other)
{
	if (this != &other) {
		size = other.size;
		if (strlen(username) < strlen(other.username)) {
			delete[] username;
			username = new char[strlen(other.username) + 1];
		}
		strcpy(this->username, other.username);
		delete[] posts;
		posts = new InstaPost*[size];
		for (int i = 0; i < size; i++)
		{
			posts[i] = new InstaPost(*other.posts[i]);
		}
	}
	return *this;
}

InstaProfile::~InstaProfile()
{
	delete[] username;
	for (size_t i = 0; i < size; i++)
	{
		delete posts[i];
	}
	delete[] posts;
}

InstaProfile::InstaProfile(InstaProfile&& other)
{
	username = other.username;
	posts = other.posts;
	size = other.size;
	other.size = 0;
	other.posts = nullptr;
	other.username = nullptr;
}

InstaProfile& InstaProfile::operator=(InstaProfile&& other)
{
	if (this != &other) {
		delete[] username;
		delete[] posts;
		username = other.username;
		posts = other.posts;
		size = other.size;
		other.username = nullptr;
		other.posts = nullptr;
		other.size = 0;

	}
	return *this;
}

void InstaProfile::operator+=(const InstaPost post)
{
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) {
			posts[i] = post;
		}
		if (isEmpty(i)) {
			posts[i] = post;
		}
	}
}

InstaPost InstaProfile::operator[](int index) const
{
	if (isEmpty(index)) {
		throw std::exception("Error");
	}
	return posts[index];
}

bool InstaProfile::isEmpty(int index) const
{
	if (posts[index]==nullptr) {
	return true;
	}
}
