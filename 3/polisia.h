//
// Created by Kaemis on 02/05/2020.
//

#ifndef EXAMENES_POLISIA_H
#define EXAMENES_POLISIA_H

//includes
#include <string.h>
#include "lista.h"
using namespace std;

//exceptions
class ConductorDuplicado{};
class ConductorInexistente{};
class PuntosNoValidos{};

//TAD
class polisia{

private:

    class conductor{
    public :
        int puntos;
        string dni;
    };

    Lista<conductor> poblacion;

public:

    //Añade un nuevo conductor identificado por su dni (un string), con 15 puntos.
    void nuevo(string dni){
        Lista<conductor>::Iterator it = poblacion.begin();
        if(buscaDni(dni, it)) throw ConductorDuplicado();
        conductor nuevo;
        nuevo.dni = dni;
        nuevo.puntos = 15;
        poblacion.pon_final(nuevo);
    }

    //Le resta puntos a un conductor tras una infracción. Si a un conductor se le quitan
    //más puntos de los que tiene, se quedará con 0 puntos. Si los puntos resultantes de
    //esta operación son los mismos que los que tiene el conductor actualmente, entonces
    //la operación debe ignorarse.
    void quitar(string dni, int puntos){
        Lista<conductor>::Iterator it = poblacion.begin();
        if(!buscaDni(dni, it)) throw ConductorInexistente();
        conductor cond = it.elem();
        cond.puntos -= puntos;
        if(cond.puntos < 0) cond.puntos = 0;
        it.set(cond);
    }

    //Le añade puntos a un conductor enmendado. Si debido a una recuperación un conductor supera
    //los 15 puntos, se quedará con 15 puntos. Si los puntos resultantes de esta operación son
    //los mismos que los que tiene el conductor actualmente, entonces la operación debe ignorarse.
    void recuperar(string dni, int puntos){
        Lista<conductor>::Iterator it = poblacion.begin();
        if(!buscaDni(dni, it)) throw ConductorInexistente();
        if(puntos > 0) {
            conductor cond = it.elem();
            cond.puntos += puntos;
            if(cond.puntos > 15) cond.puntos = 15;
            it.set(cond);
        }
    }

    //Devuelve los puntos actuales de un conductor.
    int consultar(string dni){
        Lista<conductor>::Iterator it = poblacion.begin();
        if(!buscaDni(dni, it)) throw ConductorInexistente();
        return it.elem().puntos;
    }

    //Devuelve cuántos conductores tienen un determinado número de puntos.
    int cuantos_con_puntos(int puntos){
        if(puntos < 0 || puntos > 15) throw PuntosNoValidos();
        int cont = 0;

        Lista<conductor>::ConstIterator cit = poblacion.cbegin();
        for(;cit != poblacion.cend();cit.next()) {
            if(cit.elem().puntos == puntos)
                cont++;
        }
        return cont;
    }



protected:

    bool buscaDni(string dni, Lista<conductor>::Iterator &ret){
        Lista<conductor>::Iterator cit = poblacion.begin();
        for(;cit != poblacion.end();cit.next()){
            if(cit.elem().dni == dni) {
                ret = cit;
                return true;
            }
        }
        return false;
    }
};

#endif //EXAMENES_POLISIA_H
