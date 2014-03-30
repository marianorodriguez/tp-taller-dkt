#include "Dibujable.h"

Dibujable::Dibujable(){}

Dibujable::Dibujable(SDL_Renderer* renderer, SDL_Rect rect, string pathImagen) {
	this->rect = rect;
	this->imagen = IMG_LoadTexture(renderer, pathImagen.c_str());
	this->anguloRotacion = 0;
};

Dibujable::~Dibujable() {
	delete this->imagen;
}

SDL_Texture* Dibujable::getImagen(){
	return this->imagen;
}

SDL_Rect Dibujable::getRect(){
	return this->rect;
}

void Dibujable::setRect(SDL_Rect rect) {
	this->rect = rect;
}

int Dibujable::getAngulo() {
	return this->anguloRotacion;
}

void Dibujable::setAngulo(int angulo) {
	this->anguloRotacion = angulo;
}

void Dibujable::setColor(int* rgb){
	SDL_SetTextureColorMod(this->imagen,rgb[0],rgb[1],rgb[2]);
}

void Dibujable::dibujar(SDL_Renderer* renderer){
	SDL_RenderCopyEx(renderer,this->getImagen(),NULL, &this->getRect(),this->getAngulo(),NULL,SDL_FLIP_NONE);
}