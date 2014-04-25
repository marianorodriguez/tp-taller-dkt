#include "ScrollingSprite.h"


ScrollingSprite::ScrollingSprite(SDL_Renderer* renderer, SDL_Rect rect, string path): DibujableTextura(){

	this->rec = rect;
	this->textura = IMG_LoadTexture(renderer, path.c_str());
	this->velocidadRefresco = timeStepNubes;
	
	this->anchoEscenario = ParserYaml::getParser()->getEscenario()->anchoPx;
	//printf("%i", this->anchoEscenario);
	this->contador=0;
}


ScrollingSprite::~ScrollingSprite(){
}

void ScrollingSprite::dibujar(SDL_Renderer* renderer, int corrimientoX,int corrimientoY, float escalaZoom, int posZoomX, int posZoomY){

	SDL_Rect rectAux = rec;
	rectAux.x += corrimientoX;
	rectAux.y += corrimientoY;
	
	if ((escalaZoom != escalaZoomDefault) && (escalaZoom <= zoomMax) && (escalaZoom >= zoomMin)) {
		rectAux = realizarZoom(rectAux, posZoomX, posZoomY, escalaZoom);
		SDL_RenderCopy(renderer, this->textura , NULL , &rectAux);
	} else {
		SDL_RenderCopy(renderer, this->textura, NULL, &rectAux);
	}
	
	contador++;
	if(contador >= this->velocidadRefresco){
		rec.x++;
		contador = 0;
	}

	if(rec.x >= this->anchoEscenario) rec.x = -rec.w;
	
}