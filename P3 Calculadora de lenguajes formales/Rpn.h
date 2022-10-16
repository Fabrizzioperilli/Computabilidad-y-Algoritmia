// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Calculadora de  lenguajes formales
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 18/10/2022
// Archivo: Rpn.h Definicion de la clase Rpn (calculadora de lenguajes formales)
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 12/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Alphabet.h"
#include "Language.h"
#include "Word.h"
#include <iostream>
#include <stack>
#include <string>

bool isNumber(std::string);
typedef std::vector<std::vector<std::string>> vector_operation;

class Rpn {
private:
  std::stack<Language> stack_;
  void Operate(std::string);
  int n_;

public:
  Rpn();
  ~Rpn();
  std::vector<Language> Calculate(std::vector<Language>, vector_operation);
};
