/*
 * NOT finished yet !!!!
 */
#include <iostream>
#include <string>
using namespace std;

void permute( const string &str );
void permute( const string &str, int low, int high );
inline void myswap(string &i, string &j) {
  string tmp = i;
  i = j;
  j = tmp;
}

void permute( const string &str, int low, int high)
{
  string newstring = str;
  if ( low == high )
    //    cout << ??? << endl;
  else {
    for (int i=low; i<high; ++i) {
      string tmp = newstring
      myswap(  );
      permute( str, high, low + 1 );
      myswap( str[low].c_str(), str[i].c_str());
    }
  }
}

void permute( const string &str ) {
  int low = 0;
  int high = str.size();
  permute(str, low, high);
}

int main() {
  string str = "a";
  permute(str);
  return 0;
}
