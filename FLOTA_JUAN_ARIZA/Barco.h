#pragma once
#include "Casilla.h"
template <class T> class Barco{
protected:
	T tipo_barco; //Lo usaremos como string e int
	int num_casillas;
	int casillas_vivas;
	Casilla* casillas;
public:
	Barco();
	Barco(T,int,int);
	Barco(const Barco<T>&);	
	Barco& operator=(const Barco<T>&op_dcha) {
		tipo_barco = op_dcha.tipo_barco;
		casillas_vivas = op_dcha.casillas_vivas;
		num_casillas = op_dcha.num_casillas;
		casillas = new Casilla[num_casillas];
		for (int i = 0; i < num_casillas; i++) { casillas[i] = op_dcha.casillas[i]; }
		return *this;
	}
	void changeNumCasVivas(int);
	bool asignaCasillas();
	void casillaMenos(); //No puedo hacer sobrecarga del -- ya que usaré un array de barcos y no es modificable
	bool existeCasInBoat(Fila, int)const;
	bool casIn()const; //Mira que las casillas sean horizontales o verticales y que no se salgan del tablero
	Casilla getCasilla(int)const;
	T getTipoBarco() { return tipo_barco; }
	void cambiarPosCasilla(int, int); 
	int getCasillaViva() { return casillas_vivas; }
	void mostrarCasillas();
	virtual string getNombre() = 0;
	Fila convertToFila(int);
	int convertToInt(Fila);
	bool printX(Fila,int)const;
	virtual~Barco();
};

template <class T> Barco<T>::Barco() {
	casillas_vivas = 0;
	num_casillas = 0;
	casillas = new Casilla[num_casillas];
}

template <class T> Barco<T>::Barco(T typeB, int cas,int viva) {
	tipo_barco = typeB;
	num_casillas = cas;
	casillas_vivas = viva; //Al principio tendrá todas vivas
	casillas = new Casilla[num_casillas]; 
}

template <class T>Barco<T>::Barco(const Barco<T>& orig) {
	tipo_barco = orig.tipo_barco;
	casillas_vivas = orig.casillas_vivas;
	num_casillas = orig.num_casillas;
	casillas = new Casilla[num_casillas];
	for (int i = 0; i < num_casillas; i++) { casillas[i] = orig.casillas[i]; }
}

template <class T>void Barco<T>::changeNumCasVivas(int num) {
	casillas_vivas = num;
}


template <class T> bool Barco<T>::asignaCasillas() {
	bool cond = true;
	char opt;
	cout << "Vertical [V] u horizontal [H]: ";
	cin >> opt;
	cin >> casillas[0];
	if (opt == 'V') {
		int fila = convertToInt(casillas[0].getFila());
		for (int i = 1; i < num_casillas; i++) {
			casillas[i] = Casilla(convertToFila(fila + i), casillas[0].getColumna());
		}
	}
	else if (opt == 'H') {
		for (int i = 1; i < num_casillas; i++) {
			casillas[i] = Casilla(casillas[0].getFila(), casillas[0].getColumna() + i);
		}
	}
	else {
		cout << "Opcion introducida no valida\n";
		cond = false;
	}
	casillas_vivas = num_casillas;
	return cond;
}

template <class T> void Barco<T>::casillaMenos() {
	if (casillas_vivas > 0) {
		casillas_vivas--;
	}
}

template <class T> bool Barco<T>::casIn()const{
	bool cond = true;
	for (int i = 0; i < casillas_vivas; i++) {
		if (!casillas[i].isIn()) { cond = false; }
	}
	return cond;
}

template <class T> bool Barco<T>::existeCasInBoat(Fila i,int j)const {
	bool cond=false;
	for (int k = 0;  k< casillas_vivas; k++) {
		if (casillas[k] == Casilla(i,j)) {
			cond = true;
		}
	}
	return cond;
}
template <class T> Casilla Barco<T>::getCasilla(int index)const {
	Casilla myCas;
	if (index < 0 || index >=casillas_vivas) {
		cout << "Indice no valido, vuelva a introducir uno nuevo\n";
	}
	else {
		myCas = casillas[index];
	}
	return myCas;
}

template <class T> void Barco<T>::mostrarCasillas() {
	for (int i = 0; i < casillas_vivas; i++) {
		cout << casillas[i];
	}
}

template <class T> void Barco<T>::cambiarPosCasilla(int p, int end_p) {
	//Cambio la casilla p por la casilla de la posición final (me servirá para simular una eliminación)
	Casilla aux;
	aux=casillas[p];
	casillas[p] = casillas[end_p];
	casillas[end_p] = aux;
}

template <class T> int Barco<T>::convertToInt(Fila myFila) {
	int num;
	switch (myFila) {
	case Fila::A:
		num = 0;
		break;
	case Fila::B:
		num = 1;
		break;
	case Fila::C:
		num = 2;
		break;
	case Fila::D:
		num = 3;
		break;
	case Fila::E:
		num = 4;
		break;
	case Fila::F:
		num = 5;
		break;
	case Fila::G:
		num = 6;
		break;
	case Fila::H:
		num = 7;
		break;
	case Fila::I:
		num = 8;
		break;
	case Fila::J:
		num = 9;
		break;
	default:
		num = 10;
	}
	return num;
}

template <class T> Fila Barco<T>::convertToFila(int num) {
	Fila myFila;
	switch (num) {
	case 0:
		myFila = Fila::A;
		break;
	case 1:
		myFila = Fila::B;
		break;
	case 2:
		myFila = Fila::C;
		break;
	case 3:
		myFila = Fila::D;
		break;
	case 4:
		myFila = Fila::E;
		break;
	case 5:
		myFila = Fila::F;
		break;
	case 6:
		myFila = Fila::G;
		break;
	case 7:
		myFila = Fila::H;
		break;
	case 8:
		myFila = Fila::I;
		break;
	case 9:
		myFila = Fila::J;
		break;
	default:
		myFila = Fila::BAD;
	}

	return myFila;
}

template <class T> bool Barco<T>::printX(Fila fil,int col)const{
	bool cond = false;
	for (int i = 0; i < num_casillas; i++) {
		if (casillas[i]==Casilla(fil,col)) {
			cond = true; 
			break;
		}
	}
	return cond;
}

template <class T> Barco<T>::~Barco() {
	delete[] casillas;
}