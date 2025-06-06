// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con lenguajes
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 11/10/2022
// Archivo: Word.h  Fichero cabecera de la clase Cadena
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 7/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Alphabet.h"
// #include "Language.h"

class Language;
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
  Language WordPrefixes();
  Language WordSuffixes();
  Language WordSubstrings();
  std::ostream &Write(std::ostream &os);

  bool operator<(const Word &) const;
  friend std::ostream &operator<<(std::ostream &, Word &);
  Word operator+(Word &);
  bool operator==(const Word &) const;
  bool operator!=(const Word &) const;
};