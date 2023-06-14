#include <iostream>
#include <vector>
#include <climits>

std::vector<std::vector<int>> calcularMatrizMonedas(int n)
{
  std::vector<int> v = {1, 3, 4};
  int m = v.size();
  std::vector<std::vector<int>> C(m, std::vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++)
  {
    C[i][0] = 0;
    for (int j = 1; j <= n; j++)
    {
      if (i == 0 && j < v[0])
        C[i][j] = INT_MAX; // Infinito
      else if (i == 0)
        C[i][j] = 1 + C[i][j - v[0]];
      else if (j < v[i])
        C[i][j] = C[i - 1][j];
      else
        C[i][j] = std::min(C[i - 1][j], 1 + C[i][j - v[i]]);
    }
  }

  return C;
}

std::vector<int> obtenerCambioMonedas(int m, int n, const std::vector<std::vector<int>> &C)
{
  std::vector<int> cambio(m, 0);
  std::vector<int> v = {1, 3, 4};
  int i = m - 1, j = n;

  while (j > 0)
  {
    if (i > 0 && C[i][j] == C[i - 1][j])
      i--;
    else
    {
      cambio[i]++;
      j -= v[i];
    }
  }

  return cambio;
}

// Algoritmo voraz
std::vector<int> Currency_exchange(int C)
{
  std::vector<int> di = {1, 3, 4};
  std::vector<int> result(3, 0); // Inicializar el vector de resultados con ceros

  int sum = 0;

  while (sum != C)
  {
    for (int i = di.size() - 1; i >= 0 ; i--)
    {
      if (sum + di[i] <= C)
      {
        result[i]++; // Incrementar la cantidad en la posición del valor equivalente
        sum += di[i];
        break;
      }
    }
  }

  return result;
}

int main()
{
  int cantidad = 6; // Cantidad para obtener el cambio
  std::vector<std::vector<int>> matrizMonedas = calcularMatrizMonedas(cantidad);
  std::vector<int> cambioMonedas = obtenerCambioMonedas(matrizMonedas.size(), cantidad, matrizMonedas);
  std::vector<int> M = {1, 3, 4};

  std::vector<int> vector_greedy = Currency_exchange(cantidad);
  std::cout << "Cantiada a cambiar = " << cantidad << std::endl;
    
    std::cout << "Tipos de monedas = { ";
    for (auto i : M) 
      std::cout << i << " ";
    std::cout << "}" << std::endl;

  std::cout << "Cambio de monedas (Programción dinámica): ";
  for (int i = 0; i < cambioMonedas.size(); i++)
    std::cout << cambioMonedas[i] << " ";
  std::cout << std::endl;

  std::cout << "Cambio de monedas (Greddy): ";
  for (int i = 0; i < vector_greedy.size(); i++)
    std::cout << vector_greedy[i] << " ";
  std::cout << std::endl;

  return 0;
}