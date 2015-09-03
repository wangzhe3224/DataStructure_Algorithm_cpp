#include "List.h"
#include <iostream>
int main()
{
    List<int> l1;
    for (int i = 0; i < 10; ++i )
        l1.push_back(i);
    l1.printList();
    List<int>::iterator it;
    for (auto i = l1.begin(); i != l1.end(); ++i) {

        if ( *i == 5 )
            l1.erase(i);
    }
    l1.printList();
    return 0;
}
