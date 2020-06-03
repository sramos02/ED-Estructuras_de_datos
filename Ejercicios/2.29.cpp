//1
Lista<T>::Iterator itBuscado(T elem) {
	Lista<T>::Iterator ret = begin();

	while (ret != NULL) {
		if (ret->_elem == elem) return ret;
		ret = ret->_sig;
	}

	return ret;
}

//2
Lista<T>::Iterator itBuscado(T elem, Lista<T>::Iterator ini, Lista<T>::Iterator fin) {
	Lista<T>::Iterator ret = ini;

	while (ret != fin) {
		if (ret->_elem == elem) return ret;
		ret = ret->_sig;
	}

	return ret;
}

//3
void itBuscado(T elem, Lista<T>::Iterator ini, Lista<T>::Iterator fin) {
	Lista<T>::Iterator act = ini;

	while (ret != fin) {
		if (ret->_elem == elem){
			act->_ant->_sig = act->_sig;
			act->_sig->_ant = act->_ant;
		}
		act = act->_sig;
	}
}