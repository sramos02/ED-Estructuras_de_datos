/**
NOMBRE Y APELLIDOS:
LABORATORIO:
PUESTO:
USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "CarnetPorPuntos.h"


/**
Implementa aquí los métodos de las clases adicionales
*/

 
/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/ 

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::nuevo(const string& dni) {
    if (listaConductores.contiene(dni)) throw EConductorDuplicado();
    
    listaConductores.inserta(dni, Conductor());
    listaPorPuntos[MAX_PUNTOS].lista.inserta(dni, Conductor());
    listaPorPuntos[MAX_PUNTOS].conductores++;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
    if (!listaConductores.contiene(dni)) throw EConductorNoExiste();
    Diccionario<string, Conductor>::Iterator conductor = listaConductores.busca(dni);

    listaPorPuntos[conductor.valor().puntos].lista.borra(dni);
    listaPorPuntos[conductor.valor().puntos].conductores--;

    int nuevosPuntos = conductor.valor().puntos - puntos;
    if (nuevosPuntos < 0)nuevosPuntos = 0;

    listaConductores.busca(dni).valor().puntos = nuevosPuntos;
    listaPorPuntos[nuevosPuntos].lista.inserta(dni, listaConductores.busca(dni).valor());
    listaPorPuntos[nuevosPuntos].conductores++;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
    if (!listaConductores.contiene(dni)) throw EConductorNoExiste();
    Diccionario<string, Conductor>::Iterator conductor = listaConductores.busca(dni);

    listaPorPuntos[conductor.valor().puntos].lista.borra(dni);
    listaPorPuntos[conductor.valor().puntos].conductores--;

    int nuevosPuntos = listaConductores.busca(dni).valor().puntos + puntos;
    if (nuevosPuntos > 15) nuevosPuntos = 15;

    listaConductores.busca(dni).valor().puntos = nuevosPuntos;
    listaPorPuntos[nuevosPuntos].lista.inserta(dni, listaConductores.busca(dni).valor());
    listaPorPuntos[nuevosPuntos].conductores++;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
    if (!listaConductores.contiene(dni)) throw EConductorNoExiste();
    Diccionario<string, Conductor>::ConstIterator conductor = listaConductores.cbusca(dni);

    return listaPorPuntos[conductor.valor().puntos].lista.cbusca(dni).valor().puntos;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
    return listaPorPuntos[puntos].conductores;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
	  // A IMPLEMENTAR
}

