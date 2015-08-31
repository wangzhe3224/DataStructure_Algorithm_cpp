#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Permutation
{
 public:
  Permutation(string &str) : _str(str) {}
  Permutation() : _str("") {}
  void getString();
  void showPermutation();
 private:
  string _str;
  void showPermutation(string &s, int length, string &buff,
                       vector<bool> mark, int position);
};

void Permutation::getString() {
  cout << "Please enter a string: ";
  cin >> _str;
}

void Permutation::showPermutation(string &s, int length, string &buff,
                     vector<bool> mark, int position)
{
  // Here is the base case, when the fixed character is the last one in the string... function is finished.
  if (position == length) {
    cout << buff << endl;
    return;
  }
  else {
    for (int i = 0; i <length; ++i) {
      if (mark[i])
        continue;

      buff += s[i];
      mark[i] = true; // the character is in use.

      // fixes a character, then get the permutation of the left characters
      showPermutation(s, length, buff, mark, position + 1);

      // remove the mark, erase the last the charactor, preparing for the new for loop......
      buff.erase( position ); 
      mark[i] = false;
    }
  }
}

void Permutation::showPermutation() {
  int length = _str.size();
  string buff;
  vector<bool> mark(length);
  for (auto i : mark)
    i = false;
  int position = 0;

  showPermutation(_str, length, buff, mark, 0);
}


int main() {
  Permutation p;
  p.getString();
  p.showPermutation();
  return 0;
}
