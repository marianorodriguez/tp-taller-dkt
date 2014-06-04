#ifndef CTTES_ARMAS_H_
#define CTTES_ARMAS_H_

#define rutaCrosshair "imagenes/texturas/crosshair.png"
#define rutaBaz "imagenes/texturas/bazIzq.png"
#define rutaGranada "imagenes/texturas/granada.png"
#define rutaAleluya "imagenes/texturas/aleluya.png"
#define rutaBanana "imagenes/texturas/banana.png"
#define rutaDinamita "imagenes/texturas/dinamita.png"
#define rutaMisil "imagenes/texturas/Misil.png"
#define rutaWormBaz "imagenes/texturas/wormConBazookaIzq.png"
#define rutaWormGran "imagenes/texturas/wormGran.png"
#define rutaWormAle "imagenes/texturas/wormAleluya.png"
#define rutaWormDin "imagenes/texturas/wormConDinamita.png"
#define rutaWormBan "imagenes/texturas/wormConBanana.png"
#define rutaWormRadio "imagenes/texturas/wormConRadio.png"



const int POTENCIA_MAXIMA_DISPARO = 40;
const float AUMENTO_POTENCIA = 0.4;

const float anchoBazooka = 1.4;
const float altoBazooka = 1;
const int masaBazooka = 30;

const float radioGranada = 0.8;
const float masaGranada = 5;
const int tiempoExplosionGranada = 3; //hay q poder variar este valor

const float radioAleluya = 1;
const int masaAleluya = 5;
const int tiempoExplosionAleluya = 3;

const float altoDinamita = 2;
const float anchoDinamita = 1;
const int masaDinamita = 5;
const int tiempoExplosionDinamita = 5;

const float radioBanana = 1;
const float radioMiniBanana = 0.5;
const int masaBanana = 5;
const int tiempoExplosionBanana = 5;
const int tiempoExplosionMiniBanana = 3;

const float anchoMisiles = 3;
const float altoMisiles = 2;
const int masaMisiles = 30;

//PARA EXPLOSIONES
const float radioExplosionGusano = 3;
const float radioExplosionGranada = 4;
const float radioExplosionBazooka = 5;
const float radioExplosionDinamita = 6;
const float radioExplosionAleluya = 7;
const float radioExplosionBanana = 8;
const float radioExplosionMiniBanana = 4;
const float radioExplosionMisiles = 3;

////////// TIPOS DE ARMAS ////////////
typedef enum{
	NINGUNA,
	BAZOOKA,
	GRANADA,
	ALELUYA,
	DINAMITA,
	BANANA,
	MISILES,
}tipoArma;
//////////////////////////////////////

#endif