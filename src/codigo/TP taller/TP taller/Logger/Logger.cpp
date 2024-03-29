#include "Logger.h"
#include "../constantes.h"

Logger* Logger::logInstancia = NULL;

Logger::Logger(){

	ofstream* arch = new ofstream;
	arch->open(archivoLog, ofstream::trunc);
	archivo = arch;

	ponerFecha();
}

void Logger::escribir(string texto){
	//this->archivo->open(archivoLog, ofstream::app);
	this->archivo->write(texto.c_str(), strlen(texto.c_str()));
	this->archivo->write("\n", strlen("\n"));
	//this->archivo->close();
}

void Logger::guardarEstado(){

	this->archivo->close();
	this->archivo->open(archivoLog, ofstream::app);

}

void Logger::ponerFecha(){
	time_t fecha;
	time ( &fecha);
	string sfecha = ctime (&fecha); 

	string guion = "-----------------------------------------------------------------";
	escribir(guion);
	sfecha.append(guion);
	escribir(sfecha);
}

Logger::~Logger(){

	this->archivo->close();
	delete this->archivo;
}

Logger* Logger::getLogger(){

	if(logInstancia == NULL) logInstancia = new Logger();

	return logInstancia;
}