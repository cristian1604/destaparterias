#include "fondo.h"

Fondo::Fondo (string archivo, float pos){
	fondo.LoadFromFile(archivo);
	sprite.SetImage(fondo);
	sprite.SetPosition(pos,0);
	sprite.SetSubRect(IntRect(0,0,1102,615));
	fondo.SetSmooth(false);
}

void Fondo::setDerecha (float x) {
	sprite.SetPosition(x, 0);
}

const float Fondo::getPosition ( ) const {
	return sprite.GetPosition().x;
}

void Fondo::moverFondo (float vel, bool estado) {
	if(estado)	
		sprite.Move(vel, 0);
	else if(getPosition() > 545)
		sprite.Move(vel, 0);
}

const Sprite & Fondo::getSprite () {
	return sprite;
}

bool Fondo::rotar () {
	return getPosition() == 0;
}


Fondo::~Fondo ( ) {
	
}
