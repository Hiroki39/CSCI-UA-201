#include <stdio.h> 

struct comp {
   int a[3];
   char b[2];
   long c[2];
   double d;
   char e;
};

struct comp2 {
   char a;
   long b;
   char c[4];
   int d;
};

struct comp3 {
   char a[2];
   struct comp2 b;
   int c;
};


int main() {
   printf("Size of comp = %ld\n", sizeof(struct comp));
   printf("Size of comp2 = %ld\n", sizeof(struct comp2));
   printf("Size of comp3 = %ld\n", sizeof(struct comp3));
   struct comp3 temp;
   printf("Start of struct comp2: %ld\n", (void*)(&temp.b) - (void*)temp.a);
}