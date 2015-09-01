#ifndef EX01_15_H_
#define EX01_15_H_

#include <iostream>
#include <vector>
using namespace std;

class Rectangle;

template <typename Object, typename Comparator>
    const Object & findMax( const vector<Object> & arr, Comparator cmp )
{
    int maxIndex = 0;
    for( int i = 1; i < arr.size( ); ++i )
	if( cmp.isLessThan( arr[ maxIndex ], arr[ i ] ) )
	    maxIndex = i;
    return arr[ maxIndex ];
}

class Rectangle
{
 public:
 Rectangle(): _length(1), _width(1) {}
 Rectangle(double l, double w = 1.0) : _length(l), _width(w) {}
    double getLength() const { return _length; }
    double getWidth() const { return _width; }
    double getArea() const { return _length*_width; }
    double getPerimet() const { return 2*(_length + _width); }
    void setLW(double l, double w) { _length = l; _width = w; }
    void print() const {
	std::cout << "Length: " << _length
	     << ", width: " << _width << std::endl;
    }
 private:
    double _length;
    double _width;
};

// 这里定义了函数对象的类，
class areaCom {
 public:
    bool isLessThan(const Rectangle& lhs, const Rectangle& rhs) const
    {
	return lhs.getArea() < rhs.getArea();
    }
};

class perimetCom {
 public:
    bool isLessThan(const Rectangle& lhs, const Rectangle& rhs) const
    {
	return (lhs.getPerimet() < rhs.getPerimet()) ? true : false;
    }
};

#endif
