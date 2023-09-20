#pragma once
#include <iostream>
using namespace std;
enum Fila { A, B, C, D, E, F, G, H, I, J,BAD};
class Casilla{
private:
	Fila fila;
	int columna;
public:
	Casilla();
	Casilla(Fila, int);
	void changeTocada();
	bool operator==(const Casilla&);
	Fila getFila() { return fila; }
	int getColumna() { return columna; }
	bool isIn()const;
	friend istream& operator>>(istream&,Casilla&); //Metemos datos
	friend ostream& operator<<(ostream&, const Casilla&);
};

