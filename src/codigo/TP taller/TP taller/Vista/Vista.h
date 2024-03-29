#ifndef __VISTA_H__
#define __VISTA_H__
#include "Dibujables/DibujableTextura.h"
#include "Dibujables/DibujableTerreno.h"
#include "Dibujables/CirculoDibujable.h"
#include "Dibujables/PoligonoDibujable.h"
#include "Dibujables\RectanguloDibujable.h"
#include "Dibujables\CartelDibujable.h"
#include "Dibujables\GusanoDibujable.h"
#include "Dibujables/CartelInfo.h"
#include "Dibujables/PanelArmas.h"
#include "Sprite/Sprite.h"
#include "Sprite\GusanoSprite.h"
#include "Sprite/ScrollingSprite.h"
#include "../Parser/yaml/ParserYaml.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include "Dibujables\AContactoDibujable.h"
#include "Dibujables\ATiempoDibujable.h"
#include "Sprite\RelojSprite.h"
#include "../Modelo/MotorParticulas/MotorParticulas.h"
using namespace std;

typedef enum{
	DERECHA,
	IZQUIERDA,
	ARRIBA,
	ABAJO,
	ENTER,
	ESPACIO,
	SOLTARDERECHA,
	SOLTARIZQUIERDA,
	SOLTARARRIBA,
	SOLTARABAJO,
	SOLTARENTER,
	SOLTARESPACIO,
	PAUSAR,
	JUGAR,
	SALIR,
	CLICK,
	CLICKDERECHO,
	CLICKARMA,
	
}ACCION_REALIZADA;

class Vista
{

private:

	
	
	
	int anchoPx;
	int altoPx;
	int anchoPxTot;
	int altoPxTot;
	float corrimientoX;
	float corrimientoY;
	ACCION_REALIZADA accion;
	float escalaZoom;

public:

	list<Dibujable*>* listaDibujables;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Vista(EscenarioParseado* e,SDL_Window* window, SDL_Renderer* renderer);
	Vista();
	~Vista();
	MotorParticulas* motor;
	SDL_Renderer* getRenderer();
	DibujableTextura* crearDibujableTextura(int x , int y ,int ancho,int alto, string pathImagen, string imagenDEF);
	Sprite* crearSprite(int x, int y, int anchoFrame, int altoFrame, string path, int col, int fil, int anchoTex, int altoTex);
	RelojSprite* crearRelojSprite(int x, int y, int anchoFrame, int altoFrame, string path, int col, int fil, int anchoTex, int altoTex);
	void crearScrollingSprite(int x, int y, int ancho, int alto, string path);
	CirculoDibujable* crearCirculoDibujable(int x , int y ,int radioHorizontal,int radioVertical);
	PoligonoDibujable* crearPoligonoDibujable(short int n, float escalaAncho, float escalaAlto);
	RectanguloDibujable* crearRectanguloDibujable(float ancho, float alto);
	GusanoDibujable* crearGusanoDibujable(int x, int y, int ancho, int alto, string pathImagen, string imagenDef);
	GusanoSprite* crearGusanoSprite(int x, int y, int anchoFrame, int altoFrame, string path, int col, int fil, int anchoTex, int altoTex,string nombre,int maximosClientes);
	CartelInfo* crearCartelInfo(int x, int y, int ancho, int alto);
	ATiempoDibujable* crearArmaTiempoDibujable(int x, int y, int ancho, int alto, string pathImagen, string imagenDef);
	AContactoDibujable* crearArmaContactoDibujable(int x, int y, int ancho, int alto, string pathImagen, string imagenDef);
	PanelArmas* Vista::crearPanelArmas(int x , int y , int ancho, int alto, vector<int> armas);
	void agregarDibujable(Dibujable* dibujable);
	list<Dibujable*>* getListaDibujables();
	void setListaDibujables(list<Dibujable*>* dibujables);
	void Dibujar();
	int getAnchoPx();
	int getAltoPx();
	bool leerEvento(SDL_Event* evento);
	ACCION_REALIZADA getAccion();
	float getCorrimientoX();
	float getCorrimientoY();
	float getZoom();
	void setZoom(float escala);
	void scroll(int x ,int y );
	void zoom(SDL_Event* evento,int x, int y);
	void validarCorrimiento();
	
	DibujableTerreno* crearDibujableTerreno(int x , int y ,int ancho,int alto, string pathImagen, string imagenDEF);
	
	void limpiar();

	void destruir(float x,float y,int radio, LectorTerreno* lector);
};

#endif