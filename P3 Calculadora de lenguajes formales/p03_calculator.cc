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
void Read(char *, char *, char *, int);
vector_alph_lg Split(std::string);
int Divide(std::string);

int main(int argc, char **argv) {
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 5;

  if (argc == kNumberParam) {
    int opcode = atoi(argv[4]);
    std::cout << "Compruebe la salida en el fichero: " << argv[3] << std::endl;
    Read(argv[1], argv[2], argv[3], opcode);
    
  } else if ((argc == 2) && (argv[1] == kOptionHelp)) {
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
  std::cout << "./p02_languages FicheroEntrada1.txt FicheroEntrada2.txt FicheroSalida.txt NumeroOperacion" << std::endl;
  std::cout << "--Operaciones con cadenas" << std::endl;
  std::cout << "1. Concatenacion" << std::endl;
  std::cout << "2. Union" << std::endl;
  std::cout << "3. Interseccion" << std::endl;
  std::cout << "4. Diferencia" << std::endl;
  std::cout << "5. Inversa" << std::endl;
  std::cout << "6. Potencia" << std::endl;
}


void Read(char *file_input1, char *file_input2, char *file_output, int opcode) {
  std::ifstream namefile1(file_input1);
  std::ifstream namefile2(file_input2);
  std::ofstream namefile_output(file_output);

  std::string string_line_file1;
  std::string string_line_file2;

  std::vector<std::string> vector_symbols_file1;
  std::vector<std::string> vector_words_file1;

  std::vector<std::string> vector_symbols_file2;
  std::vector<std::string> vector_words_file2;

  vector_alph_lg vector_aux_file1;
  vector_alph_lg vector_aux_file2;

  int n;
  if (opcode == 6) {
    std::cout << "Para realizar la operacion de potencia introduzca el valor de n: ";
    std::cin >> n;
  }

  while (!namefile1.eof() && !namefile2.eof()) {
    getline(namefile1, string_line_file1);
    getline(namefile2, string_line_file2);

    vector_aux_file1 = Split(string_line_file1);
    vector_aux_file2 = Split(string_line_file2);

    vector_symbols_file1 = vector_aux_file1[0];
    vector_words_file1 = vector_aux_file1[1];

    vector_symbols_file2 = vector_aux_file2[0];
    vector_words_file2 = vector_aux_file2[1];

    Alphabet alphabets_file1;
    Alphabet alphabets_file2;

    for (size_t i = 0; i < vector_symbols_file1.size(); i++)
      alphabets_file1.AddSymbol(vector_symbols_file1[i]);

    for (size_t i = 0; i < vector_symbols_file2.size(); i++)
      alphabets_file2.AddSymbol(vector_symbols_file2[i]);

    Language languages_file1;
    Language languages_file2;

    for (size_t i = 0; i < vector_words_file1.size(); i++) {
      Word word(vector_words_file1[i], alphabets_file1);
      languages_file1.AddWord(word);
    }

    for (size_t i = 0; i < vector_words_file2.size(); i++) {
      Word word(vector_words_file2[i], alphabets_file2);
      languages_file2.AddWord(word);
    }

    languages_file1.SetAlphabet(alphabets_file1);
    languages_file2.SetAlphabet(alphabets_file2);

    Language language_result;
    Alphabet alphabet_result;
    
    switch (opcode) {
    case 1:
      language_result = languages_file1 + languages_file2;
      alphabet_result = language_result.GetAlphabet();
      namefile_output << "{ " << alphabet_result << "} { " << language_result << "}" << std::endl;
      break;
    case 2:
      language_result = languages_file1 | languages_file2;
      alphabet_result = language_result.GetAlphabet();
      namefile_output << "{ " << alphabet_result << "} { " << language_result << "}" << std::endl;
      break;
    case 3:
      language_result = languages_file1 ^ languages_file2;
      alphabet_result = language_result.GetAlphabet();
      namefile_output << "{ " << alphabet_result << "} { " << language_result << "}" << std::endl;
      break;
    case 4:
      language_result = languages_file1 - languages_file2;
      alphabet_result = language_result.GetAlphabet();
      namefile_output << "{ " << alphabet_result << "} { " << language_result << "}" << std::endl;
      break;
    case 5:
      language_result = ! languages_file1;
      alphabet_result = languages_file1.GetAlphabet();
      namefile_output << "{ " << alphabet_result << "} { " << language_result << "}" << std::endl;
      break;
    case 6:
      language_result = languages_file1 * n;
      alphabet_result = languages_file1.GetAlphabet();
      namefile_output << "{ " << alphabet_result << "} { " << language_result << "}" << std::endl;
      break;
    default:
      std::cout << "Error en el opcode, consulte con --help" << std::endl;
      exit(EXIT_FAILURE);
      break;
    }
  }
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