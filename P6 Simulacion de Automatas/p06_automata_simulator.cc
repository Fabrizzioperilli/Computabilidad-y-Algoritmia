// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de automatas finitos
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 08/11/2022
// Archivo: p06_automata_simulator.cc Programa cliente
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 02/11/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <iostream>
#include <iomanip>
#include "Automata.h"

void Help();
bool CheckExtension(std::string, std::string);
void ReadFile(std::string, std::string);

int main(int argc, char **argv)
{

  const std::string kOptionHelp = "--help";
  const int kNumberParam = 3;

  if (argc == kNumberParam)
  {
    if (CheckExtension(argv[1], argv[2]))
      ReadFile(argv[1], argv[2]);

    else
    {
      std::cout << "Las extensiones de los ficheros no son correctas. Ejecute ./p06_automata_simulator --help para mas informacion" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  else if (argc == 2 && argv[1] == kOptionHelp)
    Help();
  else
  {
    std::cout << "Error en los parametros. Ejecute ./p06_automata_simulator --help para mas informacion" << std::endl;
    exit(EXIT_FAILURE);
  }

  return 0;
}

void Help()
{
  std::cout << "\nModo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl;

  std::cout << "\nEl programa crea un automata a partir de la especificacion dada en el\n"
               "fichero .fa y lee las cadenas del fichero.txt, posteriormente por consola\n"
               "indica las cadenas aceptadas y rechazadas por el automata en cuestion."
            << std::endl;
}

bool CheckExtension(std::string file_fa, std::string file_txt)
{

  file_fa = file_fa.substr(file_fa.find_last_of(".") + 1);
  file_txt = file_txt.substr(file_txt.find_last_of(".") + 1);

  if (file_fa == "fa" && file_txt == "txt")
    return true;
  else
    return false;
}

void ReadFile(std::string file_fa, std::string file_txt)
{
  std::ifstream name_file_fa;
  std::ifstream name_file_txt;

  name_file_fa.open(file_fa);
  name_file_txt.open(file_txt);

  Automata automata(file_fa);
  Alphabet alphabet = automata.GetAlphabet();

  if (name_file_txt.is_open())
  {
    std::string line;
    while (getline(name_file_txt, line))
    {
      Word word(line, alphabet);
      
      if (automata.ReadWord(word))
        std::cout << line << " -- Accepted" << std::endl;
      else
        std::cout << line << " -- Rejected" << std::endl;
    }
  }
  else
  {
    std::cout << "Error al abrir los ficheros" << std::endl;
    exit(EXIT_FAILURE);
  }
}
