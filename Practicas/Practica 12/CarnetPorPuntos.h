
#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "lista.h"
#include "diccionario.h"
#include <string>
using namespace std;

const static int MAX_PUNTOS = 15;

class EConductorDuplicado {};
class EConductorNoExiste {};
class EPuntosNoValidos {};

class CarnetPorPuntos {
public:
   void nuevo(const string& dni);
   void quitar(const string& dni, unsigned int puntos);
   void recuperar(const string& dni, unsigned int puntos);
   unsigned int consultar(const string& dni) const;
   unsigned int cuantos_con_puntos(unsigned int puntos) const;
   const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:
    class Conductor {
    public:
        int puntos;
        Conductor() { puntos = 15; }
   };

    class Puntos {
    public:
        Diccionario<string, Conductor> lista;
        int conductores;
    };

    Diccionario<string, Conductor> listaConductores;
    Puntos listaPorPuntos[MAX_PUNTOS];
};

#endif