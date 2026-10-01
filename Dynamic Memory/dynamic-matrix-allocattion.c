/*
A program that dynamically allocates a 2D integer matrix based on
user-defined dimensions (rows and columns), with a strong focus on
robust memory management.
Finally, it displays the matrix elements and properly releases the
allocated memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int **matrix, rowCount, columnCount;

    printf("Enter the number of rows in the matrix:\n");
    scanf("%d", &rowCount);

    printf("Enter the number of columns in the matrix:\n");
    scanf("%d", &columnCount);

    matrix = (int **) malloc(rowCount * sizeof(int *));

    for(int i = 0; i < rowCount; i++){
        matrix[i] = (int *) malloc(columnCount * sizeof(int));

        for(int j = 0; j < columnCount; j++){
            printf("Enter the value for row %d, column %d: ", (i+1), (j+1));
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < columnCount; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rowCount; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
