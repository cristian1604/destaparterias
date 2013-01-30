#include "Bala.h"

Bala::Bala(Image &im,float x, float y) : velocidad(15), alterador(2), ruidoDeDisparo(true), impactado(false) {
	sp.SetImage(im);
	sp.SetPosition(x+160,y+32);
}

void Bala::SetearBala (float x, float y)  {
	sp.SetPosition(x,y);	
}

Sprite Bala::getSprite() {
	return sp;
}

void Bala::Mover(){
	if (sp.GetPosition().x < 1010)
		if (ruidoDeDisparo){
			sp.Move(velocidad, rand()%10);
			ruidoDeDisparo = !ruidoDeDisparo;
		}
		else
		{
			sp.Move(velocidad, (-1)*rand()%10);
			ruidoDeDisparo = !ruidoDeDisparo;
		}
	else
		impactado = true;

}

void Bala::Dibujar(RenderWindow &w){
	w.Draw(sp);
}

Bala::~Bala() {
	
}

