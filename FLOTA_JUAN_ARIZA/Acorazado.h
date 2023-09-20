#pragma once
#include "Barco.h"
class Acorazado :public Barco<char>{
public:
	Acorazado();
	string getNombre() { return "Acorazado"; }
};

