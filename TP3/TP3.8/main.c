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

// Function to sort the winners array by year using bubble sort
void sortTuringWinnersByYear(TuringWinner winners[], int count) {
    TuringWinner temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (winners[j].year > winners[j + 1].year) {
                // Swap the two entries
                temp = winners[j];
                winners[j] = winners[j + 1];
                winners[j + 1] = temp;
            }
        }
    }
}

// Function to find and display information for a specific year
void infosAnnee(int year, TuringWinner winners[], int count) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (winners[i].year == year) {
            printf("Year: %d, Winner(s): %s, Work Nature: %s\n",
                   winners[i].year, winners[i].winners, winners[i].workNature);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No winner found for the year %d\n", year);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <inputfile> <outputfile> [--sort] [year]\n", argv[0]);
        return 1;
    }

    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];

    TuringWinner winners[MAX_WINNERS];
    int count;

    // Read the input CSV file
    readWinners(inputFilename, winners, &count);

    // Check if the user provided the --sort option
    int sortFlag = 0;
    int yearFlag = 0;
    int year = 0;

    // Parse command line arguments for sorting and year options
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "--sort") == 0) {
            sortFlag = 1;
        } else {
            yearFlag = 1;
            year = atoi(argv[i]);
        }
    }

    // Sort the winners by year if --sort is provided
    if (sortFlag) {
        sortTuringWinnersByYear(winners, count);
    }

    // Print the winners information to the output CSV file
    printWinners(outputFilename, winners, count);

    // Display info for the specified year if year is provided
    if (yearFlag) {
        infosAnnee(year, winners, count);
    }

    printf("Winners data has been written to %s\n", outputFilename);

    return 0;
}
