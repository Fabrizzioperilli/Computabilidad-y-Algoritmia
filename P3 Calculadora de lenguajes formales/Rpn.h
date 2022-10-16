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

bool isNumber(std::string);

class Rpn
{
private:
  std::stack<Language> stack_;
  void Operate(std::string);
  int n_;

public:
  Rpn();
  ~Rpn();
  std::vector<Language> Calculate(std::vector<Language>, std::vector<std::vector<std::string>>);
};

Rpn::Rpn() {}

Rpn::~Rpn() {}

bool isNumber(std::string str)
{
  for (size_t i = 0; i < str.length(); i++)
    if (isdigit(str[i]) == false)
      return false;
  return true;
}


std::vector<Language> Rpn::Calculate(std::vector<Language> languages, std::vector<std::vector<std::string>> operations)
{
  std::vector<std::string> aux;
  Language result_language;
  std::vector<Language> vector_result;

  for (auto i : operations)
  {
    for (auto j : i)
    {
      if (j == "+" || j == "|" || j == "^" || j == "-" || j == "*" || j == "!")
        Operate(j);
      //si j es un numero se lo asignamos a n_
      else if (isNumber(j)) { 
        n_ = std::stoi(j);
      }
      else
      {
        for (auto k : languages) 
          if (k.GetName() == j)
            stack_.push(k);
          
        }
      }
    
    result_language = stack_.top();
    stack_.pop();
    vector_result.push_back(result_language);
  }

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
  case '*':
    stack_.push(aux[0] * n_);
    break;
  default:
    std::cout << "Operacion no valida" << std::endl;
    break;
  }
}
