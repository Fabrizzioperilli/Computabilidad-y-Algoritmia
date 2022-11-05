// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Calculadora de  lenguajes formales
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 18/10/2022
// Archivo: Word.h  Fichero cabecera de la clase Word (Cadena)
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 12/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Alphabet.h"


class Word {
private:
  Alphabet alphabet_;
  std::vector<Symbol> word_;

public:
  Word();
  Word(std::string, Alphabet &);
  ~Word();

  std::vector<Symbol> GetWord();
  void SetWord(std::vector<Symbol>);
  Alphabet GetAlphabet();
  void SetAlphabet(Alphabet &);

  void AddSymbol(Symbol &);
  int WordLength();
  Word WordInverse();
  Word WordConcatenate(Word &);
  std::ostream &Write(std::ostream &os);

  bool operator<(const Word &) const;
  friend std::ostream &operator<<(std::ostream &, Word &);
  bool operator==(const Word &) const;
  bool operator!=(const Word &) const;
  Word operator+(Word &);
};