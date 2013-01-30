#include "Game.h"
#include "Collision.h"
#include <sstream>
#include <iostream>
#include "fondo.h"
//hola mundo

//cristian estuvo aca rompiendo todo desde linux y ahora commiteo con 
este comentario crazy =P

#define MAX_PUNTAJE 1500

using namespace std;

Game::Game() : cantidadMalosPorRafaga(2), XAxis(0), YAxis(0),
	arteria("images/arteria.png",0), arteria2("images/arteria.png",1099),
	sangre1("images/sangre.png",0), sangre2("images/sangre.png",1099),
	fondoJefe("images/corazon.png"), booster(false)
{
	municion=100;
	acum=0;
	text_jefe.LoadFromFile("images/monstersprite_1.png");
	text_grasa.LoadFromFile("images/sprite_acumulaciones.png");
	text_bicho[0].LoadFromFile("images/bicho0.png");
	text_bicho[1].LoadFromFile("images/pill.png");
	text_bicho[2].LoadFromFile("images/bicho0.png");
	text_bala.LoadFromFile("images/bala.png");
	text_pildora.LoadFromFile("images/pillsprite.png");
	width = 1000;
	height = 615;
	win.Create(VideoMode(width, height), "Global Game Jam 2013");
	vista.SetCenter(width/2,height/2);
	vista.SetHalfSize(width/2, height/2);
	atras.SetCenter(width/2,height/2);
	atras.SetHalfSize(width/2, height/2);
	pos_mov = 0;
	contpill = 0;
	bg_atras.SetImage(text_fondo);
	
	sangre1.setDerecha(0);
	arteria.setDerecha(0);
	sangre2.setDerecha();
	arteria2.setDerecha();
	bg_atras.SetPosition(0,0);
	
	puntaje = 0;
	sumarPuntaje(0);
	s_puntaje.SetPosition(10,530);
	
	
	fondo_buffer.LoadFromFile("music/fondo.wav");
	fondo_sound.SetBuffer(fondo_buffer);
	fondo_sound.SetVolume(50.f);
	fondo_sound.SetLoop(true);
	
	pill_buffer.LoadFromFile("music/pill.wav");
	pill_sound.SetBuffer(pill_buffer);
	pill_sound.SetVolume(25.f);
	
	grasa_buffer.LoadFromFile("music/grasa.wav");
	grasa_sound.SetBuffer(grasa_buffer);
	grasa_sound.SetVolume(100.f);
//	shot_buffer.LoadFromFile("music/shot.wav");
//	shot_sound.SetBuffer(shot_buffer);
	
	ft.LoadFromFile("ITCBLKAD.ttf");
	s_puntaje.SetFont(ft);
	
	
	
}

Game::~Game() {
	
}


void Game::Disparar() {
	if (municion <= 0)
		return;
//	float val = rand()%4;
//	if (val > 2){
		/*shot_sound.Play();*/
		balaGenerica->SetearBala(nave.getPosition().x+150, nave.getPosition().y+20);
		balas.push_back(*balaGenerica);
		return;
//	}
//	else if (val > 1) {
//		balas.push_back(*balaGenerica);
//		return;
//	}
//	else
//		balas.push_back(*balaGenerica);
	
	--municion;
}


void Game::processEvent(Event &evt) {
	
	if(evt.Type == evt.Closed) {
		win.Close();
	}
	
	
	///Procesar eventos de teclado
	if (((evt.Type == sf::Event::KeyPressed) and (evt.Key.Code == sf::Key::Left)) ) {
		nave.setIzquireda(true);
	}
		
	if (((evt.Type == sf::Event::KeyReleased) and (evt.Key.Code == sf::Key::Left))) {
		nave.setIzquireda(false);
	}
	
	if (((evt.Type == sf::Event::KeyPressed) and (evt.Key.Code == sf::Key::Right))){
		nave.setDerecha(true);
	}
	
	if (((evt.Type == sf::Event::KeyReleased) and (evt.Key.Code == sf::Key::Right))) {
		nave.setDerecha(false);
	}
	
	if (((evt.Type == sf::Event::KeyPressed) and (evt.Key.Code == sf::Key::Up))){
		nave.setArriba(true);
	}
	
	if (((evt.Type == sf::Event::KeyReleased) and (evt.Key.Code == sf::Key::Up))) {
		nave.setArriba(false);
	}
	
	if (((evt.Type == sf::Event::KeyPressed) and (evt.Key.Code == sf::Key::Down))){
		nave.setAbajo(true);
	}
	
	if (((evt.Type == sf::Event::KeyReleased) and (evt.Key.Code == sf::Key::Down))) {
		nave.setAbajo(false);
	}
	
	if (((evt.Type == sf::Event::KeyPressed) and (evt.Key.Code == sf::Key::Space )) ) {
		Disparar();
	}
	

	

	
}

//
// DRAW
//
void Game::drawGame(void) {
	win.SetView(atras);
	win.SetView(vista);
	
	//	Dibujamos los sprites que son necesarios al comenzar el juego.
	//para eso dibujamnos arteria, sangre y el jugador. En ese orden.
	win.Draw(arteria.getSprite());
	win.Draw(arteria2.getSprite());
	
	win.Draw(sangre1.getSprite());
	win.Draw(sangre2.getSprite());
	
	win.Draw(fondoJefe.getSprite());
	//---------------------------------------
	
	vector<Bala>::iterator it_aux;
	
	if (!balas.empty()){
		for (vector<Bala>::iterator it = balas.begin(); it != balas.end(); it++){
			if(!it->impactado)
				it->Dibujar(win);
		}
	}
	
	nave.dibujarPersonaje(win);
	
	
	it_bicho0 = bichos0.begin();
	for(unsigned int i = 0; i < bichos0.size(); i++) {
		bichos0[i].dibujarBicho(win);
	}
	
	if (!pildoras.empty()) {
		for (vector<Pildora>::iterator it = pildoras.begin(); it != pildoras.end(); it++) {
				(*it).dibujar(win);
		}
	}
	
	if ((jefe->GetVida() > 0) and (puntaje > MAX_PUNTAJE))
	{
		booster = true;
		jefe->dibujarJefe(win);
	}
	
	// Grasas que vienen pegadas a la pared
	it_bicho1 = bichos1.begin();
	for(unsigned int i = 0; i < bichos1.size(); i++) {
		bichos1[i].dibujar(win);
	}
	
	for (vector<Pildora>::iterator it = pildoras.begin(); it != pildoras.end(); it++)
	{
//		cout << "Dibujando pildora" << endl;
		(*it).dibujar(win);		
	}
	
	win.SetView(win.GetDefaultView());
	win.Draw(s_puntaje);
}


//
// UPDATE GAME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
void Game::updateGame(float t) {
	const sf::Input& Input = win.GetInput();
	
	if (Input.IsJoystickButtonDown(0, 0) || Input.IsJoystickButtonDown(0, 1) || Input.IsJoystickButtonDown(0, 2) || Input.IsJoystickButtonDown(0, 3))
	{
		Disparar();
	}


	this->XAxis = Input.GetJoystickAxis(0, sf::Joy::AxisX);
	this->YAxis = Input.GetJoystickAxis(0, sf::Joy::AxisY);
	
	nave.moverPersonaje(XAxis/20,YAxis/20);

	
	
	if (puntaje > MAX_PUNTAJE and jefe->GetVida() < 1)
	{
		win.Clear();

		stringstream out1;
		out1<<"¡¡¡Victoria!!!" << " Puntos: " << puntaje << endl;
		out1<<"¡Has salvado a este humano del " << endl <<"ataque de colesteroles!" << endl;
		string aux = out1.str();
		s_puntaje = (String)aux;
		s_puntaje.SetPosition(250,200);
	}
	
	//Saber si ya llegamos al booster
	if(puntaje >= MAX_PUNTAJE)
		booster = true;
	
	if (booster)
		jefe->arrastre(t);
	
	
	
	//insertar pildora cuando pasan 60 segundos y no hay ninguna otra en pantalla
	if (acum >= 10 and pildoras.empty()){
		pildoras.insert(pildoras.begin(), Pildora(text_pildora, 1));
		cout<<"pildora generada"<<endl;
		acum = 0;
	}
	
	//mueve la pildora a traves de la pantalla
	for (vector<Pildora>::iterator it = pildoras.begin(); it != pildoras.end(); it++) {
		(*it).mover(t,win);
	}
	//mueve la Grasa
	for (vector<Grasa>::iterator it = bichos1.begin(); it != bichos1.end(); it++){
		(*it).mover();
	}
	
	if(nave.getJump())
		nave.selfJump(t);
	
	if (time_grasas.GetElapsedTime() > 5) {
		bichos1.insert(bichos1.begin(), Grasa(text_grasa));
		time_grasas.Reset();
	}
	
	///funcion que maneja el paso del tiempo en segundos
	
	if(time_bichos.GetElapsedTime() > 1) {
		++acum;
		cout<<acum<<endl;
		nave.SetColor(255,255,255);
		cantidadMalosPorRafaga += pow((t),(1/2))/10;
		cout << cantidadMalosPorRafaga << endl;
		
		if (cantidadMalosPorRafaga > 10) cantidadMalosPorRafaga = 6;
		for(short i = cantidadMalosPorRafaga; i > 0; i--){
			bichos0.insert(bichos0.begin(),Bicho(text_bicho[0],tiempo));
		}
		
		time_bichos.Reset();
	}
	
	//mueve las balas a traves de la pantalla
	if (!balas.empty()){
		for (vector<Bala>::iterator it = balas.begin(); it != balas.end(); it++){
			(*it).Mover();
		}
	}
	
	
	
	it_bicho0 = bichos0.begin();
	for(unsigned int i = 0; i <bichos0.size(); i++) {
		if(!bichos0[i].getEstado()) {
			bichos0.erase(it_bicho0);
		} else
			++it_bicho0;
	}
	for(unsigned int i = 0; i < bichos0.size(); i++) {
		bichos0[i].moverBicho(t);
	}
	
	it_bicho1 = bichos1.begin();
	for(unsigned int i = 0; i <bichos1.size(); i++) {
		if(!bichos1[i].getEstado()) {
			bichos1.erase(it_bicho1);
		} else
			it_bicho1++;
	}
	
	
	///movimiento de la nave mediante eventos del teclado
	if(nave.getIzquierda() and nave.getPosition().x >= 0) {
		nave.moverPersonaje(-5,0);
//		if(nave.getPosition().x >= 500 && nave.getPosition().x+500 <= 1000) {
//			vista.Move(-5, 0);
//			atras.Move(-2.5, 0);
//		}
	}
	else if(nave.getDerecha() and nave.getPosition().x <= 1000) {
		nave.moverPersonaje(5,0);
//		if(nave.getPosition().x >= 500  && nave.getPosition().x+500 <= 2560) {
//			vista.Move(5, 0);
//			atras.Move(2.5,0);
//		}
	}
	
	if(nave.getArriba() and nave.getPosition().y >= 0) {
		if(nave.getPosition().y > 70) {
			nave.moverPersonaje(0,-5);
		}
	}
	else if(nave.getAbajo() and nave.getPosition().y <= 390) {
		nave.moverPersonaje(0,5);
//		if(nave.getPosition().x >= 500  && nave.getPosition().x+500 <= 2560) {
//			vista.Move(5, 0);
//			atras.Move(2.5,0);
//		}
	}
}



///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!COLISIONES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//colision de nave con bicho
void Game::processCollisions(void) {
	for(unsigned int i = 0; i <bichos0.size(); i++) {
		if(Collision::PixelPerfectTest(nave.getSprite(),bichos0[i].getSprite())) {
			nave.SetColor(255,0,0);
			bichos0[i].setEstado();
			sumarPuntaje(bichos0[i].getValor());
/*			nave_comer.Play();*/
		}
	}


	// Colisiones de balas
	for (unsigned int i=0;i<balas.size();i++) {
		for (unsigned int j=0;j<bichos0.size();j++) {
			if(Collision::PixelPerfectTest(balas[i].getSprite(),bichos0[j].getSprite())) {
				bichos0[j].setEstado();
				sumarPuntaje(-bichos0[j].getValor());
				grasa_sound.Play();
				balas[i].impactado = true;
			}
		}
	}	
	vector<Bala>::iterator it_aux=balas.begin();
	vector <Bala>::iterator itV = balas.begin();
	for (unsigned int i=0;i<balas.size()-1;i++) {
		if (itV != balas.end()){
			if (balas[i].impactado) {
				it_aux=itV;
				balas.erase(itV);
				itV=it_aux;
				
//				cout<<"me borre"<<endl;
			}
			++itV;
		}
		else
			break;
	}
	
	// COLISION JEFE
	if (jefe->GetVida() > 0 && booster){
		for (unsigned int i=0;i<balas.size();i++) {
			if(Collision::PixelPerfectTest(balas[i].getSprite(),jefe->sp)) {
				jefe->saltando = true;
				jefe->DisminuirVidaPorImpacto();
				cout << "VIDA DEL JEFE: " << jefe->GetVida() << endl;
			}
		}
		

	}
	
	// Colisiones de grasas
	for (unsigned int i=0;i<balas.size();i++) {
		for (unsigned int j=0;j<bichos1.size();j++) {
			if(Collision::PixelPerfectTest(balas[i].getSprite(),bichos1[j].getSprite())) {
				bichos1[j].setEstado();
				sumarPuntaje(-bichos1[j].getValor());
/*				nave_comer.Play();*/
				balas[i].impactado = true;
				bichos1[i].setEstado();
				cout << bichos1[i].getEstado() << endl;
				
			}
		}
	}
	vector<Bala>::iterator it_auxGrasa=balas.begin();
	vector <Bala>::iterator itBalaImpactaGrasa = balas.begin();
	for (unsigned int i=0;i<balas.size();i++) {  //cualquier cosa restamos un 1
		if (itBalaImpactaGrasa != balas.end()){
			if (balas[i].impactado) {
				it_auxGrasa=itBalaImpactaGrasa;
				balas.erase(itBalaImpactaGrasa);
				itBalaImpactaGrasa=it_auxGrasa;
			}
			++itBalaImpactaGrasa;
		}
		else
			break;
	}
	
	// Colisiones de pildoras
	for (unsigned int i=0;i<pildoras.size();i++) {
			if(Collision::PixelPerfectTest(pildoras[i].getSprite(),nave.getSprite()) && !pildoras[i].bonusPack) {
				pildoras[i].setEstado();
				pill_sound.Play();
				// TODO: Logica para puntaje si se alcanzo una pildora.
				cout << "BONUS SUPER PACK DE LA PILDORA: CARGAR BALAS." << endl;
				
				
				if (!pildoras[i].impactado) {
					nave.SetColor(50,255,50);
					puntaje+=100;
					municion+=150;
				}
				pildoras[i].impactado = true;
				
			}
	}	
	vector<Pildora>::iterator it_auxPildora;
	vector<Pildora>::iterator itPildora = pildoras.begin();
	for (unsigned int i=0;i<pildoras.size();i++) {
		if (itPildora != pildoras.end()){
			if (pildoras[i].impactado) {
				it_auxPildora=itPildora;
				++contpill;
				if (contpill == 8) {
					pildoras.erase(itPildora);
					contpill = 0;
				}
				itPildora=it_auxPildora;
				
//				cout<<"pildora borrada"<<endl;
			}
			++itPildora;
		}
		else
			break;
	}
}



/// Start Game


void Game::startGame() {
	balaGenerica = new Bala(text_bala,nave.getPosition().x, nave.getPosition().y);
	
	//Limita los FPS
	win.SetFramerateLimit(60);
	jefe = new Jefe(text_jefe,10.0f,Vector2f(700,200));
	jefe->sp.SetPosition(700,200);	
	jefe->saltando = false;
	//Bucle principal del juego
	fondo_sound.Play();
	while(win.IsOpened()) {
		//Obtiene el tiempor transcurrido entre frame y frame
		tiempo = win.GetFrameTime();
		//Lee los eventos
		while(win.GetEvent(evento)) {
			tiempo = win.GetFrameTime();
			processEvent(evento);
		}
		
		///efectos de la nave (dibujar sprites animados y efecto de arrastre)
		nave.arrastre(evento);
		///fin de efectos de la nave
		
		// Procesa el loop del background de la sangre
		sangre1.moverFondo(-5);
		sangre2.moverFondo(-5);
		
		//	Reposicionando el background de la sangre
		if (sangre1.rotar())
			sangre2.setDerecha();
		else if(sangre2.rotar())
			sangre1.setDerecha();
		
		if(!booster){
			// Procesa el loop del background de la arteria
			arteria.moverFondo(-2);
			arteria2.moverFondo(-2);
			
			//	Reposicionando el background de la arteria
			if (arteria.rotar())
				arteria2.setDerecha();
			if(arteria2.rotar())
				arteria.setDerecha();
		}
		else{
			arteria.moverFondo(-2, false);
			arteria2.moverFondo(-2, false);
			fondoJefe.moverFondo(-2, false);
		}
		
		processCollisions();
		updateGame(tiempo);
		win.Clear(Color(255,255,255,255));
		drawGame();
		win.Display();
	}
}

void Game::sumarPuntaje(int p) {
	puntaje += p;
	stringstream out1;
	out1<<"Puntos: "<<puntaje<<endl<<"Municion: "<<municion;
	string aux = out1.str();
	s_puntaje = (String)aux;
	s_puntaje.SetPosition(10,530);
}
