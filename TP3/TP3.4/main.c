#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about each winner
typedef struct {
    int year;
    char winners[100];   // To store the winner's name(s)
    char workNature[200]; // To store the nature of the work
} TuringWinner;

#define MAX_WINNERS 100 // Assuming there are at most 100 entries

// Function to read the CSV file and store the data in the array
void readWinners(const char *filename, TuringWinner winners[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    char line[300];
    *count = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Use strtok to split each line by semicolon
        char *token = strtok(line, ";");
        winners[*count].year = atoi(token);  // The first field is the year

        token = strtok(NULL, ";");
        strcpy(winners[*count].winners, token);  // The second field is the winner(s) name(s)

        token = strtok(NULL, ";");
        strcpy(winners[*count].workNature, token); // The third field is the nature of the work

        (*count)++;
    }

    fclose(file);
}

// Function to print winners data into a new CSV file
void printWinners(const char *outputFilename, TuringWinner winners[], int count) {
    FILE *file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Cannot open file %s\n", outputFilename);
        exit(1);
    }

    // Write each winner's data to the file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d;%s;%s\n", winners[i].year, winners[i].winners, winners[i].workNature);
    }

    fclose(file);
}

int main() {
    TuringWinner winners[MAX_WINNERS];
    int count;

    // Read the CSV file
    readWinners("C:\\Users\\tianr\\Desktop\\IMT Nord Europe\\langue C\\MLOD_AlgoC\\TP3\\turingWinners.csv", winners, &count);

    // Print the winners information to a new file
    printWinners("out.csv", winners, count);

    printf("Winners data has been written to out.csv\n");

    return 0;
}
