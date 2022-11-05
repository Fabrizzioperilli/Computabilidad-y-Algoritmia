# Universidad de la Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 4: Expresiones Regulares
# Autor: Fabrizzio Daniell Perilli Martin
# Correo: alu0101138589@ull.edu.es
# Fecha: 08/10/2022
# Archivo: MakeFile
#             ...
# Referencias:
# Historial de revisiones:
# Fecha: 02/11/2022 - Versión: 1.0 - Descripción: Creación del código.

FILES= *.cc
CXXFLAGS= -Wall -std=c++17 -ggdb
ARG_FA = *.fa
ARG_TXT = *.txt
FA_FILE = $(shell ls $(ARG_FA) | sort | head -n 1)
TXT_FILE = $(shell ls $(ARG_TXT) | sort | head -n 1)

all:
	g++ $(CXXFLAGS) $(FILES) -o p06_automata_simulator

clean:
	rm -rf p06_automata_simulator 
	rm -rf *.o

run:
	./p06_automata_simulator $(FA_FILE) $(TXT_FILE)