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

#pragma once
#include <iostream>

class Variable {
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
  bool Initialized(std::string);
  std::ostream &Write(std::ostream &);
  
  friend std::ostream &operator<<(std::ostream &, Variable &);
};