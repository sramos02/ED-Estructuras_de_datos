#include <iostream>
#include "polisia.h"
using namespace std;

int main() {
    polisia pob;
    pob.nuevo("12345678A");
    pob.nuevo("87654321B");
    pob.nuevo("18273645C");
    //pob.nuevo("87654321B");

    pob.quitar("12345678A", 16);
    pob.quitar("87654321B", 4);

    pob.recuperar("18273645C", 5);
    pob.recuperar("12345678A", 6);

    cout << pob.consultar("12345678A") << endl;
    cout << pob.consultar("87654321B") << endl;
    cout << pob.consultar("18273645C") << endl;

    cout << pob.cuantos_con_puntos(6) << endl;
    cout << pob.cuantos_con_puntos(5) << endl;
}
