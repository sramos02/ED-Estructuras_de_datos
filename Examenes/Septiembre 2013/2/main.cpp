#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

void resuelve(const Arbin<int>& arbol, bool& esZurdo, int& longMinima) {

    if (arbol.hijoIz().esVacio() && arbol.hijoDer().esVacio()) {
        esZurdo = true;
        longMinima = 0;
    }
    else {

        bool zurdoIz, zurdoDer;
        int longIz, longDer;

        if (!arbol.hijoIz().esVacio())
            resuelve(arbol.hijoIz(), zurdoIz, longIz);

        if (!arbol.hijoDer().esVacio())
            resuelve(arbol.hijoDer(), zurdoDer, longDer);

        esZurdo = esZurdo && zurdoDer && zurdoIz && (longIz >= longDer);
        longMinima = 1 + ((longIz <= longDer) ? longIz : longDer);
    }
}


bool esZurdo(const Arbin<int>& arbol) {
    if (arbol.raiz() == NULL) return false;
    else {
        bool esZurdo = true;
        int longitud = 1;
        resuelve(arbol, esZurdo, longitud);    
        return esZurdo;
    }
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
        (esZurdo(mapa)) ? cout << "SI\n" : cout << "NO\n";
    }
    return 0;
}