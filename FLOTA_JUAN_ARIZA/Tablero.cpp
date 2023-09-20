#include "Tablero.h"

Tablero::Tablero() {
	//NO HAY NADA QUE INICIALIZAR
}

void Tablero::pintarTablero(Jugador jugador) {
	cout << "   0   1   2   3   4   5   6   7   8   9"<<endl;
	cout << "A  ";
	printCasillasFila(jugador, Fila::A);
	cout << "B  ";
	printCasillasFila(jugador, Fila::B);
	cout << "C  ";
	printCasillasFila(jugador, Fila::C);
	cout << "D  ";
	printCasillasFila(jugador, Fila::D);
	cout << "E  ";
	printCasillasFila(jugador, Fila::E);
	cout << "F  ";
	printCasillasFila(jugador, Fila::F);
	cout << "G  ";
	printCasillasFila(jugador, Fila::G);
	cout << "H  ";
	printCasillasFila(jugador, Fila::H);
	cout << "I  ";
	printCasillasFila(jugador, Fila::I);
	cout << "J  ";
	printCasillasFila(jugador, Fila::J);
}

void Tablero::printCasillasFila(Jugador jugador,Fila i) {
	bool cond;
	for (int j = 0; j < 10; j++) {
		cond = false;
		//Miramos en cada barco si existe essa casilla
		for (int boat = 0; boat < 5; boat++) {
			if (jugador.getBarco(boat)->existeCasInBoat(i, j)) {
				cond = true;
				
				cout << jugador.getBarco(boat)->getTipoBarco();
				break;
			}
		}

		if (!cond) {
		
			cout << "*";
		}

		if (j < 9) {
			cout << "   ";
		}
		else{
			cout << endl;
		}

	}
	
}