/*
Nombre y apellidos del/de la estudiante: Sergio Ramos Mesa

*/

//Descomentar para habilitar autocorrección. 
#define AUTO


#include "lista.h"
#include <iostream>
#include <sstream>
using namespace std;


typedef struct {
	string input;
	string output;
} tCaso;

const int NCASOS = 13;

tCaso casos[NCASOS] = {
	{"6 5 7 9 10 20 25","5 9 20 25 10 7 #7 10 25 20 9 5 "},
	{"4 6 8 2 1","6 2 1 8 #8 1 2 6 "},
	{"0","#"},
	{"1 0","0 #0 "},
	{"2 0 1","0 1 #1 0 "},
	{"3 0 1 2","0 2 1 #1 2 0 "},
	{"4 0 1 2 3","0 2 3 1 #1 3 2 0 "},
	{"5 0 1 2 3 4","0 2 4 3 1 #1 3 4 2 0 "},
	{"6 0 1 2 3 4 5","0 2 4 5 3 1 #1 3 5 4 2 0 " },
	{"7 0 1 2 3 4 5 6","0 2 4 6 5 3 1 #1 3 5 6 4 2 0 " },
	{"8 0 1 2 3 4 5 6 7","0 2 4 6 7 5 3 1 #1 3 5 7 6 4 2 0 " },
	{"9 0 1 2 3 4 5 6 7 8","0 2 4 6 8 7 5 3 1 #1 3 5 7 8 6 4 2 0 " },
	{"10 0 1 2 3 4 5 6 7 8 9","0 2 4 6 8 9 7 5 3 1 #1 3 5 7 9 8 6 4 2 0 " }
};

bool lee_lista(istream& in, Lista<int>& lista) {
	int n_elems;
	in >> n_elems;
	if (n_elems >= 0) {
		while (n_elems-- != 0) {
			int elem;
			in >> elem;
			lista.pon_final(elem);
		}
		return true;
	}
	else {
		return false;
	}
}

bool ejecuta_caso(istream& in, ostream& out) {
  Lista<int> lista;
  if (lee_lista(in,lista)) { 
    lista.estremece();
    lista.imprime(out);
    out << "#";
    lista.imprime_inv(out);
    return true;
  }
  else {
	return false;  
  }  
}


void autocorreccion() {
	bool ok = true;
	for (int i = 0; i < NCASOS; i++) {
		stringstream in;
		stringstream out;
		in << casos[i].input;
		ejecuta_caso(in, out);
		if (out.str() != casos[i].output) {
			ok = false;
			cout << "ERROR" << endl;
			cout << "....ENTRADA:" << casos[i].input << endl;
			cout << "....SALIDA ESPERADA:" << casos[i].output << endl;
			cout << "....SALIDA OBTENIDA:" << out.str() << endl;
	    }
	}
	if (ok) {
		cout << "Todos los casos de prueba se han superado correctamente." << endl;
	}
	else {
		cout << "Se han encontrado discrepancias con casos de prueba." << endl;
	}
}

int main() {
#ifndef AUTO
	while (ejecuta_caso(cin, cout)) {
		cout << endl;
	}
#endif
#ifdef AUTO
	autocorreccion();
	system("pause"); 
#endif
	return 0;
}