#include <stdio.h>

int main(void) {
    
    int number = 8;

    int sum_diviseur = 1;
    for( int i = 2; i < number ; i++ ) {
        if(number%i == 0)
            sum_diviseur += i;
    }
    
    if(number==sum_diviseur)
        printf("%d est parfait\n",number);
    else
        printf("%d n'est PAS parfait\n",number);


    return 0;
}