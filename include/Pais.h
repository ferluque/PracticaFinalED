#ifndef __PAIS__
#define __PAIS__
#include "Punto.h"

class Pais
{
private:
    Punto p;
    std::string pais;
    std::string bandera;

public:
    Pais() {}
    Punto GetPunto() const { return p; }
    std::string GetPais() const { return pais; }
    std::string GetBandera() const { return bandera; }

    double GetLongitud () const { return p.x;}
    double GetLatitud () const {return p.y;}

    bool operator<(const Pais &P) const
    {
        return pais < P.pais;
    }
    bool operator==(const Pais &P) const
    {
        return pais == P.pais;
    }
    bool operator==(const Punto &P) const
    {
        return p == P;
    }
    friend std::istream &operator>>(std::istream &is, Pais &P)
    {
        double lat, lng;

        is >> lat >> lng >> P.pais >> P.bandera;

        P.p = Punto(lat, lng);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Pais &P)
    {
        os << P.p << " " << P.pais << " " << P.bandera << std::endl;
        return os;
    }
};
#endif