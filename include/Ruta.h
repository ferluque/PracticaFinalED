/**
 * @file Ruta.h
 * @brief Fichero de cabecera para el TDA Ruta
 * @author Fernando Luque (fl1562001@correo.ugr.es)
 * 
 * Declara un TDA Ruta que nos permite almacenar una sucesión ordenada de puntos
 * que representan los distintos países por los que pasará un determinado vuelo
 * 
 */

#ifndef __RUTA__
#define __RUTA__
#include "Paises.h"
#include <list>

using namespace std;

/**
 * @brief TDA Ruta
 * 
 * Una instancia @e r del tipo @c Ruta es un objeto que representa el trayecto (las paradas)
 * de un avión. Se representan por tanto una serie de puntos (coordenadas geográficas) que 
 * indican en qué países parará dicho vuelo
 * 
 * @author Fernando Luque (fl1562001@correo.ugr.es)
 * @date Enero 2021
 */
class Ruta
{
private:
    /**
     * @page repConjunto Rep del TDA Punto
     */
    list<Punto> puntos;

public:
    /**
     * @brief Constructor sin parámetros
     * 
     * Usa el constructor de la clase @c list (STL)
     */
    Ruta() = default;
    /**
     * @brief constructor de copia
     * @param otra La ruta a copiar
     * 
     * Usa el constructor de copia de la clase @c list (STL)
     */
    Ruta(const Ruta &otra) = default;
    /**
     * @brief Operador de asignación
     * @param otra La ruta a copiar
     * 
     * @return La ruta para asignaciones encadenadas
     * 
     * Usa el operador de asignación de la clase @c list (STL)
     */
    Ruta &operator=(const Ruta &otra) = default;
    
    friend istream &operator>>(istream &in, Ruta &ruta);
    friend ostream &operator<<(ostream &out, const Ruta &ruta);

    /**
     * @brief Clase iteradora Ruta
     * 
     * Utilizada para iterar la lista de puntos que componen la ruta.
     * Se basa en el iterador de la clase @c list con el parámetro Punto
     */
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
    /**
     * @brief Comienzo de la lista
     * @return Iterador al principio de la Ruta (primer punto)
     */
    iterator begin();
    /**
     * @brief Fin de la lista
     * @return Iterador al final de la Ruta (posterior al último punto)
     */
    iterator end();

    /**
     * @brief Clase iteradora constante Ruta
     * 
     * @see iterator
     * 
     * Similar a la clase Ruta::iterator pero para Rutas constantes
     */
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
    /**
     * @brief Principio de una Ruta constante
     * @see begin
     */
    const_iterator cbegin() const;
    /**
     * @brief Final de una Ruta constante
     * @see end
     */
    const_iterator cend() const;
};

/**
 * @brief Operador de entrada para una ruta
 * @param in El flujo de entrada
 * @param ruta La ruta a introducir
 * 
 * @return El flujo para sentencias encadenadas
 * 
 * @pre Sintaxis de la entrada: <num_puntos>[ ,\\n,\\t]<Punto>
 * @see operator>>(istream&, Punto&)
 */
istream &operator>>(istream &in, Ruta &ruta);

/**
 * @brief Operador de salida para una ruta
 * @param out El flujo de salida
 * @param ruta La ruta a mostrar
 * @return El flujo para sentencias encadenadas
 * @post Sintaxis de la salida: @see operator>>(istream&, Ruta&)
 */
ostream &operator<<(ostream &out, const Ruta &ruta);
#endif