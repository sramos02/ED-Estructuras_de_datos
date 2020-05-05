//SERGIO RAMOS MESA
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;



int singularesAux(Arbin<int> a, int count) {
    int ret = 0;

    if(a.raiz() >= count) ret++;

    if(!a.hijoIz().esVacio())
        ret += singularesAux(a.hijoIz(), count += a.raiz());
    if(!a.hijoDer().esVacio())
        ret += singularesAux(a.hijoDer(), count += a.raiz());


    return ret;
}

unsigned int singulares(Arbin<int> a) {
    if(a.esVacio()) return 0;

    int act = a.raiz();
    return singularesAux(a, act);
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
    Arbin<int> arbol;
    while (cin.peek() != EOF)  {
        Arbin<int> a = lee_arbol(cin);
        cout << singulares(a) << endl;
        string resto_linea;
        getline(cin, resto_linea);
    }
    return 0;
}