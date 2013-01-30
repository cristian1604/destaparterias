#ifndef GRASA_H
#define GRASA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<stdlib.h>
using namespace sf;

class Grasa {
private:
//	Image img;
	Sprite sp;
	Vector2f pos;
	bool estado;
	int valor;
	float tiempo_caida;
	float vida;
public:
	Grasa(Image &im);
	Grasa(Image &im, Vector2f posicion);
	void mover();
	void dibujar(RenderWindow &w);
	Vector2f getPosition();
	bool getEstado();
	int getValor();
	void setEstado();
	Sprite getSprite();
	~Grasa();
};

#endif

