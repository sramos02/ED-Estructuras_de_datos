#ifndef PRACTICA_2_SECUENCIA_H
#define PRACTICA_2_SECUENCIA_H

//Librerias
#include <iostream>
using namespace std;

//Excepciones
class ElementoInvalido{};

template <class T>
class Secuencia{

public:
    int _max;
    int _tam;
    T *_elementos;

    //Constructor
    Secuencia(){
        _max = 2;
        _tam = 0;
        _elementos = new T[_max];
    }


    //Operación mutadora que inserta un elemento
    void pon(const T& e) {
        if(_tam == _max) redimensiona();
        _elementos[_tam] = e;
        _tam ++;
    }

    //Observador que muestra la posicion pos
    const T& elem(int i) {
        if(i < 0 || i >= _tam) throw ElementoInvalido();
        return _elementos[i];
    }

    //Obervadora que devuelve el numero de argumentos
    int num_elems() const {
        return _tam;
    }

private:
    void redimensiona() {
        _max *= 2;
        T *aux = new T[_max];
        aux = _elementos;
        _elementos = aux;
    }

};



#endif //PRACTICA_2_SECUENCIA_H
