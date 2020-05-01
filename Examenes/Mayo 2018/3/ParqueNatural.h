#ifndef EXAMENES_PARQUENATURAL_H
#define EXAMENES_PARQUENATURAL_H

/// Excepciones generadas por algunos métodos
class EcosistemaDuplicado{};
class EcosistemaNoExiste{};

///Librerías necesarias
#include <string>
#include "lista.h"
#include "pila.h"
using namespace std;

class Parque {

private:

    //Información interna del parque

    class Especie {
    public:
        string idEspecie;
        int ejemplares;
    };

    class Ecosistema {
    public:
        string idEcosistema;
        Lista<Especie> especies;

    protected:

    };

    //Lista de ecosistemas del parque
    Lista<Ecosistema> parque;

public:

    //Crea un parque natural vacío
    void crea() {}

    //Añade un nuevo ecosistema con identicador ecosistema al parque.
    //Si el ecosistema ya existe, levanta una excepción EEcosistemaDuplicado.
    void an_ecosistema(string id) {
        Lista<Ecosistema>::Iterator it = parque.begin();
        if (buscaEcosistema(id, it)) throw EcosistemaDuplicado();
        else {
            Ecosistema nuevo;
            nuevo.idEcosistema = id;
            parque.pon_final(nuevo);
        }
    }

    //Añade n ejemplares de la especie con identicador especie al ecosistema con
    //identicador ecosistema. Si ecosistema no existe,levanta una excepción EEcosistemaNoExiste.
    //Si la especie ya habita en el ecosistema se incrementará su número de ejemplares en n; si
    //la especie no habita en el ecosistema, se registrará en el ecosistema esa nueva especie con
    //ese número de ejemplares.
    void an_ejemplares(string ecosistema, string especie, int n) {
        Lista<Ecosistema>::Iterator it = parque.begin();
        if (!buscaEcosistema(ecosistema, it)) throw EcosistemaNoExiste();
        else {
            Ecosistema eco = it.elem();
            Especie nuevaEspecie;
            Lista<Especie>::Iterator it2 = eco.especies.begin();
            if (buscaEspecie(eco.especies, especie, it2)) {
                nuevaEspecie.idEspecie = especie;
                nuevaEspecie.ejemplares = it2.elem().ejemplares + n;
                it2.set(nuevaEspecie);
            } else {
                nuevaEspecie.idEspecie = especie;
                nuevaEspecie.ejemplares = n;
                eco.especies.pon_final(nuevaEspecie);
            }
            it.set(eco);
        }
    }

    //Devuelve una lista con los identicadores de las n últimas nuevas especies añadidas al
    //ecosistema de identicador ecosistema, ordenadas por orden inverso de inserción (es decir,
    //primero la última nueva añadida, segundo la penúltima nueva añadida, y así sucesivamente).
    //Si ecosistema no existe, levanta una excepción EEcosistemaNoExiste.
    Lista<string> lista_especies_ecosistema(string ecosistema, int n) {
        Lista<string> listaEspecies;
        Lista<Ecosistema>::Iterator it = parque.begin();
        if (buscaEcosistema(ecosistema, it)) throw EcosistemaNoExiste();
        else {
            Ecosistema act = it.elem();
            Lista<Especie>::Iterator it2 = act.especies.begin();
            Pila<string> inversor;

            //Introduce en la lista las ultimas n especies en orden inverso de inserción
            //Utilizando una pila con estructura LIFO
            for(int i = 0; i < n; i++){
                inversor.apila(it2.elem().idEspecie);
                it2.next();
            }
            while(!inversor.esVacia()){
                listaEspecies.pon_final(inversor.cima());
                inversor.desapila();
            }
        }
        return listaEspecies;
    }

    //Devuelve la cantidad de ejemplares de la especie especie que habitan el ecosistema ecosistema.
    //Si el ecosistema no existe, levanta una excepción EEcosistemaNoExiste. Si la especie no habita
    //en el ecosistema, la operación devolverá 0 ejemplares.
    int numero_ejemplares_en_ecosistema(string ecosistema, string especie) {
        int ret = 0;
        Lista<Ecosistema>::Iterator it = parque.begin();
        if (!buscaEcosistema(ecosistema, it)) throw EcosistemaNoExiste();

        Ecosistema eco = it.elem();
        Lista<Especie>::Iterator it2 = eco.especies.begin();
        if (buscaEspecie(eco.especies, especie, it2)) {
            ret += it2.elem().ejemplares;
        }
        return ret;
    }

    //Devuelve una lista de todas las especies del parque, ordenada alfabéticamente.
    Lista<Especie>lista_especies_parque(){
        //No pienso hacer esto, es una sobrada para un examen de 3 horas
    }

    //Devuelve el número de ejemplares que hay de la especie especie en el parque.
    //Si la especie no habita en el parque, la operación devolverá 0 ejemplares.
    int numero_ejemplares_en_parque(string especie){
        int ret = 0;
        Lista<Ecosistema>::Iterator it = parque.begin();
        while(it != parque.end()) {
            Ecosistema eco = it.elem();
            Lista<Especie>::Iterator it2 = eco.especies.begin();
            if (buscaEspecie(eco.especies, especie, it2)){
                ret += it2.elem().ejemplares;
            }
            it.next();
        }
        return ret;
    }

protected:

    //Busca si existe el ecosistema con id dado, si es así devuelve su posición O(1)
    int buscaEcosistema(string id, Lista<Ecosistema>::Iterator &pos){
        Lista<Ecosistema>::Iterator it = parque.begin();
        while(it != parque.end()){
            if(it.elem().idEcosistema == id){
                pos = it;
                return true;
            }
            it.next();
        }
        return false;
    }

    bool buscaEspecie(Lista<Especie> especies, string id, Lista<Especie>::Iterator &it) {
        while(it != especies.end()){
            if(it.elem().idEspecie == id) {
                return true;
            }
            it.next();
        }
        return false;
    }

};

#endif //EXAMENES_PARQUENATURAL_H
