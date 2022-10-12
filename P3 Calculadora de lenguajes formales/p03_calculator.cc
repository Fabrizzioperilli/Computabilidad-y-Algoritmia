// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Calculadora de  lenguajes formales
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 18/10/2022
// Archivo: p03_calculator.cc Programa cliente
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 12/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "Alphabet.h"
#include "Language.h"
#include "Symbol.h"
#include "Word.h"

typedef std::vector<std::vector<std::string>> vector_alph_lg;

void Help();
void Read(char *);
vector_alph_lg Split(std::string);
int Divide(std::string);

int main(int argc, char **argv) {
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 2;

  if ((argc == kNumberParam) && (argv[1] != kOptionHelp)) {
    std::cout << "Lectura del fichero: " << argv[1] << std::endl;
    Read(argv[1]);
    
  } else if ((argc == kNumberParam) && (argv[1] == kOptionHelp)) {
    Help();
    return -1;

  } else {
    std::cout << "Error al ejecutar." << std::endl;
    std::cout << "Ejecute ./p02_languages --help para mas informacion" << std::endl;
    return -1;
  }
  return EXIT_SUCCESS;
}


void Help() {
  std::cout << "Modo de funcionamiento: " << std::endl;
  std::cout << "./p03_calculadora FicheroEntrada.txt " << std::endl;
  std::cout << "---Operaciones con lenguajes---" << std::endl;
  std::cout << " + Concatenacion" << std::endl;
  std::cout << " | Union" << std::endl;
  std::cout << " ^ Interseccion" << std::endl;
  std::cout << " - Diferencia" << std::endl;
  std::cout << " ! Inversa" << std::endl;
  std::cout << " * Potencia" << std::endl;
}


void Read(char *file_input) {
  std::ifstream namefile(file_input);
  std::cout << "Read" << std::endl;
}


// La funcion Split recorta las cadenas las almacena en un vector de vectores
vector_alph_lg Split(std::string str) {
  vector_alph_lg vector;
  std::vector<std::string> vector_alphabet;
  std::vector<std::string> vector_language;
  std::string aux_alpha;
  std::string aux_lenguage;
  int half = Divide(str);

  for (int i = 0; i < half; i++) {
    if (str[i] != ' ' && str[i] != '{' && str[i] != '}')
      aux_alpha += str[i];
    else if (aux_alpha != "") {
      vector_alphabet.push_back(aux_alpha);
      aux_alpha = "";
    }
  }

  for (size_t i = half; i < str.length(); i++) {
    if (str[i] != ' ' && str[i] != '{' && str[i] != '}')
      aux_lenguage += str[i];
    else if (aux_lenguage != "") {
      vector_language.push_back(aux_lenguage);
      aux_lenguage = "";
    }
  }
  vector.push_back(vector_alphabet);
  vector.push_back(vector_language);

  return vector;
}


//Retorna la posicion donde se encuentra el espacio entre alfabeto y lenguaje
int Divide(std::string str) {
  int pos;
  for (size_t i = 0; i < str.length(); i++)
    if (str[i] == ' ' && str[i - 1] == '}' && str[i + 1] == '{')
      pos = i;
  return pos;
}