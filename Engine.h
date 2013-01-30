#ifndef ENGINE_H
#define ENGINE_H
#include <cstddef>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <deque>

class Scene;

using namespace std;

class Engine {
	public:
	/**
	 * \brief inicializa la ventana de juego
	 * \param w ancho de la ventana
	 * \param h alto de la ventana
	 */
	void Init(unsigned w, unsigned h);
	
	
	/**
	 * \brief ejecuta el bucle de juego
	 */
	void Loop();
	
	
	/**
	 * \brief devuelve una referencia al motor (la clase es singleton)
	 */
	static Engine &GetEngine();
	
	
	/**
  	 * \brief finaliza la escena actual y comienza una nueva
	 * \param nueva escena
	 */
	void ChangeScene(Scene *s);
	
	
	/**
	 * \brief deja la escena actual en suspenso y comienza una nueva
	 * \param nueva escena
	 */
	void PushScene(Scene *s);
	
	
	/**
	 * \brief agrega una nueva escena al final de la lista, para que sea ejecutada cuando terminen las que estan antes de ella
	 * \param nueva escena
	 */
	void AppendScene(Scene *s);
	
	
	/**
	 * \brief quita la escena actual y retoma la que quedo suspendida o la proxima en la cola
	 */
	void PopScene();
	
	
	/**
	 * \brief finaliza la escena actual y sigue con la proxima en la cola
	 */
	void EndCurrentScene();
	
	
	/**
	 * \brief devuelve el Input correspondiente a la ventana de juego
	 */
	const sf::Input &GetInput() const;
	
	
	/**
	* \brief devuelve la ventana de juego
	*/
	sf::RenderWindow &GetRenderWindow() {return m_window;};
	
	
	/**
	 * \brief finaliza el bucle de juego
	 */
	void Exit();
	
	private:
	sf::RenderWindow m_window;					/// la ventana de renderizado
	static Engine *m_instance;					/// instancia unica (singleton) del motor
	std::deque<Scene *> m_sceneQueue;			/// cola de doble extremo donde se almacenan punteros a las escenas
	Scene *m_currentScene, *m_sceneToDelete;	/// puntero a la escena actual y puntero a la escena que debe ser borrada
	bool m_mustUpdateCurrentScene;				/// bandera que indica si debe realizarse alguna operacion con escenas
	bool exitEngine;							/// indica si se debe permanecer o no en el gameloop
	
	Engine();
};

#endif

