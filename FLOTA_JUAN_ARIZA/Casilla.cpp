#include "Casilla.h"

Casilla::Casilla() {
	fila = A;
	columna = 0;
}

Casilla::Casilla(Fila myFila,int myCol) {
	fila = myFila;
	columna = myCol;
}

istream& operator>>(istream& is, Casilla& cas) {
	char aux;
	cout << "Introduzca fila (A-J): ";
	is >> aux;
	switch (aux) {
	case 'A':
		cas.fila = Fila::A;
		break;
	case 'B':
		cas.fila = Fila::B;
		break;
	case 'C':
		cas.fila = Fila::C;
		break;
	case 'D':
		cas.fila = Fila::D;
		break;
	case 'E':
		cas.fila = Fila::E;
		break;
	case 'F':
		cas.fila = Fila::F;
		break;
	case 'G':
		cas.fila = Fila::G;
		break;
	case 'H':
		cas.fila = Fila::H;
		break;
	case 'I':
		cas.fila = Fila::I;
		break;
	case 'J':
		cas.fila = Fila::J;
		break;
	default:
		cas.fila = Fila::BAD;
	}

	cout << "Introduzca columna (0-9): ";
	is >>cas.columna;
	return is;
}

bool Casilla::isIn()const{
	bool cond = false;
	if (fila >= Fila::A && fila <= Fila::J && columna >= 0 && columna <= 9) {cond = true;}
	return cond;
}

bool Casilla::operator==(const Casilla& op_dcha) {
	bool condition = false;
	if (fila == op_dcha.fila && columna == op_dcha.columna) {
		condition = true;
	}
	return condition;
}

ostream& operator<<(ostream& os, const Casilla& myCas) {
	std::cout << "Fila: " << myCas.fila << " Columna: " << myCas.columna;
	return os;
}