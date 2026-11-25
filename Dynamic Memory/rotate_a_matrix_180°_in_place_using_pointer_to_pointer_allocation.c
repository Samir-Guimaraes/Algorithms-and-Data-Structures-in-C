/*
Exercise 6 — In-Place Matrix 180° Rotation with Dynamic Allocation

Write a program that asks the user for the number of rows and columns
of a matrix. Dynamically allocate the matrix as an array of row pointers
(pointer-to-pointer), with proper error handling at both allocation levels.
Ask the user to fill in all elements, then display the original matrix.

The program must then invert the matrix in place — rotating it 180 degrees —
without allocating a second matrix. Each element at position [i][j] is
swapped with the element at the symmetric position from the center of the
matrix. Display the inverted matrix and properly release all allocated
memory (each row individually, then the row-pointer array).

Note: the 180-degree inversion must be performed pairwise, walking from the
outer edges toward the center, so that each element is swapped only once.
*/

#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int columns){

    printf("\n--- Original Matrix ---\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
}

void invert_matrix(int **matrix, int rows, int columns){
    int temp;

    if(rows % 2 == 0){
        for(int i = 0; i < rows/2; i++){
            for(int j = 0; j < columns; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[(rows-1)-i][(columns-1)-j];
                matrix[(rows-1)-i][(columns-1)-j] = temp;
            }
        }
    }
    else{
        int middle = rows / 2;
        for(int i = 0; i < rows/2; i++){
            for(int j = 0; j < columns/2; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[middle][(columns-1)-j];
                matrix[middle][(columns-1)-j] = temp;
            }
        }
    }

    printf("\n--- Inverted Matrix ---\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int **matrix, rows, columns;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);

    matrix = (int **) malloc(rows * sizeof(int *));
    if(matrix == NULL){
        printf("Memory allocation error for rows.");
        return 1;
    }

    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &columns);

    for(int i = 0; i < rows; i++){
        matrix[i] = (int *) malloc(columns * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation error for columns.");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("Enter a value at position [%d][%d]: ", (i+1), (j+1));
            scanf("%d", &matrix[i][j]);
        }
    }

    print_matrix(matrix, rows, columns);

    invert_matrix(matrix, rows, columns);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
