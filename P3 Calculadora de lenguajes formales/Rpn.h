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
      {
        stack_.push(languages[std::stoi(aux[j]) - 1]);
        // std::cout << "Lenguaje " << aux[j] << " : " << languages[std::stoi(aux[j]) - 1] << std::endl;
      }
      else
      {
        Operate(aux[j]);
        // std::cout << "Operacion " << aux[j] << std::endl;
      }
    }
  
    vector_result.push_back(stack_.top());
    stack_.pop();
  }
  

    return vector_result;
}

void Rpn::Operate(std::string operation)
{
  Language aux;
  Language aux2;
  Language aux3;

  // Sacamos los dos lenguajes de la pila
  aux = stack_.top();
  stack_.pop();
  aux2 = stack_.top();
  stack_.pop();

  char op = operation[0];

  switch (op)
  {
  case '+':
    aux3 = aux + aux2;
    break;
  case '|':
    aux3 = aux | aux2;
    break;
  case '^':
    aux3 = aux ^ aux2;
    break;
  case '-':
    aux3 = aux - aux2;
    break;
  case '!':
    aux3 = aux;
    !aux3;
    break;
  default:
    std::cout << "Operacion no valida" << std::endl;
    break;
  }
    stack_.push(aux3);
}
