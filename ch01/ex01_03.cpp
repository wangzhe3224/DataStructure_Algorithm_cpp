#include <iostream>
#include <cmath>
using namespace std;

/*
 * I didn't find a method that only use function `printDigit()`..
 * However,
 * This urgly program works....
 * I divided the integer part and the digital part, and use `printDigit`
 * function to them seperately.....
 */

int findPointNum(double num) {
  int intPart = (int)num;
  double digitPart = num - intPart;

  int counter = 0;
  int tmp = 0;
  do {
    digitPart *= 10;
    //cout << digitPart << endl;
    tmp = (int)digitPart + 1;
    //cout << tmp << endl;
    ++counter;
  }while ( tmp%10 != 0);

  return counter - 1;
}


void printDigit(int n)
{
  if (abs(n) >= 10)
  {
    printDigit( n/10 );
    cout << abs( n%10 ) << endl;
  }
  else
    cout << n%10 << endl;
}

void printReal(double num)
{
  int intPart, i, dicInt = 0;
  double dicPart;

  intPart = num;
  dicPart = num - intPart;

  printDigit(intPart);

  int pointNum = findPointNum(num);
  
  if (pointNum > 0)
  {
    cout << "." << endl;

    for (i =0; i < pointNum; ++i)
    {
      dicPart *= 10;
    }

    dicInt = abs(dicPart);

    printDigit(dicInt);
  }
}

int main() {
  double num = 2.12221212;
  printReal(num);
}
