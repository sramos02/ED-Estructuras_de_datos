#include <iostream>
#include "cola.h"
using namespace std;


unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
	Cola<int> numeros;
	for (unsigned int i = 1; i <= n; i++) numeros.pon(i);
	int num = 1;
	int ret = numeros.primero();

	while (!numeros.esVacia()) {
		if (num % m != 0) numeros.pon(numeros.primero());
		else ret = numeros.primero();
		numeros.quita();
		num++;
	}
	return ret;
}


int main() {
	int n, m;
	while ((cin >> n)) {
		cin >> m;
		cout << afortunado(n, m) << endl;
	}
	return 0;
}