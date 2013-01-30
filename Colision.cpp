#include "Colision.h"

Colision::Colision() {
	
}

bool Colision::colisionSimple(Sprite s1, Sprite s2) {
	
	///Obtengo el tamaño y la posicion de los sprites a comparar
	Vector2f tam_s1 = s1.GetSize();
	Vector2f tam_s2 = s2.GetSize();
	Vector2f pos_s1 = s1.GetPosition();
	Vector2f pos_s2 = s2.GetPosition();
	
	///Comparo si la esquina superior izquierda se S1 estra dentro del area ocupada por s2
	if( ((pos_s1.x >= pos_s2.x) and (pos_s1.x <= pos_s2.x + tam_s2.x))
		and ((pos_s1.y >= pos_s2.y) and (pos_s1.y <= pos_s2.y + tam_s2.y))
		) {
			return true;
		}
	
	///Comparo si la esquina superior dercha de S1 esta dentro del area ocupada por S2
	if( ((pos_s1.x + tam_s1.x >= pos_s2.x) and (pos_s1.x + tam_s1.x <= pos_s2.x + tam_s2.x))
		and ((pos_s1.y >= pos_s2.y) and (pos_s1.y <= pos_s2.y + tam_s2.y))
		) {
			return true;
		}
	
	///Comparo si la esquina inferior derecha de S1 esta dentro del area ocupada por S2
	if( ((pos_s1.x + tam_s1.x >= pos_s2.x) and (pos_s1.x + tam_s1.x <= pos_s2.x + tam_s2.x))
		and ((pos_s1.y + tam_s2.y>= pos_s2.y) and (pos_s1.y + tam_s2.y <= pos_s2.y + tam_s2.y))
		) {
			return true;
		}
	
	///Comparo si la esquina inferior izquierda de S1 esta dentro del area ocupada por S2
	if( ((pos_s1.x >= pos_s2.x) and (pos_s1.x <= pos_s2.x + tam_s2.x))
		and ((pos_s1.y + tam_s2.y>= pos_s2.y) and (pos_s1.y + tam_s2.y <= pos_s2.y + tam_s2.y))
		) {
			return true;
		}
	///s2 con s1
	///Comparo si la esquina superior izquierda se S1 estra dentro del area ocupada por s2
	if( ((pos_s2.x >= pos_s1.x) and (pos_s2.x <= pos_s1.x + tam_s1.x))
		and ((pos_s2.y >= pos_s1.y) and (pos_s2.y <= pos_s1.y + tam_s1.y))
		) {
			return true;
		}
	
	///Comparo si la esquina superior dercha de S1 esta dentro del area ocupada por S2
	if( ((pos_s2.x + tam_s2.x >= pos_s1.x) and (pos_s2.x + tam_s2.x <= pos_s1.x + tam_s1.x))
		and ((pos_s2.y >= pos_s1.y) and (pos_s2.y <= pos_s1.y + tam_s1.y))
		) {
			return true;
		}
	
	///Comparo si la esquina inferior derecha de S1 esta dentro del area ocupada por S2
	if( ((pos_s2.x + tam_s2.x >= pos_s1.x) and (pos_s2.x + tam_s2.x <= pos_s1.x + tam_s1.x))
		and ((pos_s2.y + tam_s1.y>= pos_s1.y) and (pos_s2.y + tam_s1.y <= pos_s1.y + tam_s1.y))
		) {
			return true;
		}
	
	///Comparo si la esquina inferior izquierda de S1 esta dentro del area ocupada por S2
	if( ((pos_s2.x >= pos_s1.x) and (pos_s2.x <= pos_s1.x + tam_s1.x))
		and ((pos_s2.y + tam_s1.y>= pos_s1.y) and (pos_s2.y + tam_s1.y <= pos_s1.y + tam_s1.y))
		) {
			return true;
		}
	
	return false;
}

Colision::~Colision() {
	
}

