// FLOTA_JUAN_ARIZA.cpp

#include <iostream>
#include"Buque.h"
#include "Jugador.h"
#include "Barco.h"
#include "Tablero.h"
#include "Acorazado.h"
#include "Partida.h"
#include <windows.h>
using namespace std;

int main(){
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool menu=true,isAcabada=false;
	int k=0,opt;
		SetConsoleTextAttribute(hconsole, 4);
		string title = "HUNDIR LA FLOTA";
		int titleLength = title.length();
		cout <<"                                                  ";
		for (int i = 0; i < titleLength + 4; i++) {
			cout << "*";
		}
		cout << endl;
		cout << "                                                  * " << title << " *" << endl;
		cout << "                                                  ";
		for (int i = 0; i < titleLength + 4; i++) {
			cout << "*";
		}
		cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		while (menu) {
				system("cls");
				SetConsoleTextAttribute(hconsole, 4);
				cout << "->NUEVA PARTIDA\n\n"; 
				SetConsoleTextAttribute(hconsole, 15);
				Partida flota;
				isAcabada=flota.iniciar();
				while (true) {
					system("cls");
					cout << "NUEVA PARTIDA[1]   CARGAR ULTIMA PARTIDA[2]  SALIR[3]\n\nIntroduzca una opcion: ";
					cin >> opt;
					if (opt == 1) { break; }
					else if (opt == 2) {
						if (isAcabada) {
							cout << "Ya ha finalizado la partida\n";
							system("pause");
						}
						else {	isAcabada=flota.iniciar();  }
					}
					else if (opt == 3) {
						menu = false;
						break;
					}
				}
		}
	return 0;
}