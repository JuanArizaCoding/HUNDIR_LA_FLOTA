#include "Jugador.h"

Jugador::Jugador() {
	bool cond,cas;
	isInitialice = false;
	barcos[0] = new Acorazado();
	barcos[1] = new Portaaviones();
	barcos[2] = new Patrullero();
	barcos[3] = new Submarino();
	barcos[4] = new Buque();
	num_barcos = 0;

	cout << endl << "NUEVO JUGADOR: INTRODUCIR CASILLAS DE LOS BARCOS" << endl << endl;
	for (int i = 0; i < 5; i++) {
		cond = false;
		pintarTablero();
		switch (i) {
		case 0:
			cout << "Acorazado:" << endl;
			break;
		case 1:
			cout << endl << "Portaaviones:" << endl;
			break;
		case 2:
			cout << endl << "Patrullero:" << endl;
			break;
		case 3:
			cout << endl << "Submarino:" << endl;
			break;
		case 4:
			cout << endl << "Buque:" << endl;
			break;
		}
		cas=barcos[i]->asignaCasillas();
		num_barcos++; //Aumento el numero de barcos de forma dinámica
		if (!cas||!barcos[i]->casIn()) {
			cond = true;
			cout << "Barco introducido fuera de tablero. Vuelva a introducirlo.\n";
		}
		if (casOverBoat(i)) { //Mirará alrededor si el barco está horizontal o vertical
			cout << "El barco introducido esta pegado a otros barcos, vuelva a introducirlo." << endl;
			cond = true;
		}
		if (cond) {
			barcos[i]->changeNumCasVivas(0);
			i--;
			num_barcos--;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	cout << "TABLERO DEL JUGADOR COMPLETADO" << endl << endl;
	isInitialice = true;
	pintarTablero();
	cout << endl;
	system("pause");
	system("cls");
}

Jugador::Jugador(const Jugador& orig) {
	isInitialice = orig.isInitialice;
	num_barcos = orig.num_barcos;
	casilla_disparada = orig.casilla_disparada;
	for (int i = 0; i < 5; i++) {barcos[i] = orig.barcos[i];}
}

Jugador& Jugador::operator=(const Jugador& op_dcha) {
	for (int i = 0; i < 5; i++) { barcos[i] = op_dcha.barcos[i]; }
	casilla_disparada = op_dcha.casilla_disparada;
	return *this;
}

Jugador& Jugador::operator--(int) {
	if (num_barcos > 0) {
		num_barcos--;
	}
	return *this;
}

//Mirar si hay casillas usadas en los bordes del barco-->Lo mira para casos horizontal/vertical
bool Jugador::casOverBoat(int index) {
	int fil, col;
	for (int i = 0; i < barcos[index]->getCasillaViva(); i++) {
		fil=barcos[index]->convertToInt(barcos[index]->getCasilla(i).getFila());
		col = barcos[index]->getCasilla(i).getColumna();

		//Comprobar que al rededor de cada casilla del barco no haya ninguna ocupada
		for (int j = 0; j < 9; j++) {
			switch (j) {
			case 0:
				break;
			case 1:
				fil--;
				break;
			case 2:
				col++;
				break;

			case 3:
				fil++;
				break;
			case 4:
				fil++;
				break;
			case 5:
				col--;
				break;
			case 6:
				col--;
				break;
			case 7:
				fil--;
				break;
			case 8:
				fil--;
				break;
			}

			//Primero se mira si estás mirando dentro de tablero y luego compruebas el resto de barcos
			if (Casilla(barcos[index]->convertToFila(fil), col).isIn()&&
				isInRestBoats(index, Casilla(barcos[index]->convertToFila(fil), col))) {
				return true;
			}
		}
	}
	return false;
}

bool Jugador::isInRestBoats(int index, Casilla myCas)const {
	bool cond=false;
	for (int i = 0; i < num_barcos; i++) {
		if (i != index && barcos[i]->existeCasInBoat(myCas.getFila(), myCas.getColumna())){
			cond=true;
			break;
		}
	}
	return cond;
}

//Se mira si la casilla_disparada del Jugador contrincante está viva o no
bool Jugador::isViva(const Jugador& contrincante,int *posBoat,int*posCas)const {
	bool condition = false;
	for (int i = 0; i < 5; i++) {
		//Miramos siempre todos los barcos (si están muertos no se entra ya que casillas_vivas>0)
		for (int j = 0; j < contrincante.barcos[i]->getCasillaViva(); j++) {
			if (contrincante.barcos[i]->getCasilla(j) == casilla_disparada) {
				condition = true;
				*posBoat = i; //Paso por referencia el index del barco en el que está 
				*posCas = j; //Paso por referencia el index de la casilla viva
				return condition;
			}
		}
	}
	return condition;
}

int Jugador::disparar(Jugador*contrincante) {
	int i=-2,j=-2;
	int indexBoat = -1;
	cout << "\nDisparo a casilla: \n";

	//Introducir casilla por teclado 
	cin >> casilla_disparada;
	if (isViva(*contrincante,&i,&j)) {
		//CASILLA TOCADA-->Simula el disparo
		Casilla aux;
		contrincante->barcos[i]->cambiarPosCasilla(j, contrincante->barcos[i]->getCasillaViva() - 1);
		contrincante->barcos[i]->casillaMenos();
		cout << "La casilla "<<casilla_disparada<< " ha sido tocada\n";
		indexBoat = i;
	}
	else if(casilla_disparada.isIn()){
		//CASILLA AGUA
		cout << "La casilla " << casilla_disparada << " es agua"<<endl;
	}
	else if (casilla_disparada == Casilla(Fila::J, 10)) {
		//Toca guardar partida
		indexBoat = -2;
	}
	else {
		//CASILLA INTRODUCIDA NO VÁLIDA-->Lanzo excepción y no dejo otra oportunidad
		cout << "La casilla " << casilla_disparada << " ";
		throw ExcepcionDisparoNoValido();

	}
	return indexBoat; //-1 si falla y me devuelve el index del barco si no falla
}

Barco<char>* Jugador::getBarco(int index)const {
	if (index < 0||index>5) {
		return nullptr;
	}
	else {
		return barcos[index];
	}
}



void Jugador::pintarTablero() {
	cout << "   0   1   2   3   4   5   6   7   8   9" << endl;
	cout << "A  ";
	printCasillasFila(Fila::A);
	cout << "B  ";
	printCasillasFila(Fila::B);
	cout << "C  ";
	printCasillasFila(Fila::C);
	cout << "D  ";
	printCasillasFila(Fila::D);
	cout << "E  ";
	printCasillasFila(Fila::E);
	cout << "F  ";
	printCasillasFila(Fila::F);
	cout << "G  ";
	printCasillasFila(Fila::G);
	cout << "H  ";
	printCasillasFila(Fila::H);
	cout << "I  ";
	printCasillasFila(Fila::I);
	cout << "J  ";
	printCasillasFila(Fila::J);
}

void Jugador::printCasillasFila(Fila i)const {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool cond,dontGoe;
	for (int j = 0; j < 10; j++) {
		cond = false;
		dontGoe = false;
		//Miramos en cada barco si existe essa casilla
		for (int boat = 0; boat < 5; boat++) {
			if (getBarco(boat)->existeCasInBoat(i, j)) {
				SetConsoleTextAttribute(hconsole, 10);
				cond = true;
				dontGoe = true;
				cout << getBarco(boat)->getTipoBarco();
				break;
			}
		}	
		if (!dontGoe&&isInitialice) {
			for (int boat = 0; boat < 5; boat++) {
				if (getBarco(boat)->printX(i, j)) {
					SetConsoleTextAttribute(hconsole, 12);
					cout << "X";
					cond = true;
					break;
				}
			}
		}
		if (!cond) {
			SetConsoleTextAttribute(hconsole, 15);
			cout << "*";
		}

		if (j < 9) {
			cout << "   ";
		}
		else {
			cout << endl;
		}

	}
	SetConsoleTextAttribute(hconsole, 15);
}
