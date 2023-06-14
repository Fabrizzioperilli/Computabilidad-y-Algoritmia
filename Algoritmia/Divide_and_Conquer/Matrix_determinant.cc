#include <iostream>
#include <vector>

class Matriz {
private:
  std::vector<std::vector<int>> matriz;

public:
  Matriz(std::vector<std::vector<int>> values) : matriz(values) {}

  int getDeterminant() {
    return calcularDeterminante(matriz);
  }

private:
  int calcularDeterminante(const std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    if (n == 1) {
      return mat[0][0];
    } else {
      int det = 0;
      for (int j = 0; j < n; j++) {
        std::vector<std::vector<int>> submatriz = generarSubmatriz(mat, 0, j);
        int subdet = calcularDeterminante(submatriz);
        det += mat[0][j] * ((j % 2 == 0) ? 1 : -1) * subdet;
      }
      return det;
    }
  }

  static std::vector<std::vector<int>> generarSubmatriz(const std::vector<std::vector<int>>& mat, int fila, int columna) {
    int n = mat.size();
    std::vector<std::vector<int>> submatriz(n - 1, std::vector<int>(n - 1));

    int r = 0;
    for (int i = 0; i < n; i++) {
      if (i != fila) {
        int c = 0;
        for (int j = 0; j < n; j++) {
          if (j != columna) {
            submatriz[r][c++] = mat[i][j];
          }
        }
        r++;
      }
    }

    return submatriz;
  }
};

int main() {
  std::vector<std::vector<int>> values = {{1, 2}, {3, 4}};

  Matriz matriz(values);
  int determinante = matriz.getDeterminant();

  std::cout << "El determinante de la matriz es: " << determinante << std::endl;

  return 0;
}
