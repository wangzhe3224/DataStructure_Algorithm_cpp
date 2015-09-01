#include "ex01_16.h"
#include <iostream>
using namespace std;
int main() {
    matrix<int> m1;
    cout << m1.numrows() << endl;
    m1.resize(10,10);
    cout << m1.numrows() << endl;
    return 0;
}
