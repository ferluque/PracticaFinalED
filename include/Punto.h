#include <iostream>

struct Punto
{
    double x, y;

    Punto()
    {
        x = 0;
        y = 0;
    }

    Punto(double xx, double yy)
    {
        x = xx;
        y = yy;
    }

    Punto &operator=(const Punto &otro)
    {
        this->x = otro.x;
        this->y = otro.y;
        return *this;
    }

    bool operator==(const Punto &otro) const 
    {
        return ((x == otro.x) && (y == otro.y));
    }
};

std::istream& operator>>(std::istream& in, Punto& p) {
    in.ignore();
    in >> p.x;
    in.ignore();
    in.ignore();
    in >> p.y;
    in.ignore();
    return in;
}

std::ostream &operator<<(std::ostream &out, const Punto &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}