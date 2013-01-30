#include "Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje() {
	img.LoadFromFile("images/bubblesprite_2.png");
	sp.SetImage(img);
	sp.SetPosition(200,250);
	sp.SetSubRect(IntRect(1,0,200,65));
	pos.x= 0;
	pos.y = 0;
	saltando = false;
	altura_salto=50;
	saltoPositivo=true;
	tiempoCaida = 0;
	movDerecha = false;
	movIzquierda = false;
	movArriba = false;
	movAbajo = false;
	pos_mov = 0;
	municiones=0;
	puntaje=0;
	sp.Resize(200*0.90,85*0.75);
	}

Personaje::~Personaje() {
	
}

void Personaje::moverPersonaje(float x, float y) {
	if ((sp.GetPosition().y + y) < 400 and (sp.GetPosition().y + y) > 50){
		prev_pos = pos;
		sp.Move(x,y);
		pos = sp.GetPosition();
	}
}

void Personaje::dibujarPersonaje(RenderWindow &w) {
	
	///Dibujamos si la nave se mueve hacia la derecha
	if (movDerecha and sp.GetPosition().x <550) {
		if (pos_mov == 0) {
			sp.SetSubRect(IntRect(0,0,200,91));
			w.Draw(sp);
			++pos_mov;
			return;
		}
		if (pos_mov == 1) {
			sp.SetSubRect(IntRect(200,0,400,91));
			w.Draw(sp);
			++pos_mov;
			return;
		}
		if (pos_mov == 2) {
			sp.SetSubRect(IntRect(400,0,600,91));
			w.Draw(sp);
			pos_mov= 0;
			return;
		}
		
	}
	
	if (movDerecha and sp.GetPosition().x >550){
		///fueguito azul cuando se adelanta en la pantalla (para el efecto sexy)
		sp.SetSubRect(IntRect(2000,0,2196,91));
		w.Draw(sp);
		return;
	}
	///animacion cuando la nave se mueve a la izquierda
	if (movIzquierda) {
		if (pos_mov == 0) {
			sp.SetSubRect(IntRect(1400,0,1600,91));
			w.Draw(sp);
			++pos_mov;
			return;
		}
		if (pos_mov == 1) {
			sp.SetSubRect(IntRect(1420,0,1620,91));
			w.Draw(sp);
			pos_mov = 0;
			return;
		}
	}
	
	///Si la nave sube
	if (movArriba) {
		if (pos_mov == 0) {
			sp.SetSubRect(IntRect(600,0,800,91));
			w.Draw(sp);
			++pos_mov;
			return;
		}
		if (pos_mov == 1) {
			sp.SetSubRect(IntRect(800,0,1000,91));
			w.Draw(sp);
			pos_mov = 0;
			return;
		}
	}
	
	
	
	///si la nave baja
	if (movAbajo) {
		if (pos_mov == 0) {
			sp.SetSubRect(IntRect(1000,0,1200,91));
			w.Draw(sp);
			++pos_mov;
			return;
		}
		if (pos_mov == 1) {
			sp.SetSubRect(IntRect(1200,0,1400,91));
			w.Draw(sp);
			pos_mov = 0;
			return;
		}
	}
	
	
	
	w.Draw(sp);
}

Vector2f Personaje::getPosition(){
	return sp.GetPosition();
}
bool Personaje::getJump(){
	return saltando;
}

void Personaje::saltar(float t){
	saltando = true;
	selfJump(t);
}

void Personaje::selfJump(float tiempo){
	tiempoCaida+=tiempo;
	int v_i=10;     //velocidad inicial
	float g = 19.8; //gravedad
	float despl = v_i*tiempoCaida-g/2*tiempoCaida*tiempoCaida;
	
	moverPersonaje(0,-despl);
	
	if (pos.y >= 260){
		sp.SetPosition(pos.x,260);
		saltando = false;
		tiempoCaida=0;
	}
}

Sprite Personaje::getSprite() {
	return sp;
}

void Personaje::noMover() {
	pos = prev_pos;
	sp.SetPosition(pos);
}

void Personaje::setDerecha(bool state) {
	movDerecha = state;
}

void Personaje::setIzquireda(bool state) {
	movIzquierda = state;
}

void Personaje::setArriba(bool state) {
	movArriba = state;
}

void Personaje::setAbajo(bool state) {
	movAbajo = state;
}

void Personaje::arrastre(Event evt) {
//	if (pos.x > -5)
		moverPersonaje(-0.5f*((pos.x)/100),0);
//	
	if ((pos.x < 500) or (evt.Type != sf::Event::KeyReleased) or (evt.Type != sf::Event::KeyPressed)) {
		///si el bicho no se mueve un carajo
		if (pos_mov == 0) {
			sp.SetSubRect(IntRect(1600,0,1800,95));
			++pos_mov;
		}if (pos_mov == 1) {
			sp.SetSubRect(IntRect(1800,0,2000,95));
			pos_mov = 0;
		}
	}
}

bool Personaje::getIzquierda() {
	return movIzquierda;
}

bool Personaje::getDerecha() {
	return movDerecha;
}

bool Personaje::getArriba() {
	return movArriba;
}

bool Personaje::getAbajo() {
	return movAbajo;
}

void Personaje::SetColor (int r, int g, int b) {
	sp.SetColor(Color(r,g,b));
}
