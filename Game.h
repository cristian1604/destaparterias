#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Personaje.h"
#include "Bicho.h"
#include <list>
#include <vector>
#include "fondo.h"
#include "Bala.h"
#include "Pildora.h"
#include "Grasa.h"
#include "Jefe.h"
using namespace std;
using namespace sf;

class Game {
private:
	Bala* balaGenerica;
	RenderWindow win;
	Event evento;
	View vista,atras;
	float XAxis, YAxis;
	float cantidadMalosPorRafaga;
	Image text_fondo, text_bicho[3], text_bala, text_pildora, text_grasa, text_jefe; vector <Bala> balas;
	vector <Pildora> pildoras;
	Personaje nave;
	Sprite bg_atras;
	Clock time_bichos;
	Clock time_grasas;
	vector <Bicho> bichos0;
	vector <Bicho>::iterator it_bicho0;
	vector <Grasa> bichos1;
	vector <Grasa>::iterator it_bicho1;
	float tiempo;
	int puntaje;
	String s_puntaje;
	int height,width;
	
	Image icon;
	Font ft;
	
	int contpill;
	Jefe *jefe;
	
	Fondo arteria, arteria2, sangre1, sangre2, fondoJefe;
	
	void processEvent(Event &evt);
	void drawGame(void);
	void updateGame(float t);
	void processCollisions(void);
	void sumarPuntaje(int p);
	char pos_mov;
	bool booster;
	
	void Disparar();
	
	int municion;
	int acum;
	
	SoundBuffer fondo_buffer;
	Sound fondo_sound;
	SoundBuffer pill_buffer;
	Sound pill_sound;
	SoundBuffer grasa_buffer;
	Sound grasa_sound;
//	SoundBuffer shot_buffer;
//	Sound shot_sound;
public:
	Game();
	void startGame();
	~Game();
};

#endif

