#include "CarnetPorPuntos.h"


/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/

CarnetPorPuntos::CarnetPorPuntos() {
    listaPorPuntos.inserta(MAX_PUNTOS, Lista<string>());
}

//COMPLEJIDAD: O(1) debido al uso exclusivo de diccionarios y resto de operaciones y declaraciones constantes
void CarnetPorPuntos::nuevo(const string& dni) {
    if (listaConductores.contiene(dni)) throw EConductorDuplicado();

    DiccionarioHash<int, Lista<string>>::Iterator it = listaPorPuntos.busca(MAX_PUNTOS);

    it.valor().pon_ppio(dni);
    listaConductores.inserta(dni, it.valor().begin());
}

//COMPLEJIDAD: O(1) debido al uso exclusivo de diccionarios 
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
    if (!listaConductores.contiene(dni)) throw EConductorNoExiste();
   
    DiccionarioHash<string, Conductor>::Iterator conductor = listaConductores.busca(dni);
    if (conductor.valor().puntos != 0) {

        //Calculamos los nuevos puntos
        int nuevosPuntos = conductor.valor().puntos - puntos;
        if (nuevosPuntos < 0) nuevosPuntos = 0;

        if (conductor.valor().puntos != nuevosPuntos) {

            //Genera si es necesario un nuevo nivel de puntos
            if (!listaPorPuntos.contiene(nuevosPuntos)) listaPorPuntos.inserta(nuevosPuntos, Lista<string>());

            listaPorPuntos.busca(conductor.valor().puntos).valor().eliminar(conductor.valor().pos);
            listaPorPuntos.busca(nuevosPuntos).valor().pon_ppio(dni);
            listaConductores.busca(dni).setVal(Conductor(nuevosPuntos, listaPorPuntos.busca(nuevosPuntos).valor().begin()));
        }
    }
}

//COMPLEJIDAD: O(1) debido al uso exclusivo de diccionarios 
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
    if (!listaConductores.contiene(dni)) throw EConductorNoExiste();
   
    DiccionarioHash<string, Conductor>::Iterator conductor = listaConductores.busca(dni);
    if (conductor.valor().puntos != MAX_PUNTOS) {

        int nuevosPuntos = conductor.valor().puntos + puntos;
        if (nuevosPuntos > MAX_PUNTOS) nuevosPuntos = MAX_PUNTOS;

        if (conductor.valor().puntos != nuevosPuntos) {
            //Genera si es necesario un nuevo nivel de puntos
            if (!listaPorPuntos.contiene(nuevosPuntos)) listaPorPuntos.inserta(nuevosPuntos, Lista<string>());

            listaPorPuntos.busca(conductor.valor().puntos).valor().eliminar(conductor.valor().pos);
            listaPorPuntos.busca(nuevosPuntos).valor().pon_ppio(dni);
            conductor.setVal(Conductor(nuevosPuntos, listaPorPuntos.busca(nuevosPuntos).valor().begin()));
        }
    }
}

//COMPLEJIDAD: O(1) debido al uso exclusivo de diccionarios 
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
    if (!listaConductores.contiene(dni)) throw EConductorNoExiste();
   
    DiccionarioHash<string, Conductor>::ConstIterator conductor = listaConductores.cbusca(dni);
    return conductor.valor().puntos;
}

//COMPLEJIDAD: O(1) debido al uso exclusivo de diccionarios 
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
    if (puntos < 0 || puntos > 15) throw EPuntosNoValidos();    
    DiccionarioHash<int, Lista<string>>::ConstIterator it = listaPorPuntos.cbusca(puntos);
   
    if (it != listaPorPuntos.cend()) return it.valor().longitud();
    else return 0;
}

//COMPLEJIDAD: O(1) debido al uso exclusivo de diccionarios 
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
    if (puntos < 0 || puntos > 15) throw EPuntosNoValidos();
    return listaPorPuntos.cbusca(puntos).valor();
}
