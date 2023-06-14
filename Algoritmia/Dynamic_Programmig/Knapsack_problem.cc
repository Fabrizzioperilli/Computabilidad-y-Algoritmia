#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int mochila(int P, const vector<int>& p, const vector<int>& v) {
    int n = p.size();
    vector<vector<int>> V(n, vector<int>(P + 1, 0));
    vector<vector<int>> x(n, vector<int>(P + 1, 0));

    for (int j = 0; j <= P; j++)
        V[0][j] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= P; j++) {
            if (j < p[i] || V[i - 1][j - p[i]] + v[i] < V[i - 1][j]) {
                x[i][j] = 0;
                V[i][j] = V[i - 1][j];
            } else {
                x[i][j] = 1;
                V[i][j] = V[i - 1][j - p[i]] + v[i];
            }
        }
    }

    return V[n - 1][P];
}

vector<int> solucion_mochila(int P, const vector<int>& p, const vector<vector<int>>& x) {
    int n = p.size();
    int j = P;
    vector<int> S;

    for (int i = n - 1; i >= 1; i--) {
        if (x[i][j] == 0) {  // Corregir la condición
            S.push_back(i);
            j -= p[i];
            if (j == 0)
                break;
        }
    }

    return S;
}

int main() {
    int P = 11;  // Capacidad de la mochila
    vector<int> p = {1, 2, 5, 6, 7};  // Pesos de los objetos
    vector<int> v = {1, 6, 18, 22, 28};  // Valores de los objetos

    vector<vector<int>> x(p.size(), vector<int>(P + 1, 0));
    int max_valor = mochila(P, p, v);
    cout << "Valor máximo obtenido: " << max_valor << endl;

    vector<int> solucion = solucion_mochila(P, p, x);

    cout << "Objetos seleccionados: ";
    for (int i : solucion) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

