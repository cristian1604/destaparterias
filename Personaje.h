#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Personaje {
private:
	Image img;
	Vector2f pos, prev_pos;
	float altura_salto;
	bool saltando;
	bool saltoPositivo;
	float tiempoCaida;
	bool movDerecha;
	bool movIzquierda;
	bool movArriba;
	bool movAbajo;
	unsigned short municiones;
	long puntaje;
	int pos_mov;
public:	
	Sprite sp;
	Personaje();
	void moverPersonaje(float x, float y);
	void dibujarPersonaje(RenderWindow &w);
	Vector2f getPosition();
	void saltar(float t);
	bool getJump();
	void selfJump(float tiempo);
	Sprite getSprite();
	void noMover();
	void setDerecha(bool state);
	void setIzquireda(bool state);
	void setArriba(bool state);
	void setAbajo(bool state);
	bool getIzquierda();
	bool getDerecha();
	bool getArriba();
	bool getAbajo();
	void arrastre(Event evt);
	void SetColor (int r, int g, int b);
	
	unsigned short getMuniciones();
	long getPuntaje();
	~Personaje();
};

#endif

