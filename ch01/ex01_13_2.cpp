#include "ex01_13_2.h"
#include <iostream>
using namespace std;
int main() {
    double i = 1.0;
    Collection<double> c1(10,i);
    Collection<double> c2 = c1; // test operator =
    cout << c1[0] << endl; // test operator []
    c1.insert(2, 22.0);
    c1.print();
    double j = 22.0;
    if ( c1.contains(j) )
	std::cout << "contains " << j << std::endl;
    std::cout << c1.getSize() << std::endl;
    c1.remove( c1.getSize());
    c1.remove( c1.getSize() - 1 );
    std::cout << c1.getSize() << std::endl;
    c1.print();
    c1.makeEmpty();
    std::cout << c1.getSize() << std::endl;
    
    return 0;
}
