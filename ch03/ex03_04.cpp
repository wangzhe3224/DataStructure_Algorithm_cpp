#include <list>
using std::list;

template <typename Object>
list<Object> addList(list<Object> &l1,
		     list<Object> &l2)
{
    list<Object> tmp;
    auto iterL1 = l1.begin();
    auto iterL2 = l2.begin();

    while ( iterL1 =! l1.end() && iterL2 != l2.end() ) {
	if ( *iterL1 = *iterL2 ) {
	    tmp.push_back( *iterL1 );
	    ++iterL1;
	    ++iterL2;
	}
	
    }

    return tmp;
}


