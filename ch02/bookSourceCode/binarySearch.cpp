#include <iostream>
#include <vector>

template <class Comparable>
int binarySearch( const std::vector<Comparable> &a, const Comparable &x)
{
    int low = 0, high = a.size() - 1;

    while ( low <= high ) {
	int mid = ( low + high ) / 2;

	if ( a[mid] > x )
	    high = mid - 1;
	else if ( a[mid] < x)
	    low = mid +1;
	else
	    return mid;
    }

    return -1; // Not found
}

int main() {
    std::vector<int> v(10);
    for ( int i = 0; i < v.size(); ++i )
	v[i] = i;

    std::cout << binarySearch(v, 6) << std::endl;
}
