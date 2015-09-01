#ifndef EX01_03_H_
#define EX01_03_H_

#include <vector>
#include <memory>

using namespace std;

template <typename Object>
class Collection
{
 public:
    // constructor
 Collection() : _data(vector<Object>()), _size(0) {}
 Collection(vector<Object> &v,unsigned size = 0) : _data(v), _size(size) {}
    // method
    bool isempty() const { return _size == 0; }
    void makeEmpty() { _data.clear(); }
    Collection & insert(const Collection &ic) { }
    Collection & remove(Collection &rc);
    bool contains(const Collection &cc);
 private:
    unsigned _size;
    vector<Object> _data;
};
#endif
