#include <iostream>
#include <vector>

template <typename T>
void MergeSort(std::vector<T> &seq, int ini, int fin);

template <typename T>
void Merge(std::vector<T> &seq, int ini, int center, int fin);

int main()
{
  std::vector<int> seq = {12, 56, 6, 7, 100, 45, 12, 5, 88};
  MergeSort(seq, 0, seq.size() - 1);

  for(auto i : seq)
    std::cout << i << " ";
  std::cout << std::endl;
  
  return 0;
}

template <typename T>
void MergeSort(std::vector<T> &seq, int ini, int fin)
{
  if (ini < fin)
  {
    int center = (ini + fin) / 2;
    MergeSort(seq, ini, center);
    MergeSort(seq, center + 1, fin);
    Merge(seq, ini, center, fin);
  }
}

template <typename T>
void Merge(std::vector<T> &seq, int ini, int center, int fin) {
  int i = ini;
  int j = center + 1;
  int k = ini;
  std::vector<T> aux(seq.size());

    while(i <= center && j <= fin) {
      if (seq[i] < seq[j]) {
        aux[k] = seq[i];
        i++; k++; 
      }
      else {
        aux[k] = seq[j];
        j++; k++; 
      }
    }

    if (i > center) {
      while (j <= fin) {
        aux[k] = seq[j];
        j++; k++; 
      }
    }
    else {
      while (i <= center) {
        aux[k] = seq[i];
        i++; k++; 
      }
    }

    for (size_t i = ini; i < fin; i++)
      seq[i] = aux[i];
}