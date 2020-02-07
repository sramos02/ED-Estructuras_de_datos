//SERGIO RAMOS MESA
#include "Racional.h"
#include <cmath>

//Metodos publicos

//**** COMPLETAR
Racional::Racional(long a, long b) {
    _numer = a;
    _denom = b;
    if(_denom == 0) throw Racional::EDenominadorCero();
    reduce();
}

Racional::Racional() {
    _numer = 0;
    _denom = 1;
}

Racional Racional::suma(Racional arg) {
    long d = mcm(_denom, arg._denom);
    long n = (_numer * (d/_denom)) + (arg._numer * (d/arg._denom));

    Racional ret = Racional(n, d);
    ret.reduce();
    return ret;
}

// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
    out << f._numer << "/" << f._denom;
    return out;
}

Racional Racional::operator -(Racional arg) {
    long d = mcm(_denom, arg._denom);
    long n = (_numer * (d/_denom)) - (arg._numer * (d/arg._denom));
    Racional ret = Racional(n, d);
    ret.reduce();
    return ret;
}

void Racional::operator *=(Racional arg) {
    _numer = _numer * arg._numer;
    _denom = _denom * arg._denom;
    reduce();
}


bool Racional::operator==(const Racional& arg) const{
    return (_numer == arg._numer) && (_denom == arg._denom);
}

void Racional::divideYActualiza(Racional arg) {
    if(arg._numer == 0) throw Racional::EDivisionPorCero();

    _numer = _numer * arg._denom;
    _denom = _denom * arg._numer;
    reduce();
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
