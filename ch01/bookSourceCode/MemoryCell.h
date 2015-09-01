/*
 * 
 * 
 */

#ifndef MEMORYSHELL_H_
#define MEMORYSHELL_H_

#include <vector>
using std::vector;

template <typename Object>
class MemoryCell {
public:
  explicit MemoryCell(const Object &initialValue = Object{})
      : storeValue{ initialValue } {}
  const Object & read() const {
    return storeValue;
  }
  void write(const Object &w) {
    storeValue = w;
  }
  
private:
  Object storeValue;
};

#endif
