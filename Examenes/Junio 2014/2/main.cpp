#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;


//Caso de prueba (([D]L([D]L([L]D[L])))L(#D([L]D[L])))
void resuelve(const Arbin<char>& mapa, int numDragones, int & longitudMinima, int longitudActual) {

    //Prepara la solucion
    if (mapa.hijoIz().esVacio() && mapa.hijoDer().esVacio()) {
        if (mapa.raiz() == 'D') {
            numDragones++;
            if (longitudMinima == -1 || longitudActual < longitudMinima) longitudMinima = longitudActual;
        }
    }
    else {
        if (!mapa.hijoIz().esVacio())
            resuelve(mapa.hijoIz(), numDragones, longitudMinima, longitudActual + 1);
        if (!mapa.hijoDer().esVacio())
            resuelve(mapa.hijoDer(), numDragones, longitudMinima, longitudActual + 1);
    }
}

int numDragones(const Arbin<char>& mapa) {
    int numDragones = 0;
    int longitudMinima = -1;
    resuelve(mapa, numDragones, longitudMinima, 1);
    return longitudMinima;
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

char main() {
    while (cin.peek() != EOF) {
        Arbin<char> mapa = lee_arbol(cin);
        string resto_linea;
        getline(cin, resto_linea);
        cout << numDragones(mapa) << endl;
    }
    return 0;
}