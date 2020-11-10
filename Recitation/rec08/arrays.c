#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    
    int * vals = (int * ) malloc ( size ) ;
    int * partial_sums = (int * ) malloc (size ) ;
    
    if (vals == 0 || partial_sums == 0) 
        return 1; //memory not allocated correctly 
    
    int index = 0; 

    //initialize the array vals to powers of 2 corresponding to the
    //index in the array 
    while(index < size)
    {
        vals[index] = 1 << index; 
        index++; 
    }
    
    index = 0; 
    //initialize the array partial_sums to zeros
    while(index < size)
    {
        partial_sums[index] = 0; 
        index++; 
    }
    
    
 
    index = 0;
    int sum = 0; 
    //caclulate partial sums of powers of 2 from 0 to index and store in 
    //partial_sums[index] 
    while (index < size ) 
    {
        sum += vals[index];
        partial_sums[index] = sum;  
        index++;
    }
    
    index = 0; 
    //print the results for powers of two and the partial sums
    while (index < size ) 
    {
        printf("2^%d = %4d \t", index, vals[index] ); 
        printf("1^0 + ... + 1^%d = %5d\n", index, partial_sums[index] );  
        index++;
    }   
    
    //Note: this program should de-allocate memory that was allocated with 
    //malloc(). But since there are memory related issues in this code,
    //the program crashes when free() is called. 
   
    return 0;
}
