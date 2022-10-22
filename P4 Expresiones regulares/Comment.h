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

Comment::Comment() {}

Comment::~Comment() {}


Comment::Comment(std::string str, int n_line) {
  number_line_ini_ = n_line;
  comment_ = str;
}


Comment::Comment(std::string str, int n_line_ini, int n_line_end) {
  number_line_ini_ = n_line_ini;
  number_line_end_ = n_line_end;
  comment_ = str;
}

std::string Comment::GetComment() { 
  return comment_; 
}


void Comment::SetComment(std::string str) { 
  comment_ = str; 
}


void Comment::SetNumberLineIni(int n_line) { 
  number_line_ini_ = n_line; 
}


void Comment::SetNumberLineEnd(int n_line) { 
  number_line_end_ = n_line; 
}


void Comment::AddLine(std::string str) { 
  comment_ += "\n" + str; 
}


std::ostream &Comment::Write(std::ostream &os) {
  if (number_line_end_ == 0)
    os << "[line " << number_line_ini_ << "] " << comment_;
  else
    os << "[line " << number_line_ini_ << "-" << number_line_end_ << "] "
       << comment_;
  return os;
}


std::ostream &operator<<(std::ostream &os, Comment &comment) {
  return comment.Write(os);
}
