#include "Secuencia.h"

#include <iostream>
#include <string>
using namespace std;

void haz_consulta(Secuencia<int> sec, int elem) {
    try {
        cout << sec.elem(elem) << endl;
    }
    catch (ElementoInvalido) {
        cout << "ERROR" << endl;
    }
}

void muestra(Secuencia<int> s) {
    s = s;
    Secuencia<int> sec = s;
    for (int i = 0; i < sec.num_elems(); i++) {
        cout << sec.elem(i) << " ";
    }
    cout << endl;
}

bool ejecuta_caso(Secuencia<int>& sec) {
    string comando;
    cin >> comando;
    if (comando == "pon") {
        int elem;
        cin >> elem;
        sec.pon(elem);
        cout << sec.num_elems() << endl;
        return true;
    }
    else if (comando == "consulta") {
        int elem;
        cin >> elem;
        haz_consulta(sec, elem);
        return true;
    }
    else if (comando == "muestra") {
        muestra(sec);
        return true;
    }
    else if (comando == "limpia") {
        sec = Secuencia<int>();
        cout << "OK" << endl;
        return true;
    }
    else if (comando == "termina") {
        return false;
    }
    return false;
}

int main() {
    Secuencia<int> sec;
    while (ejecuta_caso(sec));
    return 0;
}