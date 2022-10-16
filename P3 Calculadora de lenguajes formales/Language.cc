// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Calculadora de  lenguajes formales
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 18/10/2022
// Archivo: Language.cc Implementacion de la clase Language
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 12/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Language.h"

Language::Language() {}


Language::Language(Word &word, Alphabet &alphabet) {
  language_.insert(word);
  if (!alphabet.Empty())
    alphabet_ = alphabet;
  else
    alphabet_ = word.GetAlphabet();
}


Language::Language(std::set<Word> language, Alphabet &alpha) {
  language_ = language;
  if (!alpha.Empty())
    alphabet_ = alpha;
  else
    for (auto i : language_)
      for (auto j : i.GetWord())
        alphabet_.AddSymbol(j.GetSymbol());
}


Language::~Language() {}


std::set<Word> Language::GetLanguage() { 
  return language_; 
}


Alphabet Language::GetAlphabet() { 
  return alphabet_; 
}


std::string Language::GetName() { 
  return name_; 
}


void Language::SetAlphabet(Alphabet &alphabet) { 
  alphabet_ = alphabet; 
}


void Language::SetLanguage(std::set<Word> language) { 
  language_ = language; 
}


void Language::SetName(std::string name) { 
  name_ = name; 
}


bool Language::Empty() { 
  return language_.empty(); 
}


void Language::AddWord(Word &word) { 
  language_.insert(word); 
}


std::ostream &Language::Write(std::ostream &os) {
  for (auto i : language_)
    os << i << " ";
  return os;
}


Language Language::Concatenate(Language &language) {
  Language result;
  Alphabet alpha = alphabet_.Union(language.GetAlphabet());
  result.SetAlphabet(alpha);

  Word word_empty(STR_EMPTY, alphabet_);
  for (auto i : language_)
    for (auto j : language.GetLanguage()) {
      Word word;
      if (i == word_empty)
        result.AddWord(j);
      else if (j == word_empty)
        result.AddWord(i);
      else {
        word = i + j;
        result.AddWord(word);
      }
    }
  return result;
}


Language Language::Union(Language &language) {
  Language result;
  Alphabet alpha = alphabet_.Union(language.GetAlphabet());
  result.SetAlphabet(alpha);

  for (auto i : language_)
    result.AddWord(i);
  for (auto i : language.GetLanguage())
    result.AddWord(i);
  return result;
}


Language Language::Intersection(Language &language) {
  Language result;
  result.SetAlphabet(alphabet_);

  for (auto i : language_)
    for (auto j : language.GetLanguage()) 
      if (i == j)
        result.AddWord(i);
    
  return result;
}


Language Language::Difference(Language &language) {
  Language result;
  result.SetAlphabet(alphabet_);

  for (auto i : language_)
    for (auto j : language.GetLanguage()) 
      if (i != j)
        result.AddWord(i);
    
  return result;
}


Language Language::Inverse() {
  Language result;
  result.SetAlphabet(alphabet_);

  for (auto i : language_) {
    Word word = i.WordInverse();
    result.AddWord(word);
  }
  return result;
}


Language Language::Power(int n = 1) {
  Language result;
  result.SetAlphabet(alphabet_);
  Word word_empty(STR_EMPTY, alphabet_);

  for (auto i : language_) {
    Word word = i;
    if (i != word_empty) {
      for (int j = 1; j < n; j++)
        word = word + i;
      result.AddWord(word);
    } else
      result.AddWord(word_empty);
  }
  return result;
}


Language Language::operator+(Language &second_language) {
  Language first_language(language_, alphabet_);
  return first_language.Concatenate(second_language);
}


Language Language::operator|(Language &second_language) {
  Language first_language(language_, alphabet_);
  return first_language.Union(second_language);
}


Language Language::operator^(Language &second_language) {
  Language first_language(language_, alphabet_);
  return first_language.Intersection(second_language);
}


Language Language::operator-(Language &second_language) {
  Language first_language(language_, alphabet_);
  return first_language.Difference(second_language);
}


Language Language::operator*(int n) {
  Language language(language_, alphabet_);
  return language.Power(n);
}


Language Language::operator!() {
  Language language(language_, alphabet_);
  return language.Inverse();
}


std::ostream &operator<<(std::ostream &os, Language &language) {
  return language.Write(os);
}