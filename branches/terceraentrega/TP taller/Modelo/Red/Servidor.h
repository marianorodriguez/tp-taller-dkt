#include "ServidorRed.h"
#include "../Figuras/Gusano.h"
#include "../../Parser/yaml/ParserYaml.h"

typedef struct structCliente{
	string username;
	int time;
	SOCKET socket;
	bool enviandoData;
	bool activo;
	list<Gusano*> figuras;
	string ultimoEventoSerializado;
	//Sesion* sesion;
}cliente;

class Servidor
{

public:

    Servidor();
    ~Servidor();
	static EscenarioParseado* escenario;
    static void actualizar(void* clienteN);
	static void recibirDeCliente(int* clienteN);
	static void enviarCliente(int* clienteN, int tipoPaquete, string mensaje);
	static string dibujablesSerializados;

	void enviarAeClientes(char* mensaje);
	static void enviarImagen(SOCKET sock, string direccion, int tipoPaquete);
	static ServidorRed* red;
	static void aceptarClientes(void* arg);
	static void enviarEscenario(int num_cliente);
	static void enviarImagenes(SOCKET sock);
	static cliente* clientes;
	

private:

   // IDs for the clients connecting for table in ServerNetwork 
    static unsigned int cliente_id;

   static int buscarCliente(string nombre);
   static void enviarPaquete(SOCKET sock, int tipoPaquete, string mensaje);
   bool clienteEnEspera;

   // The ServerNetwork object 

   
    
};