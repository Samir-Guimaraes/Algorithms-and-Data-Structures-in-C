/*
Write a program that reads 2 integer values and calls a function
that receives these 2 variables and swaps their contents.
In other words, the function is called with two variables A and B,
and after the function execution, A contains B's value and B contains A's value.
*/

#include <stdio.h>
#include <stdlib.h>

void somaDobro(int *ptr_A, int *ptr_B);

int main() {
    int var_A, var_B;

    printf("Enter an integer value for variable A:\n");
    scanf("%d", &var_A);

    printf("Enter an integer value for variable B:\n");
    scanf("%d", &var_B);

    int *ptr_A = &var_A, *ptr_B = &var_B;

    swapValues(ptr_A, ptr_B);

    return 0;
}

void swapValues(int *ptr_A, int *ptr_B) {
    printf("---------------------");
    printf("\nOriginal Values\n");
    printf("Variable A: %d\nVariable B: %d", *ptr_A, *ptr_B);
    printf("\n---------------------\n");

    int var_aux = *ptr_A;
    *ptr_A = *ptr_B;
    *ptr_B = var_aux;

    printf("---------------------");
    printf("\nSwapped Values\n");
    printf("Variable A: %d\nVariable B: %d", *ptr_A, *ptr_B);
    printf("\n---------------------\n");
}
