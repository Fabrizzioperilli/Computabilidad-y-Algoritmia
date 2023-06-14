#include <iostream>
#include <vector>
#include <chrono>

unsigned long long binomialCoefficient(int n, int k) {
    std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= std::min(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1; // Casos base: C(i, 0) = C(i, i) = 1
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // Recurrencia: C(n, k) = C(n-1, k-1) + C(n-1, k)
            }
        }
    }

    return dp[n][k];
}

long BinomialRecursity(int n, int k) {
  if (k == 0 || n == k)
    return 1;
  else 
    return BinomialRecursity(n-1, k-1) + BinomialRecursity(n-1, k);
}

int main() {
    int n = 10000;
    int k = 2;
    std::cout << "Programción dinamica" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "El coeficiente binomial C(" << n << ", " << k << ") es: " << binomialCoefficient(n, k) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " ms" << std::endl;
  
    std::cout << "\nRecursividad" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    std::cout << "El coeficiente binomial C(" << n << ", " << k << ") es: " << BinomialRecursity(n, k) << std::endl;
    auto end2 = std::chrono::high_resolution_clock::now();
    
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "Time taken by function: " << duration2.count() << " ms" << std::endl;
    return 0;
}
