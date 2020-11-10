#include <stdio.h>
/* A simple C program manipulating typed variables */

int main(int argc, char **argv)
{
  int myint; // signed 4 byte integer
  float myfloat1, myfloat2; // 4 byte floating point
  char mychar; // a single character (1 byte)
  char mychararray[6] = {'h','e','l','l','o','\0'}; // an array of 10 characters
  char mystring[6] = "hello";

  mychar = 'a';
  myint = 12;
  myfloat1 = 10.5;
  myfloat2 = 105e-1;

  // see https://alvinalexander.com/programming/printf-format-cheat-sheet
  // see https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)FloatingPoint.html

  printf("myint is: %d\n", myint);
  printf("myfloat1 is: %.3f\n", myfloat1);
  printf("myfloat2 is: %.6f\n", myfloat2);
  printf("mychar is: %c\n", mychar);
  printf("mychararray is: %s\n", mychararray);
  printf("mystring is: %s\n", mystring);

  return 0;
 }