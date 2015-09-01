#include "ex01_14.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "123";
    OrderCollection<string> c1(10, str);
    OrderCollection<double> c2; // 空Order
    c1.print();
    c1.insert(2, "wang");
    c1.print();
    cout << c1.findMax() << endl;
    cout << c2.findMin() << endl;
    return 0;
}
