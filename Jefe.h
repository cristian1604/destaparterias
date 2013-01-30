#ifndef JEFE_H
#define JEFE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Jefe {
private:
//	Image img;
	Vector2f pos, prev_pos;
	float tiempoCaida;
	bool estado;
	int valor;
	float tiempo_caida;
	float vida;
protected:
public:
	bool saltando;
	Sprite sp;
	float GetVida();
	void DisminuirVidaPorImpacto();
	Jefe(Image &im, float tiempo);
	Jefe(Image &im, float tiempo, Vector2f posicion);
	void arrastre(float tiempo);
	void moverJefe(float,float);
	void dibujarJefe(RenderWindow &w);
	Vector2f getPosition();
	bool getEstado();
	int getValor();
	void setEstado();
	Sprite getSprite();
	~Jefe();
};

#endif

