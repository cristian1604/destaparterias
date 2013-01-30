#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <cstddef>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>


/**
 * Clase encargada de facilitar el manejo de sonidos
 * asegurando de que no haya más de una copia de cada SoundBuffer.
 * Se trata de una clase singleton, es decir, existe un unico objeto de la misma.
 * Para operar con esta clase puede utilizarse la funcion Play() en la que se especifica el nombre
 * del archivo de sonido que se desea reproducir, la funcion se encarga de manejar el sonido creado y borrarlo
 * automáticamente cuando ya no se utilice. La función devuelve un puntero al sonido creado por si se desea alterar
 * las propiedades del mismo (volumen, posición, pitch, etc)
 * de imagen y el manejador devuelve una referencia a la misma,
 * cargandola en memoria si aún no ha sido cargada.
 * La función PreLoad() permite cargar un archivo para que ya se encuentre cargado al momento de reproducirlo por primera
 * vez y no ralentizar el juego
 */
class SoundManager {
	public:
	/**
	 * \brief devuelve el manejador de sonidos unico
	 */
	static SoundManager &GetInstance();
	
	
	/**
	* \brief Crea y reproduce un sonido correspondiente al archivo dado. Si el archivo de sonido no se ha cargado con Preload() se intenta cargarlo primero
	* \param name Nombre del archivo de sonido que se desea reproducir
	* \return puntero al sonido creado para poder modificar sus propiedades (volumen, posición, pith, etc)
	*/
	sf::Sound *Play(const std::string &name);
	
	
	/**
	* \brief PreCarga un sonido para que se encuentre disponible al momento de reproducirlo
	* \param name Nombre del archivo de sonido que se desea cargar
	*/
	void PreLoad(const std::string &name);
	
	
	
	private:
	static SoundManager *instance;							///< instancia unica de la clase
	std::map<std::string, sf::SoundBuffer> soundBuffers;	///< mapa que almacena los buffers de sonido con sus respectivos nombres de archivos
	std::list<sf::Sound *> sounds;							///< los sonidos que fueron creados y reproducidos
	
	/** constructor */
	SoundManager();
	
	/**
	* \brief Carga un SoundBuffer cuando este no existe en el mapeo. Esta función es para uso interno de la clase.
	* \param name nombre del archivo de sonido
	* \return referencia al SoundBuffer cargado
	*/
	const sf::SoundBuffer &Load(const std::string &name);
	
	/**
	* \brief busca y devuelve el SoundBuffer correspondiente a un archivo, si este no está cargado lo carga. Esta función es para uso interno de la clase.
	* \param name nombre del archivo de sonido
	* \return referencia al SoundBuffer correspondiente al archivo
	*/
	const sf::SoundBuffer &GetSoundBuffer(const std::string &name);
	
	/**
	* \brief Elimina los sonidos que ya han terminado de reproducirse. Se llama cada vez que se agrega un nuevo sonido para reproducir. Esta función es para uso interno de la clase.
	*/
	void Clean();
};

#endif

