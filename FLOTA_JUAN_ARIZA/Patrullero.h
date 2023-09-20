#pragma once
#include "Barco.h"
class Patrullero :public Barco<char>{
public:
	Patrullero();
	string getNombre() { return "Patrullero"; }
};

