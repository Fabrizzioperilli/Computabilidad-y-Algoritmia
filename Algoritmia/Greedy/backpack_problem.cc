#include <iostream>
#include <vector>

// Considérese el Problema de la mochila, en el que se dispone de n objetos, cada
// uno de los cuales tiene un peso wi y un valor vi, para i = 1, 2, . . . , n. Se dispone
// de una mochila con capacidad para un peso máximo W. El problema consiste en
// seleccionar los objetos que se incluirán en la mochila de forma que se maximice
// el valor de los objetos incluidos sin exceder el peso máximo de la mochila.
// Abórdese este problema mediante un enfoque voraz (Greedy).
// (a) Diséñese un algoritmo voraz para resolver este problema.
// (b) Escriba el orden de complejidad de temporal.

// a) Algoritmo voraz
std::vector<float> Backpack(float weight, std::vector<float> &p, std::vector<float> &v)
{
  float n = p.size();
  std::vector<float> x(n, 0); // Vector para almacenar los elementos seleccionados
  float currentWeight = 0;    // Peso actual en la mochila

  while (currentWeight < weight)
  {
    float bestIndex = -1;
    double bestValue = 0.0;

    // Seleccionar el mejor objeto restante
    for (float i = 0; i < n; i++)
    {
      if (x[i] == 0)
      {
        double value = static_cast<double>(v[i]) / p[i];
        if (value > bestValue)
        {
          bestValue = value;
          bestIndex = i;
        }
      }
    }

    if (bestIndex == -1)
    {
      break; // No quedan objetos por seleccionar
    }

    // Verificar si el objeto cabe en la mochila
    if (currentWeight + p[bestIndex] <= weight)
    {
      x[bestIndex] = 1;
      currentWeight += p[bestIndex];
    }
    else
    {
      x[bestIndex] = (weight - currentWeight) / p[bestIndex];
      currentWeight = weight;
    }
  }

  return x;
}
// b) Orden de complejidad temporal:  O(n^2)

int main()
{
  std::vector<float> w = {10, 20, 30, 40, 50};
  std::vector<float> v = {20, 30, 66, 40, 60};
  const float weight = 100;
  std::vector<float> result = Backpack(weight, w, v);
  
  std::cout << "Peso de la mochila: " << weight << std::endl;
  std::cout << "\nElementos disponibles: " << std::endl;
    
    for (int i = 0; i < w.size(); i++)
      std::cout << "Peso: " << w[i] << " Valor: " << v[i] << std::endl;

  std::cout << "\nElementos seleccionados: " << std::endl;

  for (int i = 0; i < result.size(); i++)
    if (result[i] > 0.0)
      std::cout << "Peso: " << w[i] << " Valor: " << v[i] << std::endl;

  for (auto i : result)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
