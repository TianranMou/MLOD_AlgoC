#include <stdio.h>

#define SIZE 5


void matrix_mult(int result[][SIZE], int mat1[][SIZE], int mat2[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}


void matrix_print(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int mat1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    int mat2[SIZE][SIZE] = {
        {6, 7, 8, 9, 10},
        {6, 7, 8, 9, 10},
        {6, 7, 8, 9, 10},
        {6, 7, 8, 9, 10},
        {6, 7, 8, 9, 10}
    };

    int result[SIZE][SIZE];


    matrix_mult(result, mat1, mat2);


    printf("final result：\n");
    matrix_print(result);

    return 0;
}







