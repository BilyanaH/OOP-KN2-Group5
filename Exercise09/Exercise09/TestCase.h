#ifndef TESTCASE_H
#define TESTCASE_H 
#include "Error.h"
template <typename T, typename F>
class TestCase {
	char* name;
	Error error;
	public:
	void assertTrue(bool arg) const;
	void assertEquals(const T& a, const  T& b) const;
	void assertNotNull(F* obj) const;
	bool isTestTrue() const;
	bool areThereErrors() const;
	bool typeError() const;
	void Print() const;
};
#endif
