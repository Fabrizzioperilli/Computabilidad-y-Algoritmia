// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: Variable.h Definicion de la clase variable
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <iostream>
#pragma once
class Variable
{
private:
  std::string varname_int_;
  std::string varname_double_;
  unsigned type_;
  int number_line_;
  bool initialized_ = false;

public:
  Variable();
  Variable(std::string, int, unsigned);
  ~Variable();
  int GetNumberLine();

  std::ostream &Write(std::ostream &);
  friend std::ostream &operator<<(std::ostream &, Variable &);
  bool Initialized(std::string);
};


Variable::Variable(){}


Variable::~Variable(){}


Variable::Variable(std::string var, int n_line, unsigned type_var)
{
  number_line_ = n_line;
  type_ = type_var;
  
  if (Initialized(var))
    initialized_ = true;

  switch (type_)
  {
  case 1:
    varname_int_ = var.substr(var.find("int"), (var.find(";") - var.find("int")));
    break;
  case 2:
    varname_double_ = var.substr(var.find("double"), (var.find(";") - var.find("double")));
    break;
  default:
    break;
  }
}


int Variable::GetNumberLine() {
  return number_line_;
}


std::ostream &Variable::Write(std::ostream &os)
{
  os << "[line " << number_line_ << "] ";
  if (type_ == 1) 
    os << "INT: " << varname_int_.erase(varname_int_.find("int"), 3);

  else if (type_ == 2)
    os << "DOUBLE: " << varname_double_.erase(varname_double_.find("double"), 6);
  return os;
}


std::ostream &operator<<(std::ostream &os, Variable &var)
{
  return var.Write(os);
}


bool Variable::Initialized(std::string str) {
  for (size_t i = 0; i < str.length(); i++)
    if (str[i] == '=')
      return true;
  return false;
}