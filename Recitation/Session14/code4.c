#include <stdio.h> 

struct Point
{
   int x;
   float y;
   char z;
};

void foo(struct Point* p) {
    p->x = 5;
    (*p).y = 3.14f;
}

int main() {
    struct Point p1 = {3, 1.67f, 'e'}; 
   
   // Accessing members of point p1 
   p1.x = 20; 
   printf("x = %d, y = %f, z = %c\n", p1.x, p1.y, p1.z);
   foo(&p1);
   printf("x = %d, y = %f, z = %c\n", p1.x, p1.y, p1.z);
   return 0;
}