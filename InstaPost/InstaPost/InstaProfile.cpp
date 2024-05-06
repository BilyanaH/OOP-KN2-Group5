#define _CRT_SECURE_NO_WARNINGS
#include "InstaProfile.hpp"
const int DEFAULT_SIZE = 10;
InstaProfile::InstaProfile()
{
	strcpy(username, "UserName");
	size = DEFAULT_SIZE;
	posts = new InstaPost * [size];
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
	posts = new InstaPost*[size];
	for (int i = 0; i < size; i++)
	{
		posts[i] = new InstaPost(*other.posts[i]);
	}
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
		posts = new InstaPost * [size];
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

void InstaProfile::operator+=( InstaPost post)
{
	//TODO
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) {
			posts[i] = &post;
		}
		if (isEmpty(i)) {
			posts[i] = &post;
			return;
		}
	}
}

InstaPost InstaProfile::operator[](int index) const
{
	if (isEmpty(index)) {
		throw std::exception("Error");
	}
	return *posts[index];
}

bool InstaProfile::isEmpty(int index) const
{
	if (posts[index] == nullptr) {
		return true;
	}
	return false;
}

InstaProfile::InstaProfile(const char* username,const char* fileName, int size)
{ 
	strcpy(this->username, username);
	std::ifstream is(fileName, std::ios::binary);

	if (!is)
	{
		// "Could not open profile file."
		throw new std::exception();
	}

	is.seekg(0, std::ios::end);
	int fileSize = is.tellg();
	is.seekg(0, std::ios::beg);
	this->size = size;
	int fileCount	= fileSize / sizeof(InstaPost);
	if (fileCount < size)
	{
		std::cout << "The number of posts of user " << username << " exceeds the limits of posts.  Number of entries: " << size<<" Number of posts: " << fileCount << std::endl;
	}
	InstaPost* posts = new InstaPost[fileCount];

	is.read((char*)posts, fileCount * sizeof(InstaPost));

	for (size_t i = 0; i <= size; i++)
	{
		this->posts[i] = new InstaPost(posts[i]);
	}
	delete[] posts;

	is.close();
}
