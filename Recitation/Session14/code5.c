#include <stdio.h> 

struct Point1
{
   int x;
   float y;
   char z;
};

struct Point2
{
   int x;
   double y;
   char z;
};

struct Point3
{
   int x;
   char arr[5];
   float y;
};

struct Point4
{
   int x;
   struct Point1 p;
   float y;
};

struct Point5
{
   char x[3];
   struct Point1 p;
   float y;
};


int main() {
   printf("Size of Point1 = %d\n", sizeof(struct Point1));
   printf("Size of Point2 = %d\n", sizeof(struct Point2));
   printf("Size of Point3 = %d\n", sizeof(struct Point3));
   printf("Size of Point4 = %d\n", sizeof(struct Point4));
   printf("Size of Point5 = %d\n", sizeof(struct Point5));
}