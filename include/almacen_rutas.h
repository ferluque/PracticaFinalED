#ifndef __ALMACEN_RUTAS_H
#define __ALMACEN_RUTAS_H
#include <map>
#include "Ruta.h"
#include <iostream>

using namespace std;

class Almacen_Rutas {
    private:
    map<string, Ruta> rutas;

    public:
    Almacen_Rutas()=default;
    Almacen_Rutas(const Almacen_Rutas& otro)=default;
    Almacen_Rutas& operator=(const Almacen_Rutas& otro)=default;

    Ruta GetRuta(string codigo);

    friend ostream& operator<<(ostream& out, const Almacen_Rutas& almacen);
    friend istream& operator>>(istream& in, Almacen_Rutas& almacen);
};

ostream& operator<<(ostream& out, const Almacen_Rutas& almacen);
istream& operator>>(istream& in, Almacen_Rutas& almacen);

#endif