#include "GestionaAdmisiones.h"


void Admisiones::an_paciente(string codigo, string nombre, string edad, string sintomas, gravedad gravedad) {
	if (listaEspera[(int)gravedad].contiene(codigo)) throw EPacienteDuplicado();

	Paciente nuevo = Paciente(nombre, edad, sintomas);
	listaEspera[(int)gravedad].inserta(codigo, nuevo);
}

void Admisiones::info_paciente(string codigo, string nombre, string edad, string sintomas) {
	int gravedad;

	if (listaEspera[0].contiene(codigo)) gravedad = 0;
	else if (listaEspera[1].contiene(codigo)) gravedad = 1;
	else if (listaEspera[2].contiene(codigo)) gravedad = 2;
	else throw EPacienteInexistente();

	Diccionario<string, Paciente>::Iterator actual = listaEspera[gravedad].busca(codigo);
	Paciente nuevaInfo = Paciente(nombre, edad, sintomas);
	actual.setVal(nuevaInfo);
}

void Admisiones::siguiente(string & codigo, gravedad & a) {
	int grav;
	if (listaEspera[0].contiene(codigo)) grav = 0;
	else if (listaEspera[1].contiene(codigo)) grav = 1;
	else if (listaEspera[2].contiene(codigo)) grav = 2;
	else throw ENoHayPacientes();
	
	codigo = listaEspera[2].cbegin().clave();
	a = (gravedad)grav;
	listaEspera[grav].borra(codigo);
}

bool Admisiones::hay_pacientes() {
	return listaEspera[0].esVacio() && listaEspera[1].esVacio() && listaEspera[2].esVacio();
}

void Admisiones::elimina(string codigo) {
	int grav;
	if (listaEspera[0].contiene(codigo)) grav = 0;
	else if (listaEspera[1].contiene(codigo)) grav = 1;
	else if (listaEspera[2].contiene(codigo)) grav = 2;
	else { grav = -1; }

	if (grav != -1) {
		listaEspera[grav].borra(codigo);
	}
}