#include <iostream>
#include <vector>
// Considérese el Problema de devolución de cambio, en el que debe devolver
// exactamente una cantidad C, y para ello se dispone de n tipos de moneda, cada
// uno de los cuales tiene un valor di, para i = 1, 2, . . . , n.
// Abórdese este problema mediante un enfoque voraz (Greedy).
// (a) Diséñese un algoritmo voraz para resolver este problema.
// (b) Escriba el orden de complejidad de temporal.

//a) Algoritmo voraz
std::vector<int> Currency_exchange(int C)
{
  std::vector<int> di = {200, 100, 50, 20, 10, 5, 2, 1};
  std::vector<int> result;
  int sum = 0;
  
  while (sum != C)
  {
    for (int i = 0; i < di.size(); i++)
    {
      if (sum + di[i] <= C)
      {
        result.push_back(di[i]);
        sum += di[i];
        break;
      }
    }
  }
  return result;
}
//b) Orden de complejidad temporal:  O(n)

int main()
{

  std::vector<int> result = Currency_exchange(343);

  for (int i = 0; i < result.size(); i++)
    std::cout << result[i] << " ";
  std::cout << std::endl;

  return 0;
}