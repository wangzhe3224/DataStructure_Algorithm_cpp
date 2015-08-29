#include "MemoryCell.h"
#include <iostream>
#include <string>
#include <vector>
using std::string;using std::vector;

int main() {
  MemoryCell<int> m1;
  MemoryCell<string> m2{"wangzhe."};
  MemoryCell<vector<string>> m3;

  m1.write(37);
  m2.write(m2.read() + "!!!");
  m3.write({"what", "is", "this.\n"});

  std::cout << m1.read() << std::endl << m2.read() << std::endl;

  for (auto i : m3.read())
    std::cout << i << " ";

  return 0;
}
