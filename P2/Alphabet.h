// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 11/10/2022
// Archivo: Alphabet.h  Fichero cabecera de la clase Alfabeto
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 7/10/2022 - Versión: 1.0 - Descripción: Creación del código.

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

  std::set<Symbol> getAlphabet() const;

  void AddSymbol(Symbol &);
  void AddSymbol(std::string str);
  bool Empty();
  int Size();
  bool Search(std::string);
  std::ostream &Write(std::ostream &);
  Alphabet Union(const Alphabet &);

  friend std::ostream &operator<<(std::ostream &, Alphabet &);
};