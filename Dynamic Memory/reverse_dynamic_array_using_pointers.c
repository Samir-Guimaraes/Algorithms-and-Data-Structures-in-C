/*
A program that asks the user for a number N.
Dynamically allocate an array of N integers.
Fill it with user-entered values.
Then, reverse the array in place (without creating another array),
using only pointers (without array indexing v[i]).
Print the reversed array and free the allocated memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array, *start, *end, *middle, *current;
    int auxiliary, number_of_elements;

    printf("Enter the number of values to be inserted into the array:\n");
    scanf("%d", &number_of_elements);

    array = (int *) malloc(number_of_elements * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation error.");
        exit(1);
    }

    current = array;

    for (int i = 0; i < number_of_elements; i++, current++) {
        printf("Enter the value for position %d: ", i);
        scanf("%d", current);
    }

    start = array;
    end = array + number_of_elements - 1;
    middle = array + (number_of_elements / 2);

    for (start, end; start < middle; start++, end--) {
        auxiliary = *start;
        *start = *end;
        *end = auxiliary;
    }

    start = array;

    printf("Reversed array: ");

    for (start; start < array + number_of_elements; start++) {
        printf("%d ", *start);
    }

    free(array);

    return 0;
}
