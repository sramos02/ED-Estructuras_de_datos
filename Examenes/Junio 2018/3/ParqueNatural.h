#include "lista.h"
#include "diccionario.h"
#include "DiccionarioHash.h"
#include <string>
using namespace	std;

//Excepciones
class EEcosistemaDuplicado {};
class EEcosistemaNoExiste {};

//Clase principal
class ParqueNatural {
public:
	void crea();
	void an_ecosistema(string ecosistema);
	void an_ejemplares(string ecosistema, string especie, int n);
	Lista<string> lista_especies_ecosistema(string ecosistema, int n);
	int numero_ejemplares_en_ecosistema(string ecosistema, string especie);
	Lista<string>lista_especies_parque();
	int numero_ejemplares_en_parque(string especie);

private:

	class Ecosistema {
	public:
		int numEjemplares;
		DiccionarioHash<string, int> especiesEco;
		Lista<string> listaEspeciesEcosistema;
		Ecosistema() { numEjemplares = 0; }
	};

	Diccionario<string, Ecosistema> listaEcosistemas;
	Lista<string> listaEspeciesParque;
};