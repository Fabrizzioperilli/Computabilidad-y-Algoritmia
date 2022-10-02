// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo p01_strings.cc: programa cliente.
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <string.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Alphabet.h"
#include "Symbol.h"
#include "Word.h"

void Help();
void Read(char *, char *, int);
void Write(std::ofstream &, std::vector<Word>, int);
std::vector<std::string> Split(std::string, char);


int main(int argc, char *argv[]) {
  const std::string kOptionHelp = "--help";

  if (argc == 4) {
    int opcode = atoi(argv[3]);
    std::cout << "Compruebe la salida en el fichero: " << argv[2] << std::endl;
    Read(argv[1], argv[2], opcode);
  } 
  else if ((argc == 2) && (argv[1] == kOptionHelp)) {
    Help();
    return -1;
  } 
  else {
    std::cout << "Error al ejecutar." << std::endl;
    std::cout << "Ejecute ./p01_strings --help para mas informacion" << std::endl;
    return -1;
  }

  return 0;
}


void Help() {
  std::cout << "Modo de funcionamiento: " << std::endl;
  std::cout << "./p01_strings FicheroEntrada.txt FicheroSalida.txt NumeroOperacion" << std::endl;
  std::cout << "--Operaciones con cadenas" << std::endl;
  std::cout << "1 Longitud" << std::endl;
  std::cout << "2 Inversa" << std::endl;
  std::cout << "3 Prefijos" << std::endl;
  std::cout << "4 Sufijos" << std::endl;
  std::cout << "5 Subcadenas" << std::endl;
}


void Read(char *file_input, char *file_output, int opcode) {
  std::string line;
  std::ifstream namefile_input(file_input);
  std::ofstream namefile_output(file_output);
      
  std::vector<std::string> split_line;
  std::vector<Word> word_vector;

  while (!namefile_input.eof()) {
    getline(namefile_input, line);
    split_line = Split(line, ' ');
    Alphabet alphabet;
    
    for (size_t i = 0; i < split_line.size() - 1; i++)
      if (split_line[i] != STR_EMPTY) {
        Symbol symbol;
        symbol.SetSymbol(split_line[i]);
        alphabet.AddSymbol(symbol);
      }

    Word word(split_line.back(), alphabet);
    word_vector.push_back(word);
  }
  namefile_input.close();
  Write(namefile_output, word_vector, opcode);
}


void Write(std::ofstream &namefile_output, std::vector<Word> word_vector, int opcode) {
  switch (opcode) {
    case 1:
      namefile_output << "Longitud de la cadena" << std::endl;
      for (size_t i = 0; i < word_vector.size(); i++)
        namefile_output << word_vector[i].WordLength() << std::endl;
      break;
    case 2:
      namefile_output << "Inversa de la cadena" << std::endl;
      for (size_t i = 0; i < word_vector.size(); i++)
        word_vector[i].WordInverse(namefile_output);
      break;
    case 3:
      namefile_output << "Prefijos de la cadena" << std::endl;
      for (size_t i = 0; i < word_vector.size(); i++)
        word_vector[i].WordPrefixes(namefile_output);
      break;
    case 4:
      namefile_output << "Sufijos de la cadena" << std::endl;
      for (size_t i = 0; i < word_vector.size(); i++)
        word_vector[i].WordSuffixes(namefile_output);
      break;
    case 5:
      namefile_output << "Subcadenas de la cadena" << std::endl;
      for (size_t i = 0; i < word_vector.size(); i++)
        word_vector[i].WordSubstrings(namefile_output);
      break;

    default:
      std::cout << "Error al ejecutar." << std::endl;
      std::cout << "Ejecute ./p01_strings --help para mas informacion" << std::endl;
      break;
  }
  namefile_output.close();
}

//La funcion Split recorta el string a partir de un delimitador
std::vector<std::string> Split(std::string str, char pattern) {
  int pos_init = 0;
  int pos_found = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (pos_found >= 0) {
    pos_found = str.find(pattern, pos_init);
    splitted = str.substr(pos_init, pos_found - pos_init);
    pos_init = pos_found + 1;
    results.push_back(splitted);
  }
  return results;
}