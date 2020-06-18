#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

//Caso de prueba (([3]3[1])1[2])
int resuelve(const Arbin<int>& a, int & numCuriosos, int nivel) {

    //Caso base
    if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
        if (a.raiz() == nivel) numCuriosos++;
        return 0;
    }
    
    else {
        int hijosIzq = 0, hijosDer = 0;

        //Caso recursivo
        if (!a.hijoIz().esVacio()) 
            hijosIzq = resuelve(a.hijoIz(), numCuriosos, nivel + 1) + 1;
        if (!a.hijoDer().esVacio())
            hijosDer = resuelve(a.hijoDer(), numCuriosos, nivel + 1) + 1;

        //Preparo la solucion
        if (a.raiz() == nivel + hijosIzq) numCuriosos++;
    }

}

int num_curiosos(const Arbin<int>& a) {
    int numCuriosos = 0;
    resuelve(a, numCuriosos, 1);
    return numCuriosos;
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
        cout << num_curiosos(mapa) << endl;
    }
    return 0;
}