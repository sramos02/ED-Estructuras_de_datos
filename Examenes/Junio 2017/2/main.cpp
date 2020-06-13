#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

int calculaSiguiente(const Arbin<int>& mapa) {
    int ret = mapa.raiz();

    if (!mapa.hijoIz().esVacio()) ret += calculaSiguiente(mapa.hijoIz());
    if (!mapa.hijoDer().esVacio()) ret += calculaSiguiente(mapa.hijoDer());
    return ret;
}

//Prueba ((([3]5[0])2#)1((#3[6])5[1]))
int resuelve(const Arbin<int>& mapa, int anterior) {
    int ret = 0;

    //Prepara la solución
    int siguiente = calculaSiguiente(mapa) - mapa.raiz();
    if (anterior == siguiente) ret++;

    //Caso recursivo
    if (!mapa.hijoIz().esVacio()) ret += resuelve(mapa.hijoIz(), anterior + mapa.raiz());
    if (!mapa.hijoDer().esVacio()) ret += resuelve(mapa.hijoDer(), anterior + mapa.raiz());

    return ret;
}

int num_singulares(const Arbin<int>& mapa) {
    int anterior = 0;
    return resuelve(mapa, anterior);
}

Arbin<int> lee_arbol(istream& in) {
    char c;
    in >> c;
    switch (c) {
    case '#': return Arbin<int>();
    case '[': {
        int raiz;
        in >> raiz;
        in >> c;
        return Arbin<int>(raiz);
    }
    case '(': {
        Arbin<int> iz = lee_arbol(in);
        int raiz;
        in >> raiz;
        Arbin<int> dr = lee_arbol(in);
        in >> c;
        return Arbin<int>(iz, raiz, dr);
    }
    default: return Arbin<int>();
    }
}

int main() {
    while (cin.peek() != EOF) {
        Arbin<int> mapa = lee_arbol(cin);
        string resto_linea;
        getline(cin, resto_linea);
        cout << num_singulares(mapa) << endl;
    }
    return 0;
}
