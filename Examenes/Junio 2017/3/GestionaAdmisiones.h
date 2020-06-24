#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;

typedef enum gravedad { LEVE, MEDIA, GRAVE };

class EPacienteDuplicado{};
class EPacienteInexistente{};
class ENoHayPacientes{};

class Admisiones {
public:
	void an_paciente(string codigo,string nombre, string edad, string sintomas, gravedad gravedad);
	void info_paciente(string codigo, string nombre, string edad, string sintomas);
	void siguiente(string codigo, gravedad gravedad);
	bool hay_pacientes();
	void elimina(string codigo);
private:

	class Paciente {
	public:
		string nombre;
		string edad;
		string sintomas;
		Paciente(string nombre, string edad, string sintomas) {
			this->nombre = nombre;
			this->edad = edad;
			this->sintomas = sintomas;
		}
	};

	Diccionario<string, Paciente> listaEspera[3];
};