#include <iostream>
#include <string>
using namespace std;

void permute( const string &str );
void permute( const string &str, int low, int high );

void permute( const string &str, int low, int high)
{
  string newstring = str;
  if ( low == high ) {
    for (int i = 0; i <= high; ++i)
      cout << newstring[i];
    cout << endl;
  }
  else {
    for (int i=low; i<high; ++i) {
      string tmp = newstring;
      swap( newstring[i], newstring[low] );
      permute( newstring, low + 1, high );
      swap( newstring[i], newstring[low] );
    }
  }
}

void permute( const string &str ) {
  int low = 0;
  int high = str.size();
  permute(str, low, high);
}

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;
  permute(str);
  return 0;
}
