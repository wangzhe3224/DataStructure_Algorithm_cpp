#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sys/timeb.h>

class randomPermutation {
public:
    // Constructor
    randomPermutation() : _data(), _N(0) {}
    randomPermutation(int n) : _N(n) { _data.resize(_N); }
    // method
    void a_Permutation();
    void b_Permutation();
    void c_Permutation();

    void printRandom(int i, int j) { std::cout << rangInt(i,j) << std::endl; }
    void printData() {
	for (auto i : _data)
	    std::cout << i << " ";
	std::cout << std::endl;
    }
private:
    int _N;
    std::vector<int> _data;
    
    int rangInt( int i, int j ); // random integer generator
};

int randomPermutation::rangInt( int i, int j ) {      
    return rand()%j + i;
}

void randomPermutation::a_Permutation() {

    for (int i = 0; i < _N; ++i) {

	while ( true ) {
	    int flag = 0;
	    int rand = rangInt(1,_N);
	    for ( int j = 0; j < i; ++j ) {
		if ( rand == _data[j] ) {
		    flag = 1;
		    break;
		}
	    }
	    
	    if ( flag == 0 ) {
		_data[i] = rand;
		break;
	    }
	}
    }
}

void randomPermutation::b_Permutation() {

    // hold the flag vector
    std::vector<bool> used(_N, false);

    for (int i = 0; i < _N; ++i) {
	while (true) {
	    int rand = rangInt(1, _N);
	    if ( !used[rand] ) {
		_data[i] = rand;
		used[rand] = true;
		break;
	    }
	}
    }
}

void randomPermutation::c_Permutation() {
    for (int i = 0; i < _N; ++i) {
	_data[i] = i + 1;
    }

    for (int i = 1; i < _N; ++i) {
	std::swap( _data[i], _data[rangInt(0,i)] );
    }
}

using namespace std;
int main() {
    struct timeb startTime , endTime;

    
    srand((unsigned)time(NULL));
    int N = 10;
    randomPermutation p1(N);
    randomPermutation p2(N);
    ftime(&startTime);
    
    p2.c_Permutation();

    ftime(&endTime);
    cout << "a_Permu uses: " << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << " ms" << endl;

    p2.printData();
    return 0;
}
