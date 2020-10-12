#include <stdio.h>

int main(int argc, char* argv[]) {
    switch (argc) {
        case 0:
            printf("No arguments provided\n");
            break;
        case 1:
            printf("One arg provided: %s\n", argv[0]);
            break;
        case 2:
            printf("Two args given: %s and %s\n", argv[0], argv[1]);
            break;
        case 3:
            printf("More than 2 args: %s, %s, %s, etc\n", argv[0], argv[1],
                   argv[2]);
    }
}
