#include "Ruta.h"
using namespace std;

istream& operator>>(istream& in, Ruta& ruta) {
    int num_puntos;
    in >> num_puntos; 

    for (int i=0; i<num_puntos; i++) {
        Punto nuevo;
        in >> nuevo;
        ruta.puntos.push_back(nuevo);
    }
    return in;
}

ostream& operator<<(ostream& out, const Ruta& ruta) {
    out << ruta.puntos.size() << " ";
    for (list<Punto>::const_iterator it = ruta.puntos.begin(); it != ruta.puntos.end(); ++it) {
        out << (*it) << " ";
    }
    out << endl;
    return out;
}

// ITERATOR
Ruta::iterator(list<Punto>::iterator lit) : it(lit) {}

Ruta::iterator& Ruta::iterator::operator++() {
    ++it;
    return *this;
}

Ruta::iterator& Ruta::iterator::operator--() {
    --it;
    return *this;
}

bool Ruta::iterator::operator!=(const Ruta::iterator& otro) {
    return (it != otro.it);
}

Ruta::iterator Ruta::begin() {
    iterator it(puntos.begin());
    return it;
}

Ruta::iterator Ruta::end() {
    iterator it(puntos.end());
    return it;
}

Punto& Ruta::iterator::operator*() {
    return (*it);
}

// CONST_ITERATOR
Ruta::const_iterator(list<Punto>::const_iterator clit) : cit(clit) {}

Ruta::const_iterator& Ruta::const_iterator::operator++(); {
    ++cit;
    return *this;
}

Ruta::const_iterator& Ruta::const_iterator::operator--() {
    --cit;
    return *this;
}

bool Ruta::const_iterator::operator!=(const Ruta::const_iterator& otro) {
    return (cit != otro.cit);
}

const Punto& Ruta::const_iterator::operator*() {
    return (*cit);
}

Ruta::const_iterator Ruta::cbegin() {
    const_iterator begin(puntos.cbegin());
    return begin;
}

Ruta::const_iterator Ruta::cend() {
    const_iterator end(puntos.cend());
    return end;
}