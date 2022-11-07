/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 6: Simulacion de Automatas Finitos
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 18/10/2022
* @file Archivo: State.h
*        Clase State
* Referencias:
* @version Historial de revisiones:12/10/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#pragma once 
#include <set>

class Transition;
class State {
  private:
    int id_;
    std::set<Transition> transitions_;  
  
  public:
    State();
    ~State();
    State(int);
  
    int GetId() const;
    void SetId(int);
    std::set<Transition> GetTransitions() const;
    void SetTransitions(std::set<Transition>);
    void AddTransition(Transition&);

    bool operator<(const State&) const;
    State& operator=(const State&);
    bool operator==(const State&) const;
};