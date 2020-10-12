#include "Rolldice.h"

int main() {
    int win = 0;
    int loss = 0;
    for (int i = 0; i < 1000; ++i) {
        int first_roll = rolldice();
        if (first_roll == 8) {
            ++win;
        } else {
            while (1) {
                int roll = rolldice();
                if (roll == 8) {
                    ++loss;
                    break;
                } else if (roll == first_roll) {
                    ++win;
                    break;
                }
            }
        }
    }
    printf("Wins: %i, Losses: %i\n", win, loss);
}
