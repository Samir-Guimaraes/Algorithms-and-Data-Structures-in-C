/*
Write a program that declares an integer array and an integer pointer.
Associate the pointer with the array. Then, add one (+1) to each position
of the array using the pointer (use *).
*/

#include <stdio.h>
#include <stdlib.h>

void incrementArrayElementsUsingPointer(
    int numbers_array[],
    int *control_pointer
){
    control_pointer = numbers_array;

    printf("Array with unchanged values\n");

    for (
        control_pointer;
        control_pointer < numbers_array + 10;
        control_pointer++
    ){
        printf("%d ", *control_pointer);
    }

    control_pointer = numbers_array;
    // The control pointer is reset so that the second loop can be executed

    printf("\nArray with incremented values\n");

    for (
        control_pointer;
        control_pointer < numbers_array + 10;
        control_pointer++
    ){
        *control_pointer = *control_pointer + 1;
        printf("%d ", *control_pointer);
    }
}

int main(){

    int numbers_array[10] = {
        4, 3, 19, 1, 14, 25, 4, 6, 25, 14
    };

    int *control_pointer;

    incrementArrayElementsUsingPointer(
        numbers_array,
        control_pointer
    );

    return 0;
}
