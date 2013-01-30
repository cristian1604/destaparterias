#ifndef COMIDA_H
#define COMIDA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<stdlib.h>
using namespace sf;

class Bicho {
private:
//	Image img;
	Sprite sp;
	Vector2f pos;
	bool estado;
	int valor;
	float tiempo_caida;
public:
	Bicho(Image &im, float tiempo);
	Bicho(Image &im, float tiempo, Vector2f posicion);
	void moverBicho(float t);
	void dibujarBicho(RenderWindow &w);
	Vector2f getPosition();
	bool getEstado();
	int getValor();
	void setEstado();
	Sprite getSprite();
	~Bicho();
};

#endif

