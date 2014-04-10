#include "DibujableTextura.h"

DibujableTextura::DibujableTextura(){}

DibujableTextura::DibujableTextura(SDL_Renderer* renderer, SDL_Rect rect, string pathImagen, string pathDEF) {
	this->rect = rect;
	this->imagen = IMG_LoadTexture(renderer, pathImagen.c_str());
	if(!imagen){
		Logger::getLogger()->escribir("No se encontr� la textura " + pathImagen + ". Se usar� la textura por defecto.");
		this->imagen = IMG_LoadTexture(renderer, pathDEF.c_str());
	}
	this->anguloRotacion = 0;
};

DibujableTextura::~DibujableTextura() {
	delete this->imagen;
}

SDL_Texture* DibujableTextura::getImagen(){
	return this->imagen;
}

SDL_Rect DibujableTextura::getRect(){
	return this->rect;
}

void DibujableTextura::setRect(SDL_Rect rect) {
	this->rect = rect;
}

int DibujableTextura::getAngulo() {
	return this->anguloRotacion;
}

void DibujableTextura::setAngulo(int angulo) {
	this->anguloRotacion = angulo;
}

void DibujableTextura::setColor(int* rgb){
	SDL_SetTextureColorMod(this->imagen,rgb[0],rgb[1],rgb[2]);
}

void DibujableTextura::dibujar(SDL_Renderer* renderer){
	SDL_RenderCopyEx(renderer,this->getImagen(),NULL, &this->getRect(),this->getAngulo(),NULL,SDL_FLIP_NONE);
}