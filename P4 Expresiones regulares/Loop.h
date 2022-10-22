// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: Loop.h Definicion de la clase Loop
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <iostream>

class Loop {
private:
  std::string loop_for;
  std::string loop_while;
  int type_;
  int number_line_ = 0;

public:
  Loop();
  Loop(std::string, int, int);
  ~Loop();

  std::ostream &Write(std::ostream &);
  friend std::ostream &operator<<(std::ostream &, Loop &);
};