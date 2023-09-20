#include "Game.h"

Game::Game() {
	j1 = Jugador();
	system("cls");
	j2 = Jugador();
	turno = true;
}

void Game::getTurno() {
	//True para activar j1, false para activar j2
	if (turno) { turno = false; } //Le tocará a j2
	else { turno = true; }//Le tocará a j1
}

void Game::iniciar() {

}