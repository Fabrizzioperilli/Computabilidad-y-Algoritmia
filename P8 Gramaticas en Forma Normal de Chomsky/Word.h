/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 8: Graticas en Forma Normal de Chomsky
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 22/11/2022
 * @file Archivo: Word.h  Clase Word
 * Referencias:
 * @version Historial de revisiones:23/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

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
  std::vector<Symbol> GetWord() const;
  void SetWord(std::vector<Symbol>);
  Alphabet GetAlphabet();
  void SetAlphabet(Alphabet &);

  void AddSymbol(Symbol &);
  int WordLength();
  Word WordInverse();
  Word WordConcatenate(Word &);
  void ModifySymbol(int, Symbol &);
  std::ostream &Write(std::ostream &os);

  Word operator+(Word &);
  bool operator<(const Word &) const;
  bool operator==(const Word &) const;
  bool operator!=(const Word &) const;
  friend std::ostream &operator<<(std::ostream &, Word &);
  friend std::istream &operator>>(std::istream &, Word &);
};