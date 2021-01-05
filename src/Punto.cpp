#include "Punto.h"

using namespace std;

Punto::Punto()
{
    x = 0;
    y = 0;
}

Punto::Punto(double xx, double yy)
{
    x = xx;
    y = yy;
}

Punto &Punto::operator=(const Punto &otro)
{
    this->x = otro.x;
    this->y = otro.y;
    return *this;
}

bool Punto::operator==(const Punto &otro) const
{
    return ((x == otro.x) && (y == otro.y));
}

istream& operator>>(std::istream& in, Punto& p) {
    in.ignore();
    in >> p.y;
    in.ignore();
    in >> p.x;
    in.ignore();
    return in;
}

ostream& operator<<(ostream& out, const Punto& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}