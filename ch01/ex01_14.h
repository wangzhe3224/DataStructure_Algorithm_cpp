#ifndef EX01_14_H_
#define EX01_14_H_
#include <memory.h>
#include <iostream>
/*
 * Dynamic OrderCollection class template
 */


template <class Object>
class OrderCollection
{
 public:
    // 构造函数
    OrderCollection() { Init(); }
    OrderCollection(int nSize, const Object &ob);
    OrderCollection(const OrderCollection &co);
    // 运算符重载
    OrderCollection& operator=(const OrderCollection &co);
    Object& operator[](int nIndex);
    // 析构函数
    ~OrderCollection() { Free(); }
    // 共有成员函数
    bool isEmpty() const { return _size == 0; }
    unsigned getSize() const { return _size; }
    bool makeEmpty() { _size = 0; }
    //void insert(int atIndex, Object &ob);
    void insert(int atIndex, const Object &ob); 
    void remove(int atIndex);
    bool contains(const Object &ob) const;

    Object& findMin();
    Object& findMax();

    void print() const {
	for (int i = 0; i < _size; ++i )
	    std::cout << _data[i] << " ";
	std::cout << std::endl;
    }
    
    // 私有变量
 private:
    unsigned _size; // 数组内元素个数
    unsigned _Maxsize; // 预留的动态数组空间最大值
    Object *_data; // 动态内存空间指针
    // 私有成员函数
 private:
    void Init(); // 初始化空间 
    void Free(); // 释放空间
    bool InvalidIndex(int nIndex)
    { return (nIndex >=0 && nIndex < _size) ? true : false; }
        
    void _insert(int atIndex, const Object &ob)
    {
	for ( int i = _size - 1; i >= atIndex; --i ) {
	    _data[i+1] = _data[i]; // 从点开始向后移动数组元素
	}
	
	_data[atIndex] = ob; // 插入
    }
};

// 私有成员函数
template <class Object>
void OrderCollection<Object>::Init()
{
    _size = 0;
    _Maxsize = 1;
    _data = new Object[_Maxsize];
}

template <class Object>
void OrderCollection<Object>::Free()
{
    delete [] _data;
}
// 构造函数
template <class Object>
OrderCollection<Object>::OrderCollection(int nSize, const Object &ob)
{
    if ( nSize == 0 )
	Init();
    else {
	_size = nSize;
	_Maxsize = nSize * 2;
        _data = new Object[_Maxsize];

	for ( int i = 0; i < nSize; ++i)
	    _data[i] = ob;
    }
}

// 拷贝构造
template <class Object>
OrderCollection<Object>::OrderCollection(const OrderCollection &co)
{
    _size = co._size;
    _Maxsize = co._Maxsize;
    _data = new Object[_Maxsize];
    memcpy(_data, co._data, _size*sizeof(Object));
}

// 重载赋值运算符 = 
template <class Object>
OrderCollection<Object>& OrderCollection<Object>::operator=(const OrderCollection<Object> &ob)
{
    if (this == &ob)
	return *this;
    _size = ob._size;
    _Maxsize = ob._Maxsize;
    Object *tmp = new Object[_Maxsize];
    memcpy(tmp, ob._data, _size*sizeof(Object));
    delete [] _data;
    _data = tmp;
    
    return *this;
}

// 重载 []
template <class Object>
Object& OrderCollection<Object>::operator[](int nIndex)
{
    if (nIndex < 0 || nIndex >= _size) {
	std::cout << "Out of range." << std::endl;
	//return void; // doesn't work
	return _data[_size]; // 返回最后一个值
    }

    return _data[nIndex];
}
    

// 成员函数
template <class Object>
void OrderCollection<Object>::insert(int atIndex, const Object &ob)
{
    // 检查插入位置是否合法
    if ( atIndex < 0 || atIndex >= _size) {
	std::cout << "Error index! Insert failed.\n";
	return;
    }

    // 检查现有空间是否已经满
    if ( _size < _Maxsize ) {
	// 不满
	_insert(atIndex, ob);
    }
    else {
	// 现有空间已经满， 开辟新空间
	_Maxsize = 2*_Maxsize;
	Object *tmp = new Object[_Maxsize];
	memcpy(tmp, _data, _size*sizeof(Object));// 将数据放入临时空间
	delete [] _data; // 释放原有空间
	_data = tmp;

	_insert(atIndex, ob);
    }

    ++_size; // 增加数组大小值
}


template <class Object>
void OrderCollection<Object>::remove(int atIndex)// pop_back().?
{
    if ( InvalidIndex(atIndex) ) {
	// 下标有效
	// 移除点后所有数据向前移动
	if ( atIndex == _size ) {
	    // if remove the last element
	    //_data[atIndex] = 0;
	    --_size;
	}
	else { // 移除中间元素
	for ( int i = atIndex; i < _size; ++i)
	    _data[i] = _data[i+1];
	--_size;
	}
    }
    else {
	std::cout << "Out of range! Nothing removed" << std::endl;
	return;
    }
}

template <class Object>
bool OrderCollection<Object>::contains(const Object &ob) const
{
    int flag = 0;
    for ( int i = 0; i < _size; ++i ) {
	if ( _data[i] == ob)
	    ++flag;
    }

    if ( flag == 1 )
	return true;
    else
	return false;
}

template <class Object>
Object& OrderCollection<Object>::findMin()
{
    Object tmp;
    int Min = 0;
    for (int i = 0; i < _size; ++i) {
	if ( tmp < _data[i] ) {
	    tmp = _data[i];
	    Min = i;
	}
    }

    return _data[Min];
    // 不能直接返回tmp， 因为tmp是以个局部变量，如果返回了局部变量的引用，
    // 函数执行结束后，引用就已经失效(ง •̀_•́)ง
    // 会报错
}


template <class Object>
Object& OrderCollection<Object>::findMax()
{
    //Object tmp;
    int max = 0;
    for (int i = 0; i < _size; ++i) {
	if ( _data[max] > _data[i] ) {
	    max = i;
	}
    }
    return _data[max];
}

#endif
