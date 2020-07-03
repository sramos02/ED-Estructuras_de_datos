#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "lista.h"
#include "diccionarioHash.h"
#include <string>
using namespace std;

const static int MAX_PUNTOS = 15;

class EConductorDuplicado {};
class EConductorNoExiste {};
class EPuntosNoValidos {};


class CarnetPorPuntos {
public:
    CarnetPorPuntos();
    void nuevo(const string& dni);
    void quitar(const string& dni, unsigned int puntos);
    void recuperar(const string& dni, unsigned int puntos);
    unsigned int consultar(const string& dni) const;
    unsigned int cuantos_con_puntos(unsigned int puntos) const;
    const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:

    class Conductor {
    public: 
        Lista<string>::Iterator pos = Lista<string>().begin();

        int puntos;
        Conductor(unsigned int pu, const Lista<string>::Iterator& po) {
            pos = po;
            puntos = pu;
        } 
        Conductor(const Lista<string>::Iterator& p) {
            pos = p;
            puntos = MAX_PUNTOS;
        }
    };

    DiccionarioHash<string, Conductor> listaConductores;
    DiccionarioHash<int, Lista<string>> listaPorPuntos;
};

#endif