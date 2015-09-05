#include <list>
#include <iostream>

template <typename T>
void printLots( std::list<T> L, std::list<int> P )
{   
    for ( auto pIter = P.cbegin(); pIter != P.cend(); ++pIter ) {

	auto lIter = L.begin();
	int start = 0;
	while ( start < *pIter && lIter != L.cend() ) {
	    ++start;
	    ++lIter;
	}
	if ( lIter != L.cend() ) {
	    std::cout << *lIter << std::endl;
	}
    }
};

int main() {
    std::list<double> P{ 1,2,3,4,5 };
    std::list<int> L{ 4,3,2,1,0 };
    printLots( P, L );
    return 0;
}
