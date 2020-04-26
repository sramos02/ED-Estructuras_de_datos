#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int funcion(const Arbin<int>& cuenca, int & ret, int k){
    int longitudTramo = 0;

    if(cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio()){
        if(cuenca.raiz() == 0){ //Fin del río
            return 1;
        }
    }
    else {
        longitudTramo += cuenca.raiz();
        if (!cuenca.hijoIz().esVacio())
            longitudTramo += funcion(cuenca.hijoIz(), ret, k+1);
        if (!cuenca.hijoDer().esVacio())
            longitudTramo += funcion(cuenca.hijoDer(), ret, k+1);

        if(longitudTramo == 3) ret++;
        if(k == 0) return 0;
    }

    return longitudTramo;
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {
    int ret = 0;
    funcion(cuenca, ret, 0);
    return ret;
}

Arbin<int> leeArbol(istream& in) {
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
            Arbin<int> iz = leeArbol(in);
            int raiz;
            in >> raiz;
            Arbin<int> dr = leeArbol(in);
            in >> c;
            return Arbin<int>(iz, raiz, dr);
        }
        default: return Arbin<int>();
    }
}

int main() {
    Arbin<int> cuenca;
    while (cin.peek() != EOF)  {
        cout << numeroTramosNavegables(leeArbol(cin));
        string restoLinea;
        getline(cin, restoLinea);
        if (cin.peek() != EOF) cout << endl;
    }
    return 0;
}