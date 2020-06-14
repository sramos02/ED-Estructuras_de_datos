#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

//Caso de prueba (([0]0([0]0[0]))0(#-2(([0]-1[0])0([0]0[0]))))
int resuelve(const Arbin<int>& mapa, int & res, int k) {
    int longitudTramo = 0;

    if (mapa.hijoIz().esVacio() && mapa.hijoDer().esVacio()) {
        if(mapa.raiz() == 0) return 1;
    }
    else {
        longitudTramo += mapa.raiz();
        if (!mapa.hijoIz().esVacio()) longitudTramo += resuelve(mapa.hijoIz(), res, k+1);
        if (!mapa.hijoDer().esVacio()) longitudTramo += resuelve(mapa.hijoDer(), res, k+1);
    }
  
     

    if (longitudTramo == 3) res++;
    if (k == 0) return 0;

    return longitudTramo;
}

int num_navegables(const Arbin<int>& mapa){
    int res = 0;
    resuelve(mapa, res, 0);
    return res;
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
        cout << num_navegables(mapa) << endl;
    }
    return 0;
}
