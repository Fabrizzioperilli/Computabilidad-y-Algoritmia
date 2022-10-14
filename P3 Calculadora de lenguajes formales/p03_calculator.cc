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
void Split(std::string, int);
void check(std::string);

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
    check(line);
  }
  namefile.close();
}

// La funcion Split recorta las cadenas las almacena en un vector de vectores
void Split(std::string str, int pos_ini)
{
  std::vector<std::string> vector;
  std::string aux_string;

  for (size_t i = pos_ini; i < str.length(); i++)
  {
    if (str[i] != ' ' && str[i] != '{' && str[i] != '}' && str[i] != ',')
      aux_string += str[i];
    else if (aux_string != "")
    {
      vector.push_back(aux_string);
      aux_string = "";
    }
  }

  Alphabet alphabet;
  std::set<Word> aux;
  std::vector<Language> vector_language;
  for (size_t i = 0; i < vector.size(); i++)
  {
    Word word(vector[i], alphabet);
    aux.insert(word);
  }

  Language language(aux, alphabet);
  vector_language.push_back(language);
  Language lang_aux;
  Alphabet aux_alpha;
  for (size_t i = 0; i < vector_language.size(); i++)
  {
    lang_aux = vector_language[i];
    aux_alpha = lang_aux.GetAlphabet();

    std::cout << "Alfabeto: " << aux_alpha << std::endl;
    std::cout << "Lenguaje: " << lang_aux << std::endl;
  }

  std::cout << std::endl;
}

void check(std::string line)
{
  bool flag = false;
  int pos = 0;
  for (size_t i = 0; i < line.length(); i++)
    if (line[i - 1] == ' ' && line[i] == '=' && line[i + 1] == ' ')
    {
      flag = true;
      pos = i + 1;
    }

  if (flag)
  {
    std::cout << "Definicion del lengauje. Posicion donde empieza: " << pos << std::endl;
    Split(line, pos);
  }
  else
    std::cout << "Operacion" << std::endl;
}