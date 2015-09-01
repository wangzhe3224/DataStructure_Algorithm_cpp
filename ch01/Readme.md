<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

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

a: [Answer](http://math.stackexchange.com/questions/741600/prove-that-logx-x-for-x-0-x-in-mathbbn)

b: [Answer](https://www.khanacademy.org/math/algebra2/logarithms-tutorial/logarithm_properties/v/proof-a-log-b-log-b-a-log-a-log-b-log-a-b)

## Exercise 1.8
a. 3/4  
b. 4/9  
c. 20/27  
d. ??

## Exercise 1.9
ln2

## Exercise 1.10
It is 1. [See Here](https://answers.yahoo.com/question/index?qid=20080513102215AA8Q8tf)

## Exercise 1.11
## Exercise 1.12

## Exercise 1.13 | [.h](ex01_13_2.h) | [.cpp](ex01_13_2.cpp)
>
Design a class template, Collection , that stores a collection of Object s (in an array), along with the current size of the collection. Provide public functions isEmpty , makeEmpty , insert , remove , and contains . contains(x) returns true if and only if an Object that is equal to x is present in the collection.

- Tips:
  * Use `pass-by reference-to-const` for the member function so we can pass a literal to the function....Let's fly!
  * We use operator `new` and `delete` to manage dynamic memory. We have to free the memory when the object dies. Here we use function `init()` to allocate space and `Free()` to free the space. They are all pricate member functions.
  * `InvalidIndex()` is used to check if a index is valid.
  * When we `makeEmpty()` a Collection, we set `_size` to 0 instead of erasing all the element in the memory.

## Exercise 1.14 | [.h](ex01_14.h) | [.cpp](ex01_14.cpp)
>
Design a class template, OrderedCollection , that stores a collection of Comparables (in an array), along with the current size of the collection. Provide public functions isEmpty , makeEmpty , insert , remove , findMin , and findMax . findMin and findMax return references to the smallest and largest, respectively, Comparable in the collection. Explain what can be done if these operations are performed on an empty collection.

- Tips:
  * In this class template, the Object in the class must support operator< and operatptor=.

## Exercise 1.15 | [.h](ex01_15.h) | [.cpp](ex01_15.cpp)
>
Define a Rectangle class that provides getLength and getWidth . Using the findMax routines in Figure 1.25, write a main that creates an array of Rectangle and finds the largest Rectangle first on the basis of area and then on the basis of perimeter.

- Tips:
  * You can pass a `reference-to-type` to a `reference-to-const type` parameter, but you can not do the opposite way. So if you don't change tha passing varible, use pass by `reference-to-const type` instead of `reference-to type`.
  * A const version object can only invoke const version method (the method with a const at the end of function prototype).
  * Function object is handy.

## Exercise 1.16 | [.h](ex01_16.h) | [.cpp](ex01_16.cpp)
>
For the matrix class, add a resize member function and zero-parameter constructor.


