* auto-gen TOC:
{:toc}

# Chapter 01 Programming: A general overview

## Exercise 1.1 | [Code](ex01_01.cpp)
>
Write a program to solve the selection problem. Let k = N/2. Draw a table showing the running time of your program for various values of N.

| N      | Time(s) |
|:------:|:-------:|
|10      |4e-6     |
|100     |9e-6     |
|1000    |1.9e-5   |
|1e5     |0.000163 |
|1e7     |0.004    |
|1e10    |2.7129   |
|1e12    |Aborted  |


## Exercise 1.2 | [Code](ex01_02.cpp)
> Write a program to solve the word puzzle problem.

## Exercise 1.3 | [Code](ex01_03.cpp)
> Write a function to output an arbitrary double number (which might be negative) using only printDigit for I/O.

/*
 * I didn't find a method that only use function `printDigit()`..
 * However,
 * This urgly program works....
 * I divided the integer part and the digital part, and use `printDigit`
 * function to them seperately.....
 */

## Exercise 1.4
> C++ allows statements of the form  
>  `#include filename`  
> which reads filename and inserts its contents in place of the include statement. Include statements may be nested; in other words, the file filename may itself con- tain an include statement, but, obviously, a file can’t include itself in any chain. Write a program that reads in a file and outputs the file as modified by the include statements.

I .... don't understand...What is the point of the exrecise?

I guess:

~~~cpp
#ifndef ABA_H_
#define ABA_H_

#endif
~~~

## Exercise 1.5 | [Code](ex01_05.cpp)
> Write a recursive function that returns the number of 1 in the binary representation of N. Use the fact that this is equal to the number of 1 in the representation of N/2, plus 1, if N is odd.

## Exercise 1.6 | [Code1](ex01_06.cpp), [Code2](ex01_06_2.cpp)
>
Write the routines with the following declarations:
>
~~~cpp
void permute( const string & str );
void permute( const string & str, int low, int high );
~~~
>
The first routine is a driver that calls the second and prints all the permutations of the characters in string str . If str is "abc" , then the strings that are output are abc , acb , bac , bca , cab , and cba . Use recursion for the second routine.

I think the second method is more readable than the first method.

## Exercise 1.7
> Prove the following formulas:
a. logX < X for all X > 0
b. log(AB) = BlogA

a:  

