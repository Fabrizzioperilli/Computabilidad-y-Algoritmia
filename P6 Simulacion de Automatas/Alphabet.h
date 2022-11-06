/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 6: Simulacion de Automatas Finitos
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 18/10/2022
* @file Archivo: Alphabet.h
*        Clase Alphabet
* Referencias:
* @version Historial de revisiones:12/10/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#pragma once
#include "Symbol.h"
#include <set>

class Alphabet {
private:
  std::set<Symbol> alphabet_;

public:
  Alphabet();
  Alphabet(std::set<Symbol>);
  ~Alphabet();

  std::set<Symbol> GetAlphabet() const;

  void AddSymbol(Symbol &);
  void AddSymbol(std::string str);
  bool Empty();
  int Size();
  bool Search(std::string);
  std::ostream &Write(std::ostream &);
  Alphabet Union(const Alphabet &);
  bool CheckSymbol(Symbol &);

  friend std::ostream &operator<<(std::ostream &, Alphabet &);
};