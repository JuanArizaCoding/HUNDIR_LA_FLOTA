#pragma once
#include "Barco.h"
class Buque :public Barco<char>{
public:
	Buque();
	string getNombre() { return "Buque"; }
};

