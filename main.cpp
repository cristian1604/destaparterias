#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

int main(int argc, char *argv[]){
	srand(time(NULL));
	Game juego;
	juego.startGame();
	return 0;
}

