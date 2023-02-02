#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RACE_LENGTH 70

// Function to generate random number
int getRandom(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    int tortoisePos = 1, harePos = 1;
    srand(time(NULL));

    while (tortoisePos < RACE_LENGTH && harePos < RACE_LENGTH) {
        int move = getRandom(1, 100);
        if (move <= 50) { // Fast plod (50%)
            tortoisePos += 3;
        } else if (move <= 70) { // Slip (20%)
            tortoisePos -= 6;
        } else if (move <= 100) { // Slow plod (30%)
            tortoisePos += 1;
        }

        move = getRandom(1, 100);
        if (move <= 20) { // Sleep (20%)
            // No move
        } else if (move <= 40) { // Big hop (20%)
            harePos += 9;
        } else if (move <= 50) { // Big slip (10%)
            harePos -= 12;
        } else if (move <= 80) { // Small hop (30%)
            harePos += 1;
        } else if (move <= 100) { // Small slip (20%)
            harePos -= 2;
        }

        // Ensure positions are within race length
        if (tortoisePos < 1) {
            tortoisePos = 1;
        }
        if (harePos < 1) {
            harePos = 1;
        }
        if (tortoisePos > RACE_LENGTH) {
            tortoisePos = RACE_LENGTH;
        }
        if (harePos > RACE_LENGTH) {
            harePos = RACE_LENGTH;
        }

        // Show progress of the race
        for (int i = 1; i <= RACE_LENGTH; i++) {
            if (i == tortoisePos && i == harePos) {
                printf("OUCH!!!");
            } else if (i == tortoisePos) {
                printf("T");
            } else if (i == harePos) {
                printf("H");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }

    if (tortoisePos >= RACE_LENGTH && harePos >= RACE_LENGTH) {
        printf("It's a tie!\n");
    } else if (tortoisePos >= RACE_LENGTH) {
        printf("Tortoise wins!\n");
    } else {
        printf("Hare wins!\n");
    }

    return 0;
}
