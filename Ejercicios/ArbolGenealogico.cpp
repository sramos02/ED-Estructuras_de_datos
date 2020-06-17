#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

//Caso de prueba ([3]25[1])48([3]21#)
bool arbol_genealogico(const Arbin<int>& arbol) {

    //No tiene hijos //Un solo hijo //Dos hijos
    if (arbol.hijoIz().esVacio() && arbol.hijoDer().esVacio()) { return true; }
    else if (arbol.hijoDer().esVacio()) {
        return arbol_genealogico(arbol.hijoIz()) && (arbol.hijoIz().raiz() + 18 >= arbol.raiz());
    }
    else {
        return arbol_genealogico(arbol.hijoIz()) && arbol_genealogico(arbol.hijoDer()) &&
            (arbol.hijoIz().raiz() + 18 <= arbol.raiz()) && (arbol.hijoDer().raiz() + 18 <= arbol.raiz()) &&
            (arbol.hijoIz().raiz() >= arbol.hijoDer().raiz() + 2);
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
        arbol_genealogico(mapa) ? cout << "SI\n":cout << "NO\n";
    }
    return 0;
}