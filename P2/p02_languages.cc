// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo p02_languages.cc: programa cliente.
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
#include "Language.h"

typedef std::vector<std::vector<std::string>> vector_alph_lg;

void Help();
void Read(char *, char *, char *, int);

vector_alph_lg Split(std::string);
int Divide(std::string);

int main(int argc, char **argv)
{
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 5;

  if (argc == kNumberParam)
  {
    int opcode = atoi(argv[4]);
    std::cout << "Ejecucion correcta. " << std::endl;
    std::cout << "Compruebe la salida en el fichero: " << argv[3] << std::endl;
    Read(argv[1], argv[2], argv[3], opcode);
  }
  else if ((argc == 2) && (argv[1] == kOptionHelp))
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
  return 0;
}

void Help()
{
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
  

  while (!namefile1.eof() && !namefile2.eof())
  {
    getline(namefile1, string_line_file1);
    getline(namefile2, string_line_file2);

    vector_aux_file1 = Split(string_line_file1);
    vector_aux_file2 = Split(string_line_file2);
    
    vector_symbols_file1 = vector_aux_file1[0];
    vector_words_file1 = vector_aux_file1[1];

    vector_symbols_file2 = vector_aux_file2[0];
    vector_words_file2 = vector_aux_file2[1];

    Alphabet alphabet;

    for (size_t i = 0; i < vector_symbols_file1.size(); i++) 
      alphabet.AddSymbol(vector_symbols_file1[i]);

    
    Language language;
    for (size_t i = 0; i < vector_words_file1.size(); i++) {
      Word word(vector_words_file1[i], alphabet);
      language.AddWord(word);
    }

    // namefile_output << "{" << alphabet << "}" << std::endl;
    namefile_output << "{ " << language << "}"<<std::endl;
    
    
   
  }
}

// La funcion Split recorta el string a partir de un delimitador
vector_alph_lg Split(std::string str) {
  vector_alph_lg vector;
  std::vector<std::string> vector_alphabet;
  std::vector<std::string> vector_language;
  std::string aux_alpha;
  std::string aux_lenguage;
  int half = Divide(str);
  
  for (int i = 0; i < half; i++)
  {
    if (str[i] != ' ' && str[i] != '{' && str[i] != '}')
      aux_alpha += str[i];
    else if (aux_alpha != "")
    {
      vector_alphabet.push_back(aux_alpha);
      aux_alpha = "";
    }
  }

  for (size_t i = half; i < str.length(); i++)
  {
    if (str[i] != ' ' && str[i] != '{' && str[i] != '}')
      aux_lenguage += str[i];
    else if (aux_lenguage != "")
    {
      vector_language.push_back(aux_lenguage);
      aux_lenguage = "";
    }
  }
  vector.push_back(vector_alphabet);
  vector.push_back(vector_language);

  return vector;
}


int Divide(std::string str)
{
  int pos;
  for (size_t i = 0; i < str.length(); i++)
    if (str[i] == ' ' && str[i - 1] == '}' && str[i + 1] == '{')
      pos = i;
  return pos;
}
// std::vector<std::string> Split(std::string str)
// {
//   std::vector<std::string> result;
//   std::string aux;
//   for (size_t i = 0; i < str.size(); i++)
//   {
//     if (str[i] != ' ' && str[i] != '{')
//       if (str[i] != '}')
//         aux += str[i];
//       else
//         break;
//       else if (aux != "")
//       {
//         result.push_back(aux);
//         aux = "";
//       }
//   }
//   return result;
// }