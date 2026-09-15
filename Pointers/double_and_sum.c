/*
Write a program that reads two integer values (A and B).
Then, create a function that returns the sum of twice the two
read values. The function must store twice the value of A in
variable A itself and twice the value of B in variable B itself.
*/

#include <stdio.h>
#include <stdlib.h>

void doubleAndSum(int *ptr_A, int *ptr_B);

int main() {
    int var_A, var_B, result;

    printf("Enter an integer value for variable A:\n");
    scanf("%d", &var_A);

    printf("Enter an integer value for variable B:\n");
    scanf("%d", &var_B);

    int *ptr_A = &var_A, *ptr_B = &var_B;

    doubleAndSum(ptr_A, ptr_B);

    return 0;
}

void doubleAndSum(int *ptr_A, int *ptr_B) {
    *ptr_A = *ptr_A * 2;
    *ptr_B = *ptr_B * 2;

    int doubledSum = *ptr_A + *ptr_B;

    printf("---------------------");
    printf("\nEntered Values\n");
    printf("Doubled value of variable A: %d\nDoubled value of variable B: %d",
           *ptr_A, *ptr_B);
    printf("\nSum of the doubled values: %d", doubledSum);
    printf("\n---------------------\n");
}

