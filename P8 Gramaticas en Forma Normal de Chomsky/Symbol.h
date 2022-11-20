/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 8: Graticas en Forma Normal de Chomsky
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 22/11/2022
 * @file Archivo: Symbol.h  Clase Symbol
 * Referencias:
 * @version Historial de revisiones:23/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#pragma once

#include <iostream>
#include <string.h>
#include <vector>

const std::string STR_EMPTY = "&";

class Symbol {
private:
  std::string symbol_;

public:
  Symbol();
  Symbol(std::string);
  ~Symbol();

  std::string GetSymbol();
  void SetSymbol(std::string);
  int SymbolSize();
  std::ostream &Write(std::ostream &os);

  bool operator<(const Symbol &) const;
  friend std::ostream &operator<<(std::ostream &, Symbol &);
  bool operator==(const Symbol &) const;
  Symbol operator=(const Symbol &);
  bool operator!=(const Symbol &) const;
  friend std::istream &operator>>(std::istream &, Symbol &);

};