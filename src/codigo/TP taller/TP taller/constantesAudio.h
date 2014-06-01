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
#define rutaSonidoWalkC "audio/efectos/Walk-Compress.wav"
#define rutaSonidoWalkE "audio/efectos/Walk-Expand.wav"
#define rutaSonidoImpactoBanana "audio/efectos/ImpactoBanana.wav"

#define rutaMusicaFondo "audio/ingame-04-battlezone.wav"

//NO CAMBIAR ESTOS VALORES
typedef enum{
	MUSICAFONDO,
	EXPLOSION,
	AGUA,
	SONIDOALELUYA,
	IMPACTOALELUYA,
	IMPACTOGRANADA,
	CARGANDODISPARO,
	SOLTARDISPARO,
	SOLTARGRANADA,
	CAMINANDO,
	RISA,
	MECHA,
	ACUBIERTO,
	NINGUNO,
	IMPACTOBANANA,
}sonido;

typedef struct{
	Mix_Chunk* audio;
	int canal;
}audio;


#endif