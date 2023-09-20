#include "Partida.h"


Partida::Partida() {
	turno = true; //es para que empiece j1 al iniciar()
}

void Partida::getTurno() {
	if (turno) { //tocará a j2
		turno = false;
	}
	else { //tocará a j1
		turno = true;
	}
}

bool Partida::iniciar() {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool isAcabada=false;  //¿Ha acabado la partida?
	int index;
	bool cond = true;
	while (cond) {
		try {
			//AQUÍ METEREMOS SI DESEA GUARDAR LA PARTIDA
			//ATACA J1
			system("cls");
			cout << "RECORDATORIO: a->Acorazado    b->Buque    p->Patrullero    P->Portaaviones    s->Submarino\n";
			cout << "\nPara guardar partida, en disparar tiene que poner Fila:J Columna:10\n\n";
			if (turno) {
				SetConsoleTextAttribute(hconsole, 13);
				cout << "->TURNO J1: "<<endl<<endl;
				SetConsoleTextAttribute(hconsole, 15);
				j1.pintarTablero();
				index = j1.disparar(&j2);
				if (index > -1) {
					getTurno(); //Para que le vuelva a tocar
					if (isHundido(index, j2)) {
						j2--;
						cout << "El " << j2.getBarco(index)->getNombre() << " ha sido hundido. Quedan "<<
							j2.getNum_barcos()<<" vivos del Jugador 2"<< endl;
						if (isFlotaHundida(j2)) {
							cond = false;
							isAcabada = true;
							cout << "La flota del Jugador 2 ha sido destruida. FIN DE LA PARTIDA.\n" << endl;
							system("pause");
							break;
						}
					}
				}
				else if (index == -2) {
					//Guardamos la partida-->Nos salimos del bucle, y por tanto del método
					cond = false;
					break;
				}
			}

			//ATACA J2
			else {
				SetConsoleTextAttribute(hconsole, 9);
				cout << "->TURNO J2: "<<endl<<endl;
				SetConsoleTextAttribute(hconsole, 15);
				j2.pintarTablero();
				index = j2.disparar(&j1);
				if (index > -1) {
					getTurno(); //Para que le vuelva a tocar
					if (isHundido(index, j1)) {
						j1--;
						cout << "El " << j1.getBarco(index)->getNombre() << " ha sido hundido. Quedan " <<
							j1.getNum_barcos() << " vivos del Jugador 1" << endl;
						if (isFlotaHundida(j1)) {
							cond = false;
							isAcabada = true;
							cout << "La flota del Jugador 1 ha sido destruida. FIN DE LA PARTIDA.\n" << endl;
							system("pause");
							break;
						}
					}
				}
				else if (index == -2) {
					//Guardamos la partida-->Nos salimos del bucle, y por tanto del método
					cond = false;
					break;
				}
			}
		}catch (ExcepcionDisparoNoValido& ednv) {
			cout<<ednv.what();
		}catch (runtime_error&re) {
			cout << re.what();
		}catch (exception& e) {
			cout << e.what();
		}catch (...) {
			cout << "Excepcion generica\n";
		}
		getTurno();
		system("pause");
	}
	system("cls");
	return isAcabada;
}

bool Partida::isHundido(int index,Jugador player) {
	bool cond=false;
	if (player.getBarco(index)->getCasillaViva() == 0) { 
		cond = true; 
	}
	return cond;
}

bool Partida::isFlotaHundida(Jugador player) {
	bool cond = false;
	if (player.getNum_barcos() == 0) { cond = true; }
	return cond;
}