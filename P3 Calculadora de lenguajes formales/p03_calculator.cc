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

void Help();
void Read(char *);
std::vector<std::string> Split(std::string);
int Position(std::string str);

int main(int argc, char **argv)
{
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 2;

  if ((argc == kNumberParam) && (argv[1] != kOptionHelp))
  {
    std::cout << "Lectura del fichero: " << argv[1] << std::endl;
    Read(argv[1]);
  }
  else if ((argc == kNumberParam) && (argv[1] == kOptionHelp))
  {
    Help();
    return -1;
  }
  else
  {
    std::cout << "Error al ejecutar." << std::endl;
    std::cout << "Ejecute ./p02_languages --help para mas informacion" << std::endl;
    return -1;
  }
  return EXIT_SUCCESS;
}

void Help()
{
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

void Read(char *file_input)
{
  std::string line;
  std::ifstream namefile(file_input);
  std::vector<std::string> vector_word;
  std::vector<std::vector<std::string>> vector_vector;


  while (!namefile.eof())
  {
    getline(namefile, line);
    vector_word = Split(line);
    vector_vector.push_back(vector_word);
  }
  std::vector<std::string> aux;
  
  for (size_t i = 0; i < vector_vector.size(); i++) {
    for (size_t j = 0; j < vector_vector[i].size(); j++)
      std::cout << vector_vector[i][j];
    
  }
    
  namefile.close();
}

// La funcion Split recorta las cadenas las almacena en un vector de vectores
std::vector<std::string> Split(std::string str)
{
  std::vector<std::string> vector;
  std::string aux_string;
  int ini = Position(str);
  
    for (size_t i = ini; i < str.length(); i++)
    {
      if (str[i] != ' ' && str[i] != '{' && str[i] != '}' && str[i] != ',')
        aux_string += str[i];
      else if (aux_string != "")
      {
        vector.push_back(aux_string);
        aux_string = "";
      }
    }
  return vector;
}

int Position(std::string str)
{
  int pos;
  for (size_t i = 0; i < str.length(); i++)
    if (str[i - 1] == '=' && str[i] == ' ')
      pos = i;
  
  return pos;
}