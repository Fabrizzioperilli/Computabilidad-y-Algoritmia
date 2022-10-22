// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: Comment.h Contiene la definicion de la clase Comment
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <iostream>

class Comment {
private:
  int number_line_ini_;
  int number_line_end_ = 0;
  std::string comment_;

public:
  Comment();
  ~Comment();
  Comment(std::string, int);
  Comment(std::string, int, int);

  std::string GetComment();
  void SetComment(std::string);
  void SetNumberLineIni(int);
  void SetNumberLineEnd(int);
  void AddLine(std::string);

  std::ostream &Write(std::ostream &);
  friend std::ostream &operator<<(std::ostream &, Comment &);
};