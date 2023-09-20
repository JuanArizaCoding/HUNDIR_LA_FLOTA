#pragma once
#include <stdexcept>
using namespace std;

class ExcepcionDisparoNoValido :public out_of_range{
public:
	ExcepcionDisparoNoValido() :out_of_range(" esta fuera del tablero\n") {};
};

