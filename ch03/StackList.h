#ifndef STACKLIST_H_
#define STACKLIST_H_
/*
 * Stack using single List 
 */

#include <iostream>
#include <cstdlib>

template <class T>
class StackList {
 private:
    struct Node {
	T &data;
	Node *next;

	//Node( const T &t, Node *n ) : data( t ), next( n ) {}
	Node ( T &t, Node *n) : data( t ), next( n ) {}
    Node() : data(), next(nullptr)  {}
    };

    Node *_top;
    unsigned  _size;
    
 public:
 StackList() : _top( nullptr ), _size( 0 ) {}
    
    ~StackList() {
	Node *ptr = _top;

	while ( _top != nullptr ) {
	    ptr = _top->next;
	    delete _top;
	    _top = ptr;
	}
    }
    

    bool isEmpty() { return _size == 0; }

    void push( T &in ) { // todo 增加一个const版本
	
	if ( _top == nullptr ) {
	    _top = new Node( in, nullptr );
	    ++_size;
	}
	else {
	    _top = new Node( in, _top );
	    ++_size;
	}
    }
    
    void pop() {
	
	if ( isEmpty() ) {
	    std::cout << "Stack is empty, pop failed!\n";
	    //throw 0;
	}
	else {
	    Node *tmp = _top->next;
	    T t = _top->data;
	    delete _top;
	    _top = tmp;
	    --_size;           // 栈计数器减少
	}
    }

    T& stackTop() { return _top->data; }

    unsigned getSize() { return _size; }

    void show() {
	/*
	 * 这里犯了一个错误。。。
	 * 用了_top指针来进行显示，导致最后_top指针被放倒了最后一个元素里
	 * 无法进行pop
	 * gdb error
	 * 
	 * Cannot access memory at address 0x0
	 *
	 * 0x0是空指针的意思。
	 */
	Node *tmp = _top;
	for ( int i = 0; i < _size; ++i ) {
	    std::cout << tmp->data << " ";
	    tmp = tmp->next;
	}
	std::cout << std::endl;
    }
};
#endif
