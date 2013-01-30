#include "Engine.h"
#include "Scene.h"


Engine *Engine::m_instance=NULL;



const sf::Input &Engine::GetInput() const{
	return m_window.GetInput();
}



Engine &Engine::GetEngine(){
	if(!m_instance){
		m_instance = new Engine();
	}
	return *m_instance;
}



Engine::Engine() {
	exitEngine = false;
}



void Engine::Init(unsigned w, unsigned h){
	m_window.Create(sf::VideoMode(w,h), "PVJ2_SimpleEngine");
	m_window.SetFramerateLimit(60);
	m_sceneToDelete = NULL;
	m_currentScene = NULL;
}



void Engine::Loop(){
	sf::Clock clock;
	float elapsedTime;
	sf::Event event;
	
	// el bucle de juego
	clock.Reset();
	while(m_currentScene != NULL && !exitEngine){
		elapsedTime=clock.GetElapsedTime();
		clock.Reset();
		
		// procesa los eventos y llama a la funcion de eventos de la escena
		while(m_window.GetEvent(event)) {
			if(event.Type == event.Closed){
				m_window.Close();
				exitEngine = true;
			}else{
				m_currentScene->ProcessEvent(event);
			}
		}
		// actualiza la escena
		m_currentScene->Update(elapsedTime);
		
		// dibuja la escena
		// m_window.Clear(sf::Color(0,0,0));
		m_currentScene->Render(m_window);
		m_window.Display();
		
		// manejo de escenas: si hubo algun cambio de escena, lo hace efectivo
		if (m_mustUpdateCurrentScene){
			// si hay alguna escena por borrar/desinicializar, lo hace
			if (m_sceneToDelete != NULL){
				m_sceneToDelete->Cleanup();
				delete m_sceneToDelete;
				m_sceneToDelete = NULL;
			}
			// pone como escena actual la escena del frente de la cola
			if (m_sceneQueue.size()>0)
				m_currentScene = m_sceneQueue.front();
			else
				m_currentScene = NULL;
		}
	}
}



void Engine::ChangeScene(Scene *s){
	PopScene();		// quita la escena actual de la cola
	PushScene(s);	// empuja otra escena en su posicion
	m_mustUpdateCurrentScene = true;	// activa la bandera para que se actualicen los punteros de escenas
}



void Engine::PushScene(Scene *s){
	s->Init();
	m_sceneQueue.push_front(s);
	m_mustUpdateCurrentScene = true;
	m_sceneToDelete = NULL;
}



void Engine::AppendScene(Scene *s){
	if ( m_sceneQueue.size() == 0)
		m_currentScene = s;
	m_sceneQueue.push_back(s);
	s->Init();
	m_sceneToDelete = NULL;
}



void Engine::PopScene(){
	m_sceneToDelete = m_sceneQueue.front();
	m_sceneQueue.pop_front();
	m_mustUpdateCurrentScene = true;
}



void Engine::EndCurrentScene(){
	PopScene();
}



void Engine::Exit(){
	exitEngine = true;
}
