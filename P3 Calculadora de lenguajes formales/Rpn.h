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
#include "Language.h"
#include "Alphabet.h"
#include "Word.h"
#include <stack>
#include <string>
#include <iostream>

class Rpn
{
private:
  std::stack<Language> stack_;
  void Operate(std::string);

public:
  Rpn();
  ~Rpn();
  std::vector<Language> Calculate(std::vector<Language>, std::vector<std::vector<std::string>>);
};

Rpn::Rpn() {}
Rpn::~Rpn() {}

std::vector<Language> Rpn::Calculate(std::vector<Language> languages, std::vector<std::vector<std::string>> operations)
{
  std::vector<std::string> aux;
  Language result_language;
  std::vector<Language> vector_result;

  for (size_t i = 0; i < operations.size(); i++)
  {
    aux = operations[i];
    for (size_t j = 0; j < aux.size(); j++)
    {
      // Si la cadena es cualquier numero, se busca el lenguaje en el vector de lenguajes
      if (isdigit(aux[j][0]))
        stack_.push(languages[std::stoi(aux[j]) - 1]);
      else
        Operate(aux[j]);
    }
    vector_result.push_back(stack_.top());
    stack_.pop();
  }

  // //imprimir el vector de lenguajes
  // for (size_t i = 0; i < languages.size(); i++)
  //   std::cout << "Lenguaje " << i + 1 << ": " << languages[i]<< std::endl;
  // //imprimer el vector de operaciones
  // for (size_t i = 0; i < operations.size(); i++)
  // {
  //   aux = operations[i];
  //   for (size_t j = 0; j < aux.size(); j++)
  //     std::cout << aux[j] << "";
  //   std::cout << std::endl;
  // }

  return vector_result;
}

void Rpn::Operate(std::string operation)
{
  std::vector<Language> aux;
  for (size_t i = 0; i < 2; i++)
    if (!stack_.empty())
    {
      aux.push_back(stack_.top());
      stack_.pop();
    }

  char op = operation[0];

  switch (op)
  {
  case '+':
    stack_.push(aux[0] + aux[1]);
    break;
  case '|':
    stack_.push(aux[0] | aux[1]);
    break;
  case '^':
    stack_.push(aux[0] ^ aux[1]);
    break;
  case '-':
    stack_.push(aux[0] - aux[1]);
    break;
  case '!':
    stack_.push(!aux[0]);
    break;
  default:
    std::cout << "Operacion no valida" << std::endl;
    break;
  }
}
