#include <stdio.h>


typedef short TypeEntier;


TypeEntier factorielle(TypeEntier n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorielle(n - 1);
    }
}

int main() {
    TypeEntier num;


    printf("Enter a number: ");
    scanf("%hd", &num);


    printf("%hd final resulate: %hd\n", num, factorielle(num));

    return 0;
}
