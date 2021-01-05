#ifndef __RUTA__
#define __RUTA__
#include "Paises.h"
#include <list>

using namespace std;

class Ruta
{
private:
    list<Punto> puntos;

public:
    Ruta() = default;
    Ruta(const Ruta &otra) = default;
    Ruta &operator=(const Ruta &otra) = default;

    friend istream &operator>>(istream &in, Ruta &ruta);
    friend ostream &operator<<(ostream &out, const Ruta &ruta);

    class iterator
    {
    private:
        list<Punto>::iterator it;
        iterator(list<Punto>::iterator lit);

    public:
        iterator() = default;
        iterator(const iterator &otro) = default;
        iterator &operator=(const iterator &otro) = default;

        iterator &operator++();
        iterator &operator--();
        bool operator!=(const iterator &otro);
        Punto &operator*();

        friend class Ruta;
    };

    iterator begin();
    iterator end();

    class const_iterator
    {
    private:
        list<Punto>::const_iterator cit;
        const_iterator(list<Punto>::const_iterator clit);

    public:
        const_iterator() = default;
        const_iterator(const const_iterator &otro) = default;
        const_iterator &operator=(const const_iterator &otro) = default;

        const_iterator &operator++();
        const_iterator &operator--();
        bool operator!=(const const_iterator &otro);
        const Punto &operator*();

        friend class Ruta;
    };

    const_iterator cbegin() const;
    const_iterator cend() const;
};

istream &operator>>(istream &in, Ruta &ruta);
ostream &operator<<(ostream &out, const Ruta &ruta);
#endif