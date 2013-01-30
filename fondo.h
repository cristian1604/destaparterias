#ifndef FONDOSANGRE_H
#define FONDOSANGRE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Fondo {
private:
	Image fondo;
	Sprite sprite;
protected:
public:
	Fondo(string archivo, float pos = 1100);
	
	void setDerecha(float x = 1100);
	void moverFondo(float velocidad = -10, bool estado = true);
	
	bool rotar();
	
	const float getPosition() const;
	const Sprite & getSprite();
	~Fondo();
};

#endif

