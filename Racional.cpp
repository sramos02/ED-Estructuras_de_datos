#include "Racional.h"
#include <cmath>

//Metodos publicos

  //**** COMPLETAR
Racional Racional::suma(const Racional& arg) {
	Racional ret;
	ret._denom = mcd(_denom, arg._denom);
	ret._numer = (arg._denom * _numer) / ret._denom + (arg._numer * _denom) / ret._denom;
	return ret;
}


// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

Racional Racional::operator -(const Racional& arg) const {
	Racional ret;
	ret._denom = mcd(_denom, arg._denom);
	ret._numer = (arg._denom * _numer) / ret._denom + (arg._numer * _denom) / ret._denom;
	return ret;
}

Racional& Racional::operator *=(const Racional& arg) {
	Racional ret;
	_numer = _numer * arg._numer;
	_denom = _denom * arg._denom;
	return *this;
}


bool Racional::operator==(const Racional& arg) {
	return (_numer == arg._numer) && (_denom == arg._denom);
}




// Metodos privados
void Racional::reduce() {
	// Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1 % v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1 * v2 / mcd(v1, v2);
}

