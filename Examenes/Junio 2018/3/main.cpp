#include "ParqueNatural.h"

#include <iostream>
#include <string>
using namespace std;


void listaEspecies(ParqueNatural & parque, string nombreEco, int n){
	Lista<string> lista = parque.lista_especies_ecosistema(nombreEco, n);
	Lista<string>::ConstIterator especies = lista.cbegin();
	while (especies != lista.cend()) {
		cout << especies.elem() << " ";
		especies.next();
	}
	cout << endl;
}

void listaParque(ParqueNatural & parque) {
	Lista<string> lista = parque.lista_especies_parque();
	Lista<string>::ConstIterator especies = lista.cbegin();
	while (especies != lista.cend()) {
		cout << especies.elem() << " ";
		especies.next();
	}
	cout << endl;
}

//Como no me dan el main y no me apetece hacerlo lo hago a lo cutre
int main() {
	ParqueNatural parque;
	int entrada;
	cin >> entrada;

	while (entrada != 0) {
		string nombreEco, nombreEspecie;
		int n;
		try {
			switch (entrada) {
			case 1:
				cin >> nombreEco;
				parque.an_ecosistema(nombreEco);
				break;
			case 2:
				cin >> nombreEco >> nombreEspecie >> n;
				parque.an_ejemplares(nombreEco, nombreEspecie, n);
				break;
			case 3:
				cin >> nombreEco >> n;
				listaEspecies(parque, nombreEco, n);
				break;
			case 4:
				cin >> nombreEco >> nombreEspecie;
				cout << parque.numero_ejemplares_en_ecosistema(nombreEco, nombreEspecie) << endl;
				break;
			case 5:
				listaParque(parque);
				break;
			case 6:
				cin >> nombreEspecie;
				cout << parque.numero_ejemplares_en_parque(nombreEspecie) << endl;
			}
		}
		catch (EEcosistemaNoExiste) {cout << "ECOSISTEMA_NO_EXISTE" << endl;}
		catch (EEcosistemaDuplicado) {cout << "ECOSISTEMA_DUPLICADO" << endl;}
	}
	return 0;
}
