#include "findMax.h"
#include <iostream>
#include <string>
#include <vector>
using std::vector; using std::string;
int main() {
  vector<int> vint = {1,3,4,5,7,9};
  vector<double> vdouble  = {1.1, 2.3, 23.32};
  vector<string> vstr = {"wang","zhe","!"};

  std::cout << findMax(vint) << std::endl;
  std::cout << findMax(vdouble) << std::endl;
  std::cout << findMax(vstr) << std::endl;
  
  return 0;
}
