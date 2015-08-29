#include "Square.h"
#include "findMax.h"
#include <vector>
#include <iostream>
using std::vector;

int main() {
  vector<Square> v = {Square{3.0}, Square{5.0}, Square{8.9}};

  std::cout << findMax(v) << std::endl;

  return 0;
}
