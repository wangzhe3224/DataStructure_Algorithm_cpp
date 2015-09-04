#include "StackList.h"

int main() {
    StackList<int> s;
    s.push(1);
    s.show();
    std::cout << s.stackTop() << std::endl;
    s.pop();
    s.show();
    return 0;
}
