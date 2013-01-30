#ifndef SCENE_H
#define SCENE_H
#include <cstddef>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "TextureManager.h"
#include "Engine.h"

/**
 * Scene
 * Clase base para representar a una escena, para crear una nueva escena se debe
 * heredar de esta clase y definir los metodos virtuales puros
 */
class Scene{
	public:
	Scene();											/// realiza la inicilizacion base de la escena
	virtual void Init() = 0;							/// se llama al momento de desplegar la escena por primera vez
	virtual void Cleanup() = 0;							/// se llama antes de borrar la escena
	virtual void ProcessEvent(const sf::Event &e) = 0;	/// se llama cada vez que ha ocurrido un evento
	virtual void Update(const float &dt) = 0;			/// se llama por cada actualizacion de la escena
	virtual void Render(sf::RenderWindow &w) = 0;		/// se llama cada vez que hay que redibujar la escena
	
	protected:
	Engine &theEngine;									/// referencia a la instancia (singleton) del motor
	TextureManager &theTextureManager;					/// referencia a la instancia (singleton) del manejador de texturas
	void EndScene();									/// sirve para finalizar la escena

};



#endif
