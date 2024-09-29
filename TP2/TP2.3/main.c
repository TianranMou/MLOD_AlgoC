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

// Function to initialize a date
void initialiseDate(Date *d) {
    int mois;
    printf("Enter date (day month year): ");
    scanf("%d %d %d", &d->jour, &mois, &d->annee);
    d->mois = (Mois)mois; // Convert the integer input to Mois enum type
}

// Function to display the date
void afficheDate(const Date *d) {
    printf("Date: %d/%d/%d\n", d->jour, d->mois, d->annee);
}

int main() {
    Date d;

    // Initialize and display the date
    initialiseDate(&d);
    afficheDate(&d);

    return 0;
}


