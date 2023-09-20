#pragma once
#include "Barco.h"
class Submarino :public Barco<char>{
public:
	Submarino();
	string getNombre() { return "Submarino"; }
};

