#ifndef TESTSUITE_H
#define TESTSUITE_H 
#include "TestCase.h"
template <typename T, typename F>
class TestSuite {
	char* name;
	TestCase<T,F>* script;
	void RunScripts() const;
	void NewScript();
	
};
#endif
