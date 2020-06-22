#include "ParqueNatural.h"

void ParqueNatural::crea() {}

void ParqueNatural::an_ecosistema(string ecosistema) {
	if (listaEcosistemas.contiene(ecosistema)) throw EEcosistemaDuplicado();
	listaEcosistemas.inserta(ecosistema, Ecosistema());
}

void ParqueNatural::an_ejemplares(string ecosistema, string especie, int n) {
	if (!listaEcosistemas.contiene(ecosistema)) throw EEcosistemaNoExiste();

	if (n >= 0) {
		Ecosistema eco = listaEcosistemas.busca(ecosistema).valor();
		if (eco.especiesEco.contiene(especie)) eco.especiesEco.busca(especie).valor() += n;
		else {
			eco.listaEspeciesEcosistema.pon_ppio(especie);
			listaEspeciesParque.pon_final(especie);
			eco.especiesEco.inserta(especie, n);
		}
		eco.numEjemplares += n;
	}
}

Lista<string> ParqueNatural::lista_especies_ecosistema(string ecosistema, int n) {
	if (!listaEcosistemas.contiene(ecosistema)) throw EEcosistemaNoExiste();
	Lista<string>::ConstIterator it = listaEcosistemas.cbusca(ecosistema).valor().listaEspeciesEcosistema.cbegin();
	Lista<string> ultimos;

	for (int i = 0; i < n; i++) {
		ultimos.pon_final(it.elem());
		it.next();
	}

	return ultimos;
}

int ParqueNatural::numero_ejemplares_en_ecosistema(string ecosistema, string especie) {
	if (!listaEcosistemas.contiene(ecosistema)) throw EEcosistemaNoExiste();
	return listaEcosistemas.busca(ecosistema).valor().numEjemplares;
}

Lista<string> ParqueNatural::lista_especies_parque() {
	return listaEspeciesParque;
} 

int ParqueNatural::numero_ejemplares_en_parque(string especie) {
	return listaEspeciesParque.longitud();
}
