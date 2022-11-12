/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: NonTerminalSymbol.h  Clase NonTerminalSymbol
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#pragma once

#include <iostream>
#include <set>

class NonTerminalSymbol {
 private:
  char name_;

 public:
  NonTerminalSymbol();
  NonTerminalSymbol(char);
  ~NonTerminalSymbol();
  char GetName() const;
  void SetName(char);

  std::ostream &WriteNonTerminalSymbol(std::ostream &);
  friend std::ostream &operator<<(std::ostream &, NonTerminalSymbol &);
  bool operator<(const NonTerminalSymbol &) const;
  bool operator==(const NonTerminalSymbol &) const;
};