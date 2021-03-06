#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template <typename Object>
class matrix {
 public:
    matrix() { matrix(0,0); }
 matrix( int rows, int cols ) : array( rows )
    {
	for (auto &thisRow : array)
	    thisRow.resize( cols ); // every row has cols element.
    }
 matrix( vector<vector<Object>> v) : array {v}
    {}
 matrix( vector<vector<Object>> &&v): array { std::move(v) }
    {}

    // operator [] overloading
    const vector<Object> &operator[] (int row) const
    { return array[ row ]; }
    vector<Object> &operator[] (int row)
	{ return array[ row ]; }
    
    int numrows() const
    { return array.size(); }
    int numcols() const
    { return numrows() ? array[0].size() : 0; }

    void resize(int r, int c) {
	array.resize(r);
	for (auto &i : array)
	    i.resize(c);
    }
  
 private:
    vector<vector<Object>> array;
};
#endif
