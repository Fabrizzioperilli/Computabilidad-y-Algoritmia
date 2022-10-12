// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Language.h    Cabecera de la clase lenguaje
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Word.h"
#include <set>

class Language {
private:
  std::set<Word> language_;
  Alphabet alphabet_;

public:
  Language();
  Language(Word &, Alphabet &);
  Language(std::set<Word>, Alphabet&);
  ~Language();

  std::set<Word> GetLanguage();
  Alphabet GetAlphabet();
  void SetAlphabet(Alphabet &);
  void SetLanguage(std::set<Word>);

  void AddWord(Word &);
  std::ostream &Write(std::ostream &);
  Language Concatenate(Language &);
  Language Union(Language &);
  Language Intersection(Language &);
  Language Difference(Language &);
  Language Inverse();
  Language Power(int);

  Language operator+(Language&);
  Language operator|(Language&) ;
  Language operator^(Language&) ;
  Language operator-(Language&) ;
  Language operator*(int) ;
  Language operator!() ;
  friend std::ostream &operator<<(std::ostream &, Language &);
};