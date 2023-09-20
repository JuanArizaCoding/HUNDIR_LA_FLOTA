#pragma once
#include "Jugador.h"
#include "Tablero.h"

class Partida{
private:
	bool turno;	
	Jugador j1;
	Jugador j2;
public:
	Partida();
	void getTurno();
	bool iniciar();
	bool isFlotaHundida(Jugador);
	bool isHundido(int, Jugador);
};

