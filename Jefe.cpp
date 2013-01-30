#include "Jefe.h"
#include <iostream>
using namespace std;
//Jefe::Jefe(){
//	
//}
Jefe::Jefe(Image &im, float tiempo) : tiempoCaida(0), saltando(false), vida(1000) {
	float num = 70 + rand() % 360;
//	cout<<"Jefe creado en y="<<num<<endl;
	sp.SetPosition(1000 + num,num);
	sp.SetImage(im);
	tiempo_caida = tiempo;
//	sp.Resize(25,25);
	estado = true;
	valor = -10;
//	tiempo_caida = 0;
}
void Jefe::DisminuirVidaPorImpacto(){
	vida -= 1;
}
float Jefe::GetVida(){
	return this->vida;
}
void Jefe::arrastre(float tiempo) {
	if (saltando){
		cout << "SALTANDO" << endl;
		tiempoCaida+=tiempo*3;
		//int vel = (-4)*tiempoCaida+2;
		int v_i=12;     //velocidad inicial
		float g = 19.8; //gravedad
		float despl = v_i*tiempoCaida-g/2*tiempoCaida*tiempoCaida;
		
		moverJefe(0.f,-despl);
		
		if (pos.y >= 200){
			sp.SetPosition(pos.x,200);
			saltando = false;
			tiempoCaida=0;
		}
	}
}

Jefe::Jefe(Image &im, float tiempo, Vector2f posicion) : pos(posicion), vida(1000) {
	float num = 70 + rand() % 360;
	sp.SetPosition(1000 + num,num);
	sp.SetImage(im);
	tiempo_caida = tiempo;
	estado = true;
	valor = -10;
}

void Jefe::moverJefe(float x, float y) {
	if ((sp.GetPosition().y + y) < 400 and (sp.GetPosition().y + y) > 50){
		prev_pos = pos;
		sp.Move(x,y);
		pos = sp.GetPosition();
	}
}
void Jefe::dibujarJefe(RenderWindow &w) {
	sp.SetSubRect(IntRect(0,0,215,252));
	/*sp.SetPosition(700,215);*/
	w.Draw(sp);
}


Vector2f Jefe::getPosition(){
	return sp.GetPosition();
}

bool Jefe::getEstado() {
	return estado;
}

int Jefe::getValor(){
	return valor;
}

void Jefe::setEstado() {
	estado = !estado;
}

Sprite Jefe::getSprite() {
	return sp;
}

Jefe::~Jefe() {
	
}

