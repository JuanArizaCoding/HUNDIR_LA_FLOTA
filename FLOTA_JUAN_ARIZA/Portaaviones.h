#pragma once
#include "Barco.h"
#include "Casilla.h"
class Portaaviones :public Barco<char>{
public:
	Portaaviones();
	string getNombre() { return" Portaaviones"; }
};
