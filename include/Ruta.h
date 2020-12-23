#ifndef __RUTA__
#define __RUTA__
#include "Paises.h"

using namespace std;

class Ruta {
private:
    Paises destinos;
    string avion;

public:
    Ruta();
    Ruta(const Ruta& otra);
    Ruta& operator=(const Ruta& otra);

    void ImprimirImagen(string salida, string mapa);

};

#endif