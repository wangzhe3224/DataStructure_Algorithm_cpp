template <typename Iterator, typename Object>
Iterator find( Iterator begin, Iterator end, const Object &x)
{
    Iterator iter = begin;
    while ( iter != end && *iter != x ) {
	++iter;
    }

    return iter;
}
