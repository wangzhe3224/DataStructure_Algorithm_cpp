// Generic findMax() function, with a function object
#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>


using namespace std;

template <typename Object, typename Comparator>
const Object & findMax(const vector<Object> &arr, Comparator isLessThen)
{
  int maxIndex = 0;

  for (int i = 1; i < arr.size(); ++i)
  {
    if (isLessThen(arr[maxIndex], arr[i]))
      maxIndex = i;
  }

  return arr[maxIndex];
}

template <typename Object>
const Object & findMax(const vector<Object> &arr)
{
  return findMax(arr, less<Object> {});// less<> is a template in functional.
  // overloading??
}

class CaseInsensitiveCompare
{
 public:
  bool operator()(const string &lhs, const string &rhs) {
    return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
  }
};

int main( )
{
  vector<string> arr = { "ZEBRA", "alligator", "crocodile" };
  cout << findMax( arr, CaseInsensitiveCompare{ } ) << endl;
  cout << findMax( arr ) << endl;
  return 0;
}
  
