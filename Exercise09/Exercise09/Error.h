#ifndef ERROR_H
#define ERROR_H 
class Error {
protected:
	char type[5];
	char* message;
	Error();
	~Error();
	Error(const Error& other);
	Error& operator=(const Error& other);
	bool typeError() const;
	bool isThereMessage() const;
	void Print() const;	
	bool addError();

};
#endif
