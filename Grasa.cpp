#include "Grasa.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Grasa::Grasa(Image &im) : vida(500) {
//	float num = 70 + rand() % 360;
	bool arriba = rand() % 2;
	sp.Resize(1.7,1.4);
	
	sp.SetImage(im);
	
	if(arriba){
		sp.SetSubRect(IntRect(0,0,150,50));
		sp.SetPosition(1000, 70);
	}
	else{
		sp.SetSubRect(IntRect(155,0,305,50));
		sp.SetPosition(1000, 410);
	}
	
	sp.SetImage(im);
//	tiempo_caida = tiempo;
	estado = true;
	valor = -10;
}

Grasa::Grasa(Image &im, Vector2f posicion) : pos(posicion) {
	float num = 70 + rand() % 360;
	sp.SetPosition(1000 + num,num);
	sp.SetImage(im);
//	tiempo_caida = tiempo;
	estado = true;
	valor = -10;
}

// Se mueve a la velocidad del fondo
void Grasa::mover() {
	sp.Move(-2,0);
}
void Grasa::dibujar(RenderWindow &w) {
	w.Draw(sp);
}

Vector2f Grasa::getPosition(){
	return sp.GetPosition();
}

bool Grasa::getEstado() {
	return estado;
}

int Grasa::getValor(){
	return valor;
}

void Grasa::setEstado() {
	vida -= 10;
	if (vida < 0)
		estado = !estado;
}

Sprite Grasa::getSprite() {
	return sp;
}

Grasa::~Grasa() {
	
}

