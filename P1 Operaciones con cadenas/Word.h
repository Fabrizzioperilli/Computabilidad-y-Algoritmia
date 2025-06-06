// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Word.h  Cabecera de la clase cadena
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Alphabet.h"

const std::string STR_EMPTY = "&";

class Word {
 private:
  Alphabet alphabet_;
  std::vector<Symbol> word_;

 public:
  Word();
  Word(std::string, Alphabet &);
  ~Word();

  int WordLength();
  void WordInverse(std::ostream &);
  void WordPrefixes(std::ostream &);
  void WordSuffixes(std::ostream &);
  void WordSubstrings(std::ostream &);

  void Write();
};