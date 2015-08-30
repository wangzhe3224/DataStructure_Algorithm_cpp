#include <iostream>
using namespace std:
int ex5(int N) {
  if ( N > 1 ) {
    return ex5( N/2 ) + ( N%2==0 ? 0 : 1);
  }
  return N;
}

int main() {
  int N = 2012;
  cout << ex5(N) << endl;
  return 0;
}
