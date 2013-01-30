#ifndef PILDORA_H
#define PILDORA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<stdlib.h>
using namespace sf;

class Pildora {
private:
	Sprite sp;
	Vector2f pos;
	bool estado;
	int valor;
	float tiempo_caida;
public:
	bool bonusPack;
	bool impactado;
	Pildora(Image &im, float tiempo);
	void mover(float t,RenderWindow &w);
	void dibujar(RenderWindow &w);
	Vector2f getPosition();
	bool getEstado();
	int getValor();
	void setEstado();
	Sprite getSprite();
	void colisiona();
	~Pildora();
	void Esconder();
};

#endif

