#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
    Pila<char> equilibrado;

    for(int i = 0; i < cadena.length(); i++){
        if (equilibrado.esVacia()) return false;
        else if(cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') equilibrado.apila(cadena[i]);
        else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') equilibrado.desapila();
    }
    return equilibrado.esVacia();
}


int main() {
    string cadena;
    while (getline(cin, cadena)) {
        if (esEquilibrada(cadena))
            cout << "EQUILIBRADA" << endl;
        else
            cout << "NO_EQUILIBRADA" << endl;
    }
    return 0;
}