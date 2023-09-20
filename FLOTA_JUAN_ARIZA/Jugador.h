#pragma once
#include "Barco.h"
#include "Casilla.h"
#include "Portaaviones.h"
#include "Acorazado.h"
#include "Submarino.h"
#include "Patrullero.h"
#include "Buque.h"
#include "ExcepcionDisparoNoValido.h"
#include "Casilla.h"
#include <windows.h>

class Jugador{
private:
	Barco<char>*barcos[5];
	int num_barcos;
	Casilla casilla_disparada;
	bool isInitialice; //Saber si se han inicializado todos los barcos
public:
	Jugador();
	Jugador(const Jugador&);
	Jugador& operator=(const Jugador&);
	Jugador& operator--(int);
	int getNum_barcos() { return num_barcos; }
	bool isInRestBoats(int,Casilla)const; //Comprueba si está esa casilla en todos los barcos menos en index
	bool casOverBoat(int); 
	int disparar(Jugador*); //Dispara en casilla_disparada al contrincante y le paso el index del barco
	//int convertToInt(Fila);
	//Fila convertToFila(int);
	bool isViva(const Jugador&,int*,int*)const; //Mira a ver si la casilla_disparada del contrincante está viva
	Barco<char>* getBarco(int)const;
	void pintarTablero(); //No la pongo en la clase Tablero porque me da problemas al asociar las 2 clases
	void printCasillasFila(Fila)const;
};

