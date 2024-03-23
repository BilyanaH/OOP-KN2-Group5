#ifndef USERINFO_H
#define USERINFO_H
class UserInfo {
private:
	char* name;
	char* password;
public:

	UserInfo();
	UserInfo(const UserInfo&  other);
	UserInfo(const char* name);
	UserInfo(const char* name, const char* password);
	char* getUsername() const;
	char* getPassword() const;
};

#endif // !USERINFO.H
