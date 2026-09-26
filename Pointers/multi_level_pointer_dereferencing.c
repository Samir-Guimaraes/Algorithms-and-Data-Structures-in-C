/*
Consider the following declaration: int A, *B, **C, ***D.
A program that reads variable A and calculates and displays
twice, three times, and four times its value using only pointers B, C, and D.
Pointer B must be used to calculate twice the value, C three times the value,
and D four times the value.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int variable_A = 10, *variable_B, **variable_C, ***variable_D;

    variable_B = &variable_A;
    variable_C = &variable_B;
    variable_D = &variable_C;

    printf("Original: %d\n", variable_A);
    printf("Double: %d\n", *variable_B * 2);
    printf("Triple: %d\n", **variable_C * 3);
    printf("Quadruple: %d\n", ***variable_D * 4);

    return 0;
}