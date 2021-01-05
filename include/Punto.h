#ifndef __PUNTO_H
#define __PUNTO_H

#include <iostream>

struct Punto
{
    double x, y;

    Punto();
    Punto(double, double);
    Punto& operator=(const Punto&);
    bool operator==(const Punto&) const;
};

std::istream& operator>>(std::istream& in, Punto& p);

std::ostream &operator<<(std::ostream &out, const Punto &p);

#endif