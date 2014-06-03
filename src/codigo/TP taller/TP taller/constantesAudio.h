#ifndef CONSTANTESAUDIO_H_
#define CONSTANTESAUDIO_H_

#define rutaSonidoExplosion "audio/efectos/Explosion.wav"
#define rutaSonidoAgua "audio/efectos/Agua.wav"
#define rutaSonidoAleluya "audio/efectos/Aleluya.wav"
#define rutaSonidoImpactoAleluya "audio/efectos/ImpactoAleluya.wav"
#define rutaSonidoImpactoGranada "audio/efectos/ImpactoGranada.wav"
#define rutaSonidoSoltarGranada "audio/efectos/SoltarGranada.wav"
#define rutaSonidoCargandoDisparo "audio/efectos/CargandoDisparo.wav"
#define rutaSonidoSoltarDisparo "audio/efectos/SoltarDisparo.wav"
#define rutaSonidoRisa "audio/efectos/Risa.wav"
#define rutaSonidoMecha "audio/efectos/Mecha.wav"
#define rutaSonidoPonteACubierto "audio/efectos/PonteACubierto.wav"
#define rutaSonidoSalto "audio/efectos/Salto.wav"
#define rutaSonidoWalk "audio/efectos/Walk.wav"
#define rutaSonidoOuch "audio/efectos/Ouch.wav"
#define rutaSonidoImpactoBanana "audio/efectos/ImpactoBanana.wav"
#define rutaSonidoEnemigoALas12 "audio/efectos/EnemigoALas12.wav"
#define rutaSonidoTimerTick "audio/efectos/TIMERTICK.wav"

#define rutaMusicaFondo "audio/ingame-04-battlezone.wav"

//NO CAMBIAR ESTOS VALORES
typedef enum{
	MUSICAFONDO,
	EXPLOSION,
	AGUA,
	SONIDOALELUYA,
	IMPACTOALELUYA,
	IMPACTOGRANADA,
	IMPACTOBANANA,
	ENEMIGOALAS12,
	CARGANDODISPARO,
	SOLTARDISPARO,
	SOLTARGRANADA,
	RISA,
	MECHA,
	ACUBIERTO,
	CAMINANDO,
	SALTO,
	OUCH,
	TIMERTICK,
	NINGUNO,
}sonido;

typedef struct{
	Mix_Chunk* efecto;
	int canal;
	int loops;
	bool activo;
}audio;


#endif