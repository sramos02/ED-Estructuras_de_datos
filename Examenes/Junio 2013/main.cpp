#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

int cuantos_unicos(const Arbin<int>& arbol) {
    int ret = 0;

    if (arbol.hijoIz().esVacio() && arbol.hijoDer().esVacio());
    else if (arbol.hijoDer().esVacio()) {
        ret += cuantos_unicos(arbol.hijoIz());        
        ret++;

    }
    else if (arbol.hijoIz().esVacio()) {
        ret += cuantos_unicos(arbol.hijoDer());
        ret++;
    }
    else {
        ret += cuantos_unicos(arbol.hijoIz());
        ret += cuantos_unicos(arbol.hijoDer());
    }
    return ret;
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
        cout << cuantos_unicos(mapa) << endl;
    }
    return 0;
}