#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class Block {
private:
	Image img;
	Sprite sp;
public:
	void dibujarBlock();
	Vector2f getPosition();
	void setPostion();
	Block();
	~Block();
};

#endif

