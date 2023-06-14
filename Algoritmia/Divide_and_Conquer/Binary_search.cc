#include <iostream>

// Algoritmo de busqueda binaria>
int BinarySearch(int *seq, int ini, int fin, int x)
{
  if (ini > fin)
    return -1;
  int center = (ini + fin) / 2;
  if (seq[center] == x)
    return center;
  else if (seq[center] > x)
    return BinarySearch(seq, ini, center - 1, x);
  else
    return BinarySearch(seq, center + 1, fin, x);
}

int main()
{
  int seq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x = 5;
  int pos = BinarySearch(seq, 0, 8, x);

  if (pos != -1)
    std::cout << "The element " << x << " is in the position: " << pos << std::endl;
  else
    std::cout << "The element " << x << " is not in the sequence" << std::endl;
  return 0;
}