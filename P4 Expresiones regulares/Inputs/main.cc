/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 *  Grado en Ingenierıa Informatica
 *  Asignatura: Algoritmos y Estructuras de Datos Avanzados
 *  Curso: 2º
 *  Practica 1: El juego de la vida
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha entrega: 7/03/2021
 * @file Archivo:
 *        Contiene la funcion main del proyecto.
 */

#include <iostream>
#include "../include/Grid.h"


int main()
{
    int n, m;
    unsigned turns;

    std::cout << "---El juego de la vida---" << std::endl;
    std::cout << "Número de filas del tablero (>2): ";
    std::cin >> n;

    std::cout << "Número de columnas del tablero (>2): ";
    std::cin >> m;

    std::cout << "Número de de turnos: ";
    std::cin >> turns;
    std::cout << std::endl;

    Grid table(n, m, turns);
    return 0;
}