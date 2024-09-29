#include <stdio.h>
#include <stdlib.h>

int numberOfWinners(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    int count = 0;
    char ch;

    // Count lines by detecting newline characters
    while ((ch = getc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);
    return count;
}

int main() {
    const char *filename = "C:\\Users\\tianr\\Desktop\\IMT Nord Europe\\langue C\\MLOD_AlgoC\\TP3\\turingWinners.csv";

    // Get the number of winners
    int winnerCount = numberOfWinners(filename);
    printf("Total number of winners: %d\n", winnerCount);

    return 0;
}
