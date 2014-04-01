#include "Vista.h"
#include "Sprite/Sprite.h"

Vista::Vista(EscenarioParseado* e){
	SDL_Init( SDL_INIT_EVERYTHING );
	this->window = SDL_CreateWindow("Worms!", 50, 50, e->anchoPx, e->altoPx,  SDL_WINDOW_SHOWN );
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	this->listaDibujables = new list<Dibujable*>;
	this->crearDibujableTextura(0, 0,e->anchoPx, e->altoPx, e->imagenCielo);
	this->crearDibujableTextura(0, e->nivelAgua * e->altoPx / e->altoU, e->anchoPx,(e->altoU - e->nivelAgua) * e->altoPx / e->altoU,texturaAgua);
	this->crearSprite(0, e->nivelAgua * e->altoPx / e->altoU, e->anchoPx, 15, spriteOlas, 2, 6, 256, 144);
	
}

Vista::~Vista() {
	delete this->window;
	delete this->renderer;
	delete this->listaDibujables;
}
SDL_Renderer* Vista::getRenderer() {
	return this->renderer;
}

void Vista::crearSprite(int x, int y, int anchoFrame, int altoFrame, string path, int col, int fil, int anchoTex, int altoTex){

	SDL_Rect recFrame;
	recFrame.x = x;
	recFrame.y = y;
	recFrame.w = anchoFrame;
	recFrame.h = altoFrame;
	Sprite* sprite = new Sprite(this->renderer, recFrame, path, col, fil, anchoTex, altoTex);
	this->agregarDibujable(sprite);
	
}

DibujableTextura* Vista::crearDibujableTextura(int x , int y ,int ancho,int alto, string pathImagen) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = ancho;
	rect.h = alto;
	
	DibujableTextura* dib = new DibujableTextura(this->renderer, rect, pathImagen);
	this->agregarDibujable(dib);
	return dib;
}

CirculoDibujable* Vista::crearCirculoDibujable(int x , int y ,int radioHorizontal, int radioVertical) {
	CirculoDibujable* dib = new CirculoDibujable(x,y,radioHorizontal,radioVertical);
	this->agregarDibujable(dib);
	return dib;
}

void Vista::agregarDibujable(Dibujable* dibujable) {
	this->listaDibujables->push_back(dibujable);
}

list<Dibujable*>* Vista::getListaDibujables(){
	return this->listaDibujables;
	
}

void Vista::Dibujar(){
	SDL_RenderClear(this->renderer);
	for (list<Dibujable*>::iterator it = this->listaDibujables->begin(); it != this->listaDibujables->end(); it++) {
		(*it)->dibujar(this->renderer);
	}
	SDL_RenderPresent(this->renderer);
}

