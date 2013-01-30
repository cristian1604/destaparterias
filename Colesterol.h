#ifndef COLESTEROL_H
#define COLESTEROL_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Colesterol {
private:
	Image img;
	Sprite sp;
	Vector2f pos;
	bool estado;
	int valor;
	float tiempo_caida;
public:
	
	Colesterol();
	~Colesterol();
};

#endif
