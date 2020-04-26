#include "Arbin.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Implementar aquí la funciones auxiliares que se consideren necesarias
int sumaHijos(Arbin<int> arbin, int i, int &altura);

// Función principal a implementar, que determina si
// el árbol dado como entrada es o no zurdo (devuelve true si es
// zurdo, false en otro caso)
bool es_zurdo(Arbin<int> a) {

    if(a.esVacio()) return false;

    int altura = 0, sumIz = 0, sumDer = 0;

    if (!a.hijoIz().esVacio())
        sumIz = sumaHijos(a.hijoIz(), 1, altura);
    if (!a.hijoDer().esVacio())
        sumDer = sumaHijos(a.hijoDer(), 1, altura);

    bool dif = sumIz - sumDer >= (altura - 1);
    return dif;
}

//No modifica el valor del arbol
int sumaHijos(Arbin<int> arbin, int k, int & altura) {
    int suma = 0;


    if(arbin.hijoIz().esVacio() && arbin.hijoDer().esVacio()) {
        if(k > altura) altura = k;
    }
    else {
        k++;
        if (!arbin.hijoIz().esVacio())
            suma += sumaHijos(arbin.hijoIz(), k, altura);
        if (!arbin.hijoDer().esVacio())
            suma += sumaHijos(arbin.hijoDer(), k, altura);
    }
    suma += arbin.raiz();
    return suma;
}


//-----------------------------------------------------------------------
// Código que se encarga de la e/s: no tocar
//

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


/**
La entrada al programa consiste de líneas formadas por árboles de enteros
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estádar
ZURDO si el árbol es zurdo, y NO_ZURDO en otro caso

Ejemplo de entrada:
#
[5]
([17]5([2]1[3]))
(([2]1[3])5[17])

Salida asociada:
NO_ZURDO
ZURDO
ZURDO
NO_ZURDO


*/

int main() {
    Arbin<int> arbol;
    while (cin.peek() != EOF)  {
        Arbin<int> a = lee_arbol(cin);
        string resto_linea;
        getline(cin, resto_linea);
        if (es_zurdo(a)) cout << "ZURDO";
        else cout << "NO_ZURDO";
        cout << endl;
    }
    return 0;
}