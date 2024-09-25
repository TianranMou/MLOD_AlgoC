#include <stdio.h>


void echangeContenu(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;


    printf("before exchange: a = %d, b = %d\n", a, b);


    echangeContenu(&a, &b);


    printf("after changer: a = %d, b = %d\n", a, b);

    return 0;
}
