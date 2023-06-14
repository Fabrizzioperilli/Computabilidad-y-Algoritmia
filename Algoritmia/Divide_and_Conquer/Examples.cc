#include <iostream>
#include <cmath>
#include <chrono>

long multiply(int x, int y, short n);
int power(int a, int n);
long karatsuba(int x, int y, short n);
long  RussianPeasantMultiplication(int x, int y);

int main()
{
  int a = 2, n = 10;
  int x = 100, y = 20;
  std::cout << "--Examples Divide and Conquer--" << std::endl;
  std::cout << "Power:" << std::endl;
  std::cout << a << "^" << n << " = " << power(a, n) << std::endl;
  std::cout << "Multiply:" << std::endl;
  std::cout << x << " * " << y << " = " << multiply(x, y, 2) << std::endl;
  std::cout << "Multiply Karatuba Algorithm:" << std::endl;
  std::cout << x << " * " << y << " = " << karatsuba(x, y, 2) << std::endl;
  std::cout << "Russian peasant multiplication:" << std::endl;
  std::cout << x << " * " << y << " = " << RussianPeasantMultiplication(x, y) << std::endl;
  return 0;
}

int power(int a, int n)
{
  if (n == 1)
    return a;
  int temp = power(a, n / 2);
  if (n % 2 == 0)
    return temp * temp;
  else
    return a * temp * temp;
  // O(log(n))
}

long multiply(int x, int y, short n)
{
  if (n == 1)
    return x * y;
  else
  {
    short m = n / 2;
    int temp = std::pow(10, m);
    int temp_2m = std::pow(10, 2 * m);
    int a = x / temp, c = y / temp;
    int b = x % temp, d = y % temp;
    long ac, bd, bc, ad;

    ac = multiply(a, c, m);
    bd = multiply(b, d, m);
    bc = multiply(b, c, m);
    ad = multiply(a, d, m);

    return temp_2m * ac + temp * (bc + ad) + bd;
  }
  // O(n^1/2)
}

long karatsuba(int x, int y, short n)
{
  if (n == 1)
    return x * y;
  else
  {
    short m = n / 2;
    int temp = std::pow(10, m);
    int temp_2m = std::pow(10, 2 * m);
    int a = x / temp, c = y / temp;
    int b = x % temp, d = y % temp;
    long ac, bd;

    ac = karatsuba(a, c, m);
    bd = karatsuba(b, d, m);
    long bc_ad = karatsuba(a - b, c - d, m);

    return temp_2m * ac + temp * (ac + bd - bc_ad) + bd;
  }
  // O(n^1.5849625)
}

long RussianPeasantMultiplication(int x, int y)
{
  if (x == 0)
    return 0;
  long value = RussianPeasantMultiplication(x / 2, y + y);
  return (x % 2 == 0) ? value : value += y;
  
  //Θ(logx⋅logy)
}