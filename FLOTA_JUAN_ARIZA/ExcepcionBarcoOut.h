#pragma once
#include <stdexcept>
using namespace std;
class ExcepcionBarcoOut :public out_of_range{
public:
	ExcepcionBarcoOut() :out_of_range("Barco introducido fuera de tablero. Vuelva a introducirlo.\n"){}
};

