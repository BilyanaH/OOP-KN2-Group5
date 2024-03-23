#define _CRT_SECURE_NO_WARNINGS
#include "UserInfo.h"
#include <iostream>

UserInfo::UserInfo() :name(nullptr), password(nullptr) {}

UserInfo::UserInfo(const UserInfo& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);
}

UserInfo::UserInfo(const char* name) : password(nullptr)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

UserInfo::UserInfo(const char* name, const char* pass)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->password = new char[strlen(pass) + 1];
	strcpy(this->password, pass);
}

char* UserInfo::getUsername() const
{
	if (name != nullptr)
		return name;
	return (char*)"null";

}

char* UserInfo::getPassword() const
{
	if (password != nullptr)
		return password;
	return (char*)"null";
}