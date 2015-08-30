#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../include/matrix.h"

/*
 * Puzzle class
 */
class Puzzle {
 public:
  Puzzle(const matrix<string> &puzzleBox,
         const vector<string> &wordList)
      : _puzzleBox(puzzleBox), _wordList(wordList)
  {
    // lower_bound method meeds to input a sorted container.
    // See http://www.cplusplus.com/reference/algorithm/lower_bound/ for details.
    std::sort (_wordList.begin(), _wordList.end());
  }
  
  int solvePuzzle() const;

 private:
  matrix<string> _puzzleBox;
  vector<string> _wordList;

  int _solveDirection(int baseRow, int baseCol,
                     int rowDel, int colDel) const;

  int _solveDirection2(int baseRow, int baseCol,
                       int rowDel, int colDel) const;
};

// public method
int Puzzle::solvePuzzle() const {
  
  int matches = 0;

  for (int r = 0; r < _puzzleBox.numrows(); ++r)
    for (int c = 0; c < _puzzleBox.numcols(); ++c)
      /*
       * rd and cd are used to control search directions
       * -1 : search backward
       *  1 : search forward
       */
      for (int rd = -1; rd <= 1; ++rd)
        for (int cd = -1; cd <= 1; ++cd)
          if (rd !=0 || cd != 0)
             matches += _solveDirection2(r, c, rd, cd);
            //matches += _solveDirection(r,c,rd,cd);

  return matches;
}

// Private method
int Puzzle::_solveDirection(int baseRow, int baseCol,
                     int rowDel, int colDel) const
{
  string word;
  int numMatches = 0;

  word = _puzzleBox[baseRow][baseCol];

  // search in 8 directions
  for (int i = baseRow + rowDel, j = baseCol + colDel;
       i >=0 && j >= 0 && i < _puzzleBox.numrows() && j < _puzzleBox.numcols();
       i += rowDel, j += colDel)
  {
    word += _puzzleBox[i][j];// creat a word by charactor

    // try to match in the word list
    vector<string>::const_iterator itr;
    itr = lower_bound(_wordList.begin(), _wordList.end(), word);

    if (itr == _wordList.end())
      break;

    if ( *itr == word )
    {
      ++numMatches;
      cout << "Find \"" << word << "\" at "
           << baseRow << " " << baseCol
           << " to " << i << " " << j << endl;
    }
  }

  return numMatches;
}

/*
 * Here is another method to search without using iterator of the "algorithm" library.
 */
int Puzzle::_solveDirection2(int baseRow, int baseCol,
                     int rowDel, int colDel) const
{
  string word;
  int numMatches = 0;
  string tmp;

  word = _puzzleBox[baseRow][baseCol];
  
  for (int i = baseRow + rowDel, j = baseCol + colDel;
       i >=0 && j >= 0 && i < _puzzleBox.numrows() && j < _puzzleBox.numcols();
       i += rowDel, j += colDel)
  {
    word += _puzzleBox[i][j];

    for (auto singleword : _wordList) {
      tmp = "";
      if ( word == singleword ) {
        ++numMatches;
        cout << "Find \"" << word << "\" at "
             << baseRow << " " << baseCol
             << " to " << i << " " << j << endl;
        break;
      }
      else {

        for (decltype(word.size()) t = 0; t < word.size(); ++t) {
          tmp += singleword[t];
        }
        
        if ( word == tmp) {
          break;
        }
        else
          continue;
      }
    }
  }
  
  return numMatches;
}

    

int main() {
  vector<vector<string>> oriInput
  {
    {"t","h","i", "s"},
    {"w", "a", "t", "s"},
    {"o", "a", "h", "g"},
    {"f", "g", "d", "t"}
  };
  
  matrix<string> puzzleBox(oriInput);
  vector<string> wordList{"this", "two", "fat", "that"};

  Puzzle p(puzzleBox, wordList);
  cout << "Found " << p.solvePuzzle( ) << " matches" << endl;
  
  return 0;
}

// Output:
// Find "this" at 0 0 to 0 3
// Find "two" at 0 0 to 2 0
// Find "fat" at 3 0 to 1 2
// Find "that" at 3 3 to 0 0
// Found 4 matches

