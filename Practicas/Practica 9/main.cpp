//SERGIO RAMOS MESA
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;



int hojasProfundasAux(Arbin<int> a, unsigned int minNivel, int act) {
    int ret = 0;

    if (a.hijoDer().esVacio() && a.hijoIz().esVacio()){
        if (act > minNivel)
            return 1;
    }
    else{
        if(!a.hijoIz().esVacio())
            ret += hojasProfundasAux(a.hijoIz(), minNivel, act+1);
        if(!a.hijoDer().esVacio())
            ret += hojasProfundasAux(a.hijoDer(), minNivel, act+1);
    }
    return ret;
}

unsigned int numero_hojas_mas_profundas_que(Arbin<int> a, unsigned int k) {
    int act = 1;

    if(a.esVacio()) return 0;
    else return hojasProfundasAux(a, k, act);
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
        int k;
        cin >> k;
        cout << numero_hojas_mas_profundas_que(a,k) << endl;
        string resto_linea;
        getline(cin, resto_linea);
    }
    return 0;
}