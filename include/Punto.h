/**
 * @file Punto.h
 * @brief Fichero cabecera para el TDA Punto
 * @author Fernando Luque (fl1562001@correo.ugr.es)
 * 
 * Declara un TDA Punto que nos permite representar un punto en dos dimensiones
 * 
 */

#ifndef __PUNTO_H
#define __PUNTO_H

#include <iostream>

/**
 * @brief TDA Punto
 * 
 * Una instancia @e p del tipo @c Punto es un objeto que representa un punto en dos dimensiones
 * con sus dos coordenadas x e y
 * 
 * @author Fernando Luque (fl1562001@correo.ugr.es)
 * @date Enero 2021 
 * 
 */
struct Punto
{
    /**
     * @page repConjunto Rep del TDA Punto
     */
    double x, y;

    /**
     * @brief Constructor sin parámetros
     * 
     * Inicializa a 0
     */
    Punto();
    /**
     * @brief Constructor con parámetros
     */
    Punto(double, double);
    /**
     * @brief Operador de asignación
     * @param otro Iguala las coordenadas
     * 
     * @return El propio punto para sentencias encadenadas
     */
    Punto& operator=(const Punto&);
    /**
     * @brief Operador de comparación
     * @param otro Compara si ambos puntos tienen las mismas coordenadas
     * 
     * @return true si iguales // false si no
     */
    bool operator==(const Punto&) const;
};

/**
 * @brief Operador de entrada para un punto
 * @param in El flujo de entrada
 * @param p El punto a introducir
 * @pre Sintaxis del punto: (x,y)
 * 
 * @return El flujo para sentencias encadenadas
 */
std::istream& operator>>(std::istream& in, Punto& p);

/**
 * @brief Operador de salida para un punto
 * @param out El flujo de salida
 * @param p El punto a mostrar
 * @post Sintaxis de salida: (x,y)
 * 
 * @return El flujo para sentencias encadenadas
 */
std::ostream &operator<<(std::ostream &out, const Punto &p);

#endif