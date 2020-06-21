#ifndef _PARQUE_ATRACCIONES_H
#define _PARQUE_ATRACCIONES_H
#include <string>

#include "lista.h"
#include "diccionario.h"
#include "pila.h"
using namespace std;

class EAtraccionYaExiste {};
class ENinioYaRegistrado {};
class EAtraccionNoExiste {};
class ENinioNoRegistrado {};
class EAccesoAtraccion {};
class EConsultaNumViajes {};


class ParqueDeAtracciones {
public:
   ParqueDeAtracciones();
   void an_atraccion(const string& nombre_atraccion);
   void an_ninio(const string& nombre_ninio);
   void poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion);
   void avanzar(const string& nombre_atraccion);
   Lista<string> atracciones_visitadas(const string& nombre_ninio) const;
   int numero_visitas(const string& nombre_ninio,const string& nombre_atraccion) const;
private:

    class Ninio { 
    public:
        bool enCola;
        Diccionario<string, int> atracciones_montadas;
        Ninio() { enCola = false; };
   };

    class Atraccion {
    public:
        Diccionario<string, int> historial;
        Lista<string> cola;
        Atraccion() {};
    };

    Diccionario<string, Ninio> listaNinios;
    Diccionario<string, Atraccion> listaAtracciones;
};

#endif