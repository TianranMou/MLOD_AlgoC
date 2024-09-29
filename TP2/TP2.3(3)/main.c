#include <stdio.h>
#include <stdlib.h>

// Define enum for months
typedef enum {
    JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN,
    JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
} Mois;

// Define Date structure
typedef struct {
    int jour;
    Mois mois;
    int annee;
} Date;

// Function to dynamically allocate memory for a Date and return its pointer
Date* newDate() {
    Date *d = (Date*)malloc(sizeof(Date));  // Dynamically allocate memory for Date
    if (d == NULL) {  // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        exit(1);  // Exit program if allocation failed
    }

    int mois;
    printf("Enter date (day month year): ");
    scanf("%d %d %d", &d->jour, &mois, &d->annee);
    d->mois = (Mois)mois;  // Convert the integer input to Mois enum type
    return d;  // Return the pointer to the allocated memory
}

// Function to display the date
void afficheDate(const Date *d) {
    printf("Date: %d/%d/%d\n", d->jour, d->mois, d->annee);
}

int main() {
    Date *date;

    // Create a new date using dynamic memory allocation
    date = newDate();
    afficheDate(date);

    // Free the dynamically allocated memory
    free(date);

    return 0;
}
