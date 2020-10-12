#include <stdio.h> 
  
int main() 
{ 
   int arr[] = {10, 20, 30, 40, 50, 60}; 
   int *ptr = arr; 
     
   // sizof(int) * (number of element in arr[]) is printed 
   printf("Size of arr[] %ld\n", sizeof(arr)); 
  
   printf("Size of ptr %ld\n", sizeof(ptr)); 
   return 0; 
} 