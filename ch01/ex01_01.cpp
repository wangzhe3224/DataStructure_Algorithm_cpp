#include <vector>
#include <iostream>
#include <time.h>

template<typename object>
bool seletion(const std::vector<object> &v, const object k)
{
  for (auto i = 0; i < v.size(); ++i) {
    if (v[i] == k) {
      std::cout << "Find it at index " << i << "\n";
      return true;
    }
  }
  std::cout << "Cant find it.\n";
  return false;
}


int main() {
  clock_t start, finish;
  double totaltime;

  double N = 10000000000;
  double k = N/2;
  std::vector<double> vint(N);
  for (int i = 0; i < vint.size(); ++i) {
    vint[i] = i;
  }
  start = clock();
  //Put the exercise code here
  seletion(vint, k);
  //*************************//
  finish = clock();
  totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
  std::cout << "\nRunning time: " << totaltime << "s.\n";
  return 0;
}
