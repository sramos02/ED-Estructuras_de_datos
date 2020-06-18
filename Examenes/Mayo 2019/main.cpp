#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

//No es lo que pedía el ejercicio pero no lo entiendo bien
void resuelve(const Arbin<int>& a, bool& es_rentable, int& renta_maxima, int renta_actual) {
    if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
        if (a.raiz() >= 0) {
            es_rentable = true;
            renta_actual = a.raiz();
            if (renta_actual > renta_maxima) renta_maxima = renta_actual;
        }
        else es_rentable = false;
    }
    else {
        if (!a.hijoIz().esVacio()) resuelve(a.hijoIz(), es_rentable, renta_maxima, renta_actual);
        if (!a.hijoDer().esVacio()) resuelve(a.hijoDer(), es_rentable, renta_maxima, renta_actual);

        renta_actual += a.raiz();
        if (renta_actual >= 0 && es_rentable) {
            es_rentable = true;
            if (renta_actual > renta_maxima) renta_maxima = renta_actual;
        }
        else es_rentable = false;
    }
}

void mejor_renta(Arbin<int>& a, bool& es_rentable, int& renta_maxima) {
    if (a.esVacio()) es_rentable = false;
    else resuelve(a, es_rentable, renta_maxima, 0);
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
        bool r;
        int m;
        mejor_renta(mapa, r, m);
        if (r)cout << "SI " << m << endl;
        else cout << "NO\n";
    }
    return 0;
}