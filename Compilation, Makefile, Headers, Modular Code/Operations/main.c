#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    int opction;
    float number01, number02, result;

    do{
        printf("Choose one of 4 basics operations: \n1 - Addition \n2 - Subtraction \n3 - Multiplication \n4 - Division\n");
        scanf("%d", &opction);
    }while(opction < 1 || opction > 4);

    printf("Enter the first number: ");
    scanf("%f", &number01);
    printf("Enter the second number: ");
    scanf("%f", &number02);

    switch(opction){
        case 1:
            result = addition(number01, number02);
            printf("\nAddition - \n%.2f + %.2f = %.2f: ", number01, number02, result);
            break;
        case 2:
            result = subtraction(number01, number02);
            printf("\nSubtraction - \n%.2f - %.2f = %.2f", number01, number02, result);
            break;
        case 3:
            result = multiplication(number01, number02);
            printf("\nMultiplication - \n%.2f * %.2f = %.2f", number01, number02, result);
            break;
        case 4:
            result = division(number01, number02, result);
            printf("\nDivision - \n%.2f / %.2f = %.2f", number01, number02, result);
            break;
        default:
            printf("Error with operation selected.");

    }
    return 0;
}
