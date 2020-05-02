#include <iostream>
#include "Arbin.h"
using namespace std;

int func_general(Arbin<int> arb, int prof, int k) {
    int acum = 0;
    if (arb.hijoDer().esVacio() && arb.hijoIz().esVacio()){
        if (k > prof) return 1;
    }
    else{
        if(!arb.hijoIz().esVacio())
            acum += func_general(arb.hijoIz(), prof, k+1);
        if(!arb.hijoDer().esVacio())
            acum += func_general(arb.hijoDer(), prof, k+1);
    }
    return acum;
}

int resuelve(Arbin<int> arb, int prof){
    if(arb.esVacio())return 0;
    return func_general(arb, prof, 1);
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
    while (cin.peek() != EOF)  {
        int prof;
        string resto_linea;
        cin >> prof;
        cin.get();
        Arbin<int> arb = lee_arbol(cin);
        getline(cin, resto_linea);

        cout << resuelve(arb, prof) << endl;
    }
    return 0;
}
