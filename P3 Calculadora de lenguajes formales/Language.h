// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Calculadora de  lenguajes formales
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 18/10/2022
// Archivo: Language.h  Fichero cabecera de la clase Language
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 12/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Word.h"
#include <set>

class Language {
private:
  std::set<Word> language_;
  Alphabet alphabet_;
  std::string name_;

public:
  Language();
  Language(Word &, Alphabet &);
  Language(std::set<Word>, Alphabet&);
  ~Language();

  std::set<Word> GetLanguage();
  Alphabet GetAlphabet();
  std::string GetName();
  void SetAlphabet(Alphabet &);
  void SetLanguage(std::set<Word>);
  void SetName(std::string);

  bool Empty();
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