#include <stdio.h>

int main() {
    double number1;
    double number2;
    char theoperator;
    printf("Enter the Formula:");
    scanf("%lf%c%lf", &number1, &theoperator, &number2);
    switch (theoperator) {
        case '+':
            printf("%lf", number1 + number2);
            break;
        case '-':
            printf("%lf", number1 - number2);
            break;
        case '*':
            printf("%lf", number1 * number2);
            break;
        case '/':
            printf("%lf", number1 / number2);
            break;
        default:
            printf("Invalied Argument\n");
    }
}
