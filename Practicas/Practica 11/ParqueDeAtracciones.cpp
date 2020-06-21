
#include "ParqueDeAtracciones.h"

ParqueDeAtracciones::ParqueDeAtracciones() {}

void ParqueDeAtracciones::an_atraccion(const string& nombre_atraccion) {
	if (listaAtracciones.contiene(nombre_atraccion)) throw EAtraccionYaExiste();
	else listaAtracciones.inserta(nombre_atraccion, Atraccion());
}

void ParqueDeAtracciones::an_ninio(const string& nombre_ninio) {
	if (listaNinios.contiene(nombre_ninio)) throw ENinioYaRegistrado();
	else listaNinios.inserta(nombre_ninio, Ninio());
}

void ParqueDeAtracciones::poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion) {
	if (!listaNinios.contiene(nombre_ninio) || !listaAtracciones.contiene(nombre_atraccion) || 
		listaNinios.busca(nombre_ninio).valor().enCola == true) throw EAccesoAtraccion();

	//Marca al niño en cola
	listaAtracciones.busca(nombre_atraccion).valor().cola.pon_final(nombre_ninio);
	listaNinios.busca(nombre_ninio).valor().enCola = true;

	//Lista de atracciones montadas por el niño
	if (listaNinios.busca(nombre_ninio).valor().atracciones_montadas.contiene(nombre_atraccion)) {
		int aux = listaNinios.busca(nombre_ninio).valor().atracciones_montadas.busca(nombre_atraccion).valor();
		listaNinios.busca(nombre_ninio).valor().atracciones_montadas.busca(nombre_atraccion).setVal(aux + 1);
	}
	else listaNinios.busca(nombre_ninio).valor().atracciones_montadas.inserta(nombre_atraccion, 1);

	//Lista de niños montados en una atraccion
	if (listaAtracciones.busca(nombre_atraccion).valor().historial.contiene(nombre_ninio)) {
		int aux = listaAtracciones.busca(nombre_atraccion).valor().historial.busca(nombre_ninio).valor();
		listaAtracciones.busca(nombre_atraccion).valor().historial.busca(nombre_ninio).setVal(aux + 1);
	}
	else listaAtracciones.busca(nombre_atraccion).valor().historial.inserta(nombre_ninio, 1);
}	

void ParqueDeAtracciones::avanzar(const string& nombre_atraccion) {
	if (!listaAtracciones.contiene(nombre_atraccion)) throw EAtraccionNoExiste();

	///CREO QUE ESTO ESTA MAL, REVISAR
	if (!listaAtracciones.busca(nombre_atraccion).valor().cola.esVacia()) {
		string nombreNinio = listaAtracciones.busca(nombre_atraccion).valor().cola.primero();
		listaAtracciones.busca(nombre_atraccion).valor().cola.quita_ppio();

		listaNinios.busca(nombreNinio).valor().enCola = false;
	}
}


Lista<string> ParqueDeAtracciones::atracciones_visitadas(const string& nombre_ninio) const {
	if (!listaNinios.contiene(nombre_ninio)) throw ENinioNoRegistrado();
	//return listaNinios.cbusca(nombre_ninio).valor().atracciones_montadas.;
}
   
int ParqueDeAtracciones::numero_visitas(const string& nombre_ninio, const string& nombre_atraccion) const {
	if (!listaAtracciones.contiene(nombre_atraccion) || !listaNinios.contiene(nombre_ninio)) throw EConsultaNumViajes();
	
	if (!listaAtracciones.cbusca(nombre_atraccion).valor().historial.contiene(nombre_ninio)) return 0;
	return listaAtracciones.cbusca(nombre_atraccion).valor().historial.cbusca(nombre_ninio).valor();
}
   
 