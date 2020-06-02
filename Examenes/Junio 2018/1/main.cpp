#include <iostream>
#include <string>
#include "lista.h"
using namespace std;


int main() {
	Lista<int> lista;
	lista.pon_final(8);
	lista.pon_final(10);
	lista.pon_final(5);
	lista.pon_final(19);
	lista.pon_final(3);
	lista.pon_final(8);
	lista.pon_final(4);
	lista.pon_final(7);
	lista.pon_final(2);
	lista.repartir();
	lista.muestra();
	return 0;
}