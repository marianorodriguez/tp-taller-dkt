#ifndef __GRANADA_H__
#define __GRANADA_H__

#include "ExplosivaPorTiempo.h"

class Granada: public ExplosivaPorTiempo
{

public:
	Granada(void);
	Granada(float x, float y, short int rotacion, b2World* world, bool estatico, float radioExplosion, float radioArma, float masa, int tiempoExplosion);
	~Granada(void);
	void disparar(bool sentido, float potencia, float angulo);
	void BeginContact();

};

#endif