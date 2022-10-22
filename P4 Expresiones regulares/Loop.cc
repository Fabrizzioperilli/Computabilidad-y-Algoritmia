// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: Loop.cc Implementacion de la clase Loop
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Loop.h"

Loop::Loop() {}


Loop::Loop(std::string str, int n_line, int type) {
  type_ = type;
  number_line_ = n_line;

  if (type_ == 1)
    loop_for = str;
  else if (type_ == 2)
    loop_while = str;
}


Loop::~Loop() {}


std::ostream &Loop::Write(std::ostream &os) {

  os << "[line " << number_line_ << "] LOOP: ";
  if (type_ == 1)
    os << "for";
  else if (type_ == 2)
    os << "while";
  return os;
}


std::ostream &operator<<(std::ostream &os, Loop &loop) {
  return loop.Write(os);
}