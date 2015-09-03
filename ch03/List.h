#ifndef LIST_H_
#define LIST_H_
#include <algorithm>
#include <iostream>
template <class Object>
class List
{
 private:
    struct Node
    {
	Object data;
	Node *prev;
	Node *next;
	// constructor
	Node( const Object &d = Object{ }, Node *p = nullptr,
	      Node *n = nullptr )
	: data{ d }, prev{ p }, next{ n } { }

	Node ( const Object &&d, Node *p = nullptr,
	       Node *n = nullptr )
	: data{ std::move( d ) }, prev{ p }, next{ n } { }
    }; // double link node
 private:
    int theSize;
    Node *head; // 虚头部节点
    Node *tail; // 虚尾部节点

    void init() // 初始化函数
    {
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
    };
 public:
    class const_iterator
    {
    public:
    const_iterator( )
	: current{ nullptr } { }

	const Object& operator*( ) const
	{ return retrieve(); }

	const_iterator& operator++( )
	    {
		current = current->next;
		return *this;
	    }

	const_iterator operator++( int ) // ? 干啥的？
	{
	    const_iterator old = *this;
	    ++(*this);
	    return old;
	}

	bool operator==( const const_iterator &rhs )
	{ return current == rhs.current; }

	bool operator!=( const const_iterator &rhs )
	{ return !(*this == rhs); }

    protected:
	// 错误检查
	const List<Object> *theList;
	Node *current;

    const_iterator( const List<Object> &lst, Node *p)
	: theList{ &lst }, current{ p } {}

	void assertIsValid( ) const
	{
	    if ( theList == nullptr || current == nullptr || current == theList->head )
		//throw IteratorOutOfBoundsException{ };
            std::cout << "Error!\n";
	}

	Object& retrieve( ) const
	    { return current->data; }
    const_iterator( Node *p )
	: current( p ) {}

	friend class List<Object>;
    };

    class iterator : public const_iterator
    {
    public:
	iterator( ) {}
	Object& operator*( )
	    { return const_iterator::retrieve( ); }
	const Object& operator*( ) const
	{ return const_iterator::operator*(); }

	iterator& operator++( )
	    {
		this->current = this->current->next;
		return *this;
	    }

	iterator& operator++( int )
	    {
		iterator old = *this;
		++( *this );
		return old;
	    }

    protected:
    iterator( Node *p ) : const_iterator{ p }
	{}

	friend class List<Object>;
    };

 public:
    // Constructor
    List( ) { init(); }
    List( const List &rhs )
	{
	    init();
	    for ( auto &x : rhs)
		push_back;
	}
    // move constructor
 List( List &&rhs )
     : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
    }
    // Destructor
    ~List( )
	{
	    clear();
	    delete head;
	    delete tail;
	}

    List& operator= ( const List &rhs )
	{
	    List copy = rhs;
	    std::swap( *this, copy );
	    return *this;
	}

    List& operator= ( List &&rhs )
	{
	    std::swap( theSize, rhs.theSize );
	    std::swap( head, rhs.head );
	    std::swap( tail, rhs.tail );

	    return *this;
	}

    // iterator method
    iterator begin()
    { return { head->next }; }
    const_iterator begin() const
    { return { head->next }; } // ? why {} in the return statement
    iterator end()
    { return { tail }; }
    const_iterator end() const
    { return { tail }; }

    // List method
    int size() const
    { return theSize; }
    bool isempty() const
    { return size() == 0; }
    void printList()
    {
        for (auto i : *this)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    void clear()
    {
	while( !isempty() )
	    pop_front();
    }

    Object & front()
    { return *begin(); }

    const Object & fornt()
    { return *begin(); }

    Object & back()
    { return *--end(); }

    const Object & back() const
    { return *--end(); }

    void push_front( const Object &x )
    { insert( begin(), x); }

    void push_front( const Object &&x )
    { insert( begin(), std::move( x ) ); }

    void push_back( const Object &x )
    { insert ( end(), x ); }

    void pop_front( )
    { erase( begin( ) ); }

    void pop_back( )
    { erase( --end() ); }

    iterator insert( iterator itr, const Object &x )
    {
	// insert x before itr
	Node *p = itr.current;
	theSize++;

	Node *newNode = new Node{ x, p->prev, p };
	// newNode = Node{ x, p->prev, p };
	// 直接在new中初始化，上一行的写法有问题，也不能进行取地址，因为Node{} 是一个临时变量
	// 新节点的前为元节点的前节点，后节点为元节点
	// 链接新节点
	p->prev->next = newNode;
	p->prev = newNode;

	return { p->prev }; // 返回指向新节点的iterator
    }

    iterator insert( iterator itr, Object &&x )
    {
		// insert x before itr
	Node *p = itr.current;
	theSize++;

	Node *newNode = new Node;
	newNode = Node{ std::move( x ), p->prev, p };
	// 新节点的前为元节点的前节点，后节点为元节点
	// 链接新节点
	p->prep->next = newNode;
	p->prep = newNode;

	return { p->prep }; // 返回指向新节点的iterator
    }

    iterator erase( iterator itr )
    {
	Node *p = itr.current;
	iterator returnValue{ p->next };

	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	theSize--;

	return returnValue;
    }

    iterator erase( iterator from, iterator end )
    {
	for ( auto itr = from; itr != end;  )
	    itr = erase( itr );

	return end;
    }
};

#endif
