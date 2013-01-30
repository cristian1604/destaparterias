#include "Pildora.h"

Pildora::Pildora(Image &im, float tiempo) : impactado(false), bonusPack(false) {
	float num = 70 + rand() % 360;
	sp.SetPosition(1000, num);
	sp.SetImage(im);
	tiempo_caida = tiempo;
	estado = true;
	valor = -10;
}
void Pildora::Esconder(){
	sp.SetPosition(-100, -100);
}



void Pildora::mover(float t, RenderWindow &w) {
	sp.SetSubRect(IntRect(0,0,45,48));
	w.Draw(sp);
	tiempo_caida += t;
	if(pos.x > -30) {
		float velocidad, desplazamiento;
		velocidad = 2 - 1.5 * tiempo_caida;
		desplazamiento = (velocidad*velocidad + (1.5*2)) * 1.5/2;
		
		float direccion = pow(-2,rand()%4);
		sp.Move(-desplazamiento,rand()%2);
		pos = sp.GetPosition();
		
		if (sp.GetPosition().y > 420){
			impactado = true;
			sp.SetSubRect(IntRect(45,0,119,48));
			w.Draw(sp);
			estado = false;
		}
		if (sp.GetPosition().y < 80) {
			sp.SetSubRect(IntRect(45,0,119,48));
			impactado = true;
			w.Draw(sp);
			estado = false;
			
		}
	}
	else {
		sp.SetSubRect(IntRect(45,0,119,48));
		w.Draw(sp);
		estado = false;
		impactado = true;
	}
}

void Pildora::dibujar(RenderWindow &w) {
	w.Draw(sp);
}

Vector2f Pildora::getPosition(){
	return sp.GetPosition();
}

bool Pildora::getEstado() {
	return estado;
}

int Pildora::getValor(){
	return valor;
}

void Pildora::setEstado() {
	estado = !estado;
}

void Pildora::colisiona () {
	sp.SetSubRect(IntRect(45,0,119,48));
}

Sprite Pildora::getSprite() {
	return sp;
}

Pildora::~Pildora() {
	
}
