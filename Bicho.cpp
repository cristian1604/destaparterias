#include "Bicho.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Bicho::Bicho(Image &im, float tiempo) {
	float num = 70 + rand() % 360;
//	cout<<"bicho creado en y="<<num<<endl;
	sp.SetPosition(1000 + num,num);
	sp.SetImage(im);
	tiempo_caida = tiempo;
//	sp.Resize(25,25);
	estado = true;
	valor = -10;
//	tiempo_caida = 0;
}

Bicho::Bicho(Image &im, float tiempo, Vector2f posicion) : pos(posicion) {
	float num = 70 + rand() % 360;
	sp.SetPosition(1000 + num,num);
	sp.SetImage(im);
	tiempo_caida = tiempo;
	estado = true;
	valor = -10;
}

void Bicho::moverBicho(float t) {
	tiempo_caida += t;
	if(pos.x > -10) {
		float velocidad, desplazamiento;
		velocidad = 2 - 1.5 * tiempo_caida;
		desplazamiento = (velocidad*velocidad + (3*2)) * 1.5/2;
		
		float direccion = pow(-2,rand()%4);
		sp.Move(-desplazamiento,pow((-1), rand()%2));
//		if(sp.GetPosition().y < 80 || sp.GetPosition().y > 460)
//			sp.Move(-desplazamiento,-2*direccion);
			/*sp.Move(-desplazamiento,direccion);*/
//			sp.Move(+desplazamiento, -direccion);
//			sp.Move(-desplazamiento, );
		
//			sp.Move(-desplazamiento, 5);
		
//		sp.Move(-desplazamiento,pow(-1,rand()%3));
		pos = sp.GetPosition();
	}
	else {
		estado = false;
	}
}
void Bicho::dibujarBicho(RenderWindow &w) {
	w.Draw(sp);
}


Vector2f Bicho::getPosition(){
	return sp.GetPosition();
}

bool Bicho::getEstado() {
	return estado;
}

int Bicho::getValor(){
	return valor;
}

void Bicho::setEstado() {
	estado = !estado;
}

Sprite Bicho::getSprite() {
	return sp;
}

Bicho::~Bicho() {
}

