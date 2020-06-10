/*
Nombre y apellidos del/de la estudiante: Sergio Ramos Mesa

*/

#include <iostream>
#include "pila.h"
#include "cola.h"
using namespace std;


//O(N) se recorren todos los elementos de la pila cada vez.

template<typename T>
void invierteBase(Pila<T> &pila, int valor) {
	Pila<T> norm;
	Cola<T> inv;

	if (valor > 0) {
		int i = 0;
		while (!pila.esVacia()) {
			if (i < valor) {
				inv.pon(pila.cima());
				pila.desapila();
			}
			else {
				norm.apila(pila.cima());
				pila.desapila();
			}
			i++;
		}

		//Insertamos los nuevos valores
		while (!inv.esVacia()) {
			pila.apila(inv.primero());
			inv.quita();
		}

		while (!norm.esVacia()) {
			pila.apila(norm.cima());
			norm.desapila();
		}
	}
}

template<typename T>
void muestra(const Pila<T> pila) {
	Pila<T> a = pila;
	while (!a.esVacia()) {
		cout << a.cima() << " ";
		a.desapila();
	}
}

int main() {
	Pila<int> pila;
	int aux, valor, numElems = 0;


	cin >> aux;
	while(aux != -1){
		pila.apila(aux);
		numElems++;
		cin >> aux;
	}
	cin >> valor;
	
	if (valor >= 0 && valor <= numElems) {
		invierteBase(pila, valor);
		muestra(pila);
	}
	
	return 0;
}