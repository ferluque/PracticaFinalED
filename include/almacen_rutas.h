/**
 * @file almacen_rutas.h
 * @brief Fichero cabecera para el TDA Almacen_Rutas
 * @author Fernando Luque (fl1562001@correo.ugr.es)
 * 
 * Declara un TDA Almacen_Rutas que permite representar una colección de objetos
 * de la clase @c Ruta , con un identificador cada una de ellas
 * 
 */


#ifndef __ALMACEN_RUTAS_H
#define __ALMACEN_RUTAS_H
#include <map>
#include "Ruta.h"
#include <iostream>

using namespace std;

/**
 * @brief TDA Almacen_Rutas
 * 
 * Una instancia @e ar del tipo @c Almacen_Rutas es un objeto que representa una colección
 * de objetos de la clase @c Ruta , teniendo cada ruta un identificador unívoco (string)
 */
class Almacen_Rutas {
    private:
    /**
     * @page repConjunto Rep del TDA Almacen_Rutas
     */
    map<string, Ruta> rutas;

    public:
    /**
     * @brief Constructor por defecto
     * 
     * Usa el constructor de la clase @c map (STL)
     */
    Almacen_Rutas()=default;
    /**
     * @brief Constructor de copia
     * @param otro El almacén a copiar
     * 
     * Usa el constructor de copia de la clase @c map (STL)
     */
    Almacen_Rutas(const Almacen_Rutas& otro)=default;
    /**
     * @brief Operador de asignación
     * @param otro El almacén a copiar
     * @return El almacén para asignaciones encadenadas
     * 
     * Usa el operador de asignación de la clase @c map (STL)
     */
    Almacen_Rutas& operator=(const Almacen_Rutas& otro)=default;

    /**
     * @brief Método de búsqueda de una ruta
     * @param codigo El identificador de la ruta que queremos obtener
     * @return La ruta que corresponde a dicho codigo
     * 
     * Se basa en el método at de la clase @c map (STL)
     */
    Ruta GetRuta(string codigo);

    friend ostream& operator<<(ostream& out, const Almacen_Rutas& almacen);
    friend istream& operator>>(istream& in, Almacen_Rutas& almacen);
};

/**
 * @brief Operador de salida para el almacén de rutas
 * @param out El flujo de salida
 * @param almacen El almacen a mostrar
 * 
 * @return El flujo para sentencias encadenadas
 * 
 * @post Sintaxis: \n#Rutas\n[numRutas veces]<identificador> <Ruta> @see operator<<(ostream&, const Ruta&)
 */
ostream& operator<<(ostream& out, const Almacen_Rutas& almacen);
/**
 * @brief Operador de entrada para el almacén de rutas
 * @param in El flujo de entrada
 * @param almacen El almacen a insertar
 * 
 * @return el flujo para sentencias encadenadas
 * 
 * @post Sintaxis: @see operator<<
 */
istream& operator>>(istream& in, Almacen_Rutas& almacen);

#endif