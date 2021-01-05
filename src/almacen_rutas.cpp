#include "almacen_rutas.h"

ostream& operator<<(ostream& out, const Almacen_Rutas& almacen) {
    out << "#Rutas\n";
    for (map<string, Ruta>::const_iterator it = almacen.rutas.begin(); it != almacen.rutas.end(); ++it) {
        out << (*it).first << " " << (*it).second;
    }
    return out;
}

istream& operator>>(istream& in, Almacen_Rutas& almacen) {
    string magica;
    getline(in, magica);
    if (magica != "#Rutas") 
        cerr << "Error en la entrada del almacén" << endl;

    while (!in.eof()) {
        string codigo;
        in >> codigo;
        Ruta nueva;
        in >> nueva;
        
        pair<string, Ruta> par(codigo, nueva);
        almacen.rutas.insert(par);
        
    }

    return in;
}

Ruta Almacen_Rutas::GetRuta(string codigo) {
    return rutas.at(codigo);
}