#include <stdio.h>

struct Student {
    char name[10];
    int mark1;
    int mark2;
    float percentage;
};

int main() {
    struct Student student;
    printf("Enter Student Name: ");
    scanf("%s", student.name);
    printf("Enter Mark1: ");
    scanf("%i", &student.mark1);
    printf("Enter Mark2: ");
    scanf("%i", &student.mark2);
    student.percentage = ((float)student.mark1 + (float)student.mark2) / 2;

    printf("=====================================\n");

    printf("Student: %s\nMark1: %i\nMark2: %i\nPerentage: %.2f%%\n",
           student.name, student.mark1, student.mark2, student.percentage);
}
