#ifndef BALA_H
#define BALA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Bala {
private:
	Sprite sp;
	Image img;
	Vector2f pos;
	float velocidad;
	int alterador;
	bool ruidoDeDisparo;
public:
	bool impactado;
	Bala(Image &im,float x, float y);
	~Bala();
	void SetearBala (float x, float y);
	Sprite getSprite();
	void Mover();
	void Dibujar(RenderWindow &w);
};

#endif

