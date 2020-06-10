#include <iostream>
#include "lista.h"
using namespace std;

int main() {
    Lista<int> numeros;
    numeros.pon_final(1);
    numeros.pon_final(2);
    numeros.pon_final(3);
    numeros.pon_final(4);
    numeros.pon_final(5);
    numeros.pon_final(6);
    numeros.pon_final(7);
    numeros.pon_final(8);
    numeros.pon_final(9);
    numeros.intercambioParesImpares();

    Lista<int>::ConstIterator ini = numeros.cbegin();
    for (int i = 0; ini != numeros.cend(); i++) {
        cout << ini.elem() << " ";
        ini.next();
    }
    cout << endl;
    return 0;
}