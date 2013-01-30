#include "SoundManager.h"
using namespace std;

// se debe inicializar la instancia única estática
SoundManager *SoundManager::instance = NULL;

// constructor
SoundManager::SoundManager(){
	;
}


// devuelve la instancia única del manejador
SoundManager &SoundManager::GetInstance(){
	if (instance == NULL) instance = new SoundManager();
	return *instance;
}


// en caso de no encontrar un determinado SoundBuffer en el mapa, esta función
// lo carga desde el disco.
const sf::SoundBuffer &SoundManager::Load(const std::string &name){
	// crea un objeto sf::SoundBUffer y lo agrega al mapa
	sf::SoundBuffer b;
	pair<map<string, sf::SoundBuffer>::iterator, bool> p=soundBuffers.insert(pair<string, sf::SoundBuffer>(name, b));
	// una vez que dicho objeto está cargado, se llama a LoadFromFile() para cargar el SoundBuffer en dicho
	// objeto. Esto se realiza después de cargar al objeto sf::SoundBuffer en el mapa y no antes por cuestiones
	// de eficiencia: luego de llamar a LoadFromFile() el objeto será más pesado porque contendrá la textura,
	// por esta razón, requerirá más tiempo para ser copiado, y la inserción en el mapa requiere hacer una copia.
	sf::SoundBuffer &buffer = p.first->second;
	if(!buffer.LoadFromFile(name)){
		cout<<"ERROR: no se pudo cargar achivo de sonido: "<<name<<endl;
	}
	return buffer;
}


// busca un SoundBuffer a partir de su nombre de archivo
// si no lo encuentra en el mapa, intenta cargarlo desde el dico
const sf::SoundBuffer &SoundManager::GetSoundBuffer(const std::string &name){
	map<string, sf::SoundBuffer>::iterator p=soundBuffers.find(name);
	if(p != soundBuffers.end()){
		return p->second;
	}else{
		return Load(name);
	}
	
}


// busca un SoundBuffer a partir de su nombre de archivo
// si no lo encuentra en el mapa, intenta cargarlo desde el dico
void SoundManager::Clean(void){
	list<sf::Sound *>::iterator p = sounds.begin();
	while(p != sounds.end()){
		if ((*p)->GetStatus() == sf::Sound::Stopped){
			delete (*p); // borra el sonido
			p = sounds.erase(p);
		}else{
			p++;
		}
	}
}


// crea un nuevo sonido y lo reproduce
sf::Sound *SoundManager::Play(const std::string &filename){
	Clean();		// limpia los objetos que ya han terminado de reproducirse
	const sf::SoundBuffer &buffer = GetSoundBuffer(filename);	// consigue el SoundBuffer
	sf::Sound *newSound = new sf::Sound(buffer);	// crea el sonido
	newSound->Play();	// lo pone en estado de reproduccion
	sounds.insert(sounds.end(), newSound);	// lo agrega a la lista (para despues borrarlo)
	return newSound;	// devuelve el nuevo sonido para alterar sus propiedades
}
