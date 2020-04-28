#include <iostream>
#include "Arbin.h"

int solucion(const Arbin<char> &arbin, int monstruos, int caballeros);

using namespace std;


//Nodo a salvo
//  Dama == 1
//  numMonstruos <= numCaballeros
int num_a_salvo(const Arbin<char>& mapa) {
    int numMonstruos = 0, numCaballeros = 0;
    return solucion(mapa, numMonstruos, numCaballeros);
}

//El ejercicio no deja claro si las damas solo pueden estar en las hojas, en este caso
//tomamos como que pueden estar en cualquier posicion debido a la mayor dificultad del problema
//(([D]M([M]D[D]))C(#M(([D]C[M])M([D]M[C])))) Arbol de prueba
int solucion(const Arbin<char> &mapa, int monstruos, int caballeros) {
    int ret = 0;

    //Prepara la solucion
    if (mapa.raiz() == 'M') monstruos++;
    else if (mapa.raiz() == 'C') caballeros++;
    else if (mapa.raiz() == 'D'){
        if (monstruos <= caballeros){
            ret += 1;
        }
    }

    //Caso recursivo
    if(!mapa.hijoIz().esVacio()){
        ret += solucion(mapa.hijoIz(), monstruos, caballeros);
    }
    if(!mapa.hijoDer().esVacio()){
        ret += solucion(mapa.hijoDer(), monstruos, caballeros);
    }

    return ret;
}

Arbin<char> lee_arbol(istream& in) {
    char c;
    in >> c;
    switch (c) {
        case '#': return Arbin<char>();
        case '[': {
            char raiz;
            in >> raiz;
            in >> c;
            return Arbin<char>(raiz);
        }
        case '(': {
            Arbin<char> iz = lee_arbol(in);
            char raiz;
            in >> raiz;
            Arbin<char> dr = lee_arbol(in);
            in >> c;
            return Arbin<char>(iz, raiz, dr);
        }
        default: return Arbin<char>();
    }
}

int main() {
    while (cin.peek() != EOF)  {
        Arbin<char> mapa = lee_arbol(cin);
        string resto_linea;
        getline(cin, resto_linea);
        cout << num_a_salvo(mapa) << endl;
    }
    return 0;
}