// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Alphabet.h  Cabecera de la clase alfabeto
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

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

  void AddSymbol(Symbol &);
  void AddSymbol(std::string str);
  
  bool Empty();
  std::set<Symbol> getAlphabet();
  int Size();
  bool Search(std::string);
  std::ostream& Write(std::ostream&);
  friend std::ostream& operator<<(std::ostream&, Alphabet&);
   
 

};