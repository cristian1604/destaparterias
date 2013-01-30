#ifndef COLISION_H
#define COLISION_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Colision {
private:
public:
	Colision();
	bool colisionSimple(Sprite s1, Sprite s2);
	~Colision();
};

#endif

