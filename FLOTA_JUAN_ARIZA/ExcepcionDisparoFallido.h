#pragma once
#include <exception>
using namespace std;

class ExcepcionDisparoFallido :public exception {
public:
	ExcepcionDisparoFallido() :exception() {};
	char*what(){
		return (char*)" es agua\n";
	}
};

