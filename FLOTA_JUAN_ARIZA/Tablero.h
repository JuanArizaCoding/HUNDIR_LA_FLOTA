#pragma once
#include "Jugador.h"
#include "Casilla.h"

class Tablero{
public:
	Tablero();
	void pintarTablero(Jugador);
	void printCasillasFila(Jugador,Fila);
};

