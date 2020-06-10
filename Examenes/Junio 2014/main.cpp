/*
Nombre y apellidos del/de la estudiante: Sergio Ramos Mesa

*/

#include <sstream>
#include "lista.h"
using namespace std;


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


int main() {
	int pos = 0;

	while (pos != -1) {
		Lista<int> lista;
		int numElems, nuevo;

		cin >> numElems;
		for (int i = 0; i < numElems; i++) {
			int aux;
			cin >> aux;
			lista.pon_final(aux);
		}

		cin >> nuevo >> pos;
		if (pos >= 0 && pos <= lista.longitud()) {
			lista.inserta(nuevo, pos);
			lista.muestra();
		}
		else { std::cout << "DATOS INCORRECTOS" << std::endl; }
	}
	return 0;
}