/*
Write a function that accepts an integer array with N values as a parameter
and determines the largest element in the array and the number of times
this element occurred in the array.

For example, for an array with the following elements:
5, 2, 15, 3, 7, 15, 8, 6, 15,
the function should return to the calling program the value 15 and the
number 3, indicating that the number 15 occurred 3 times.
The function must be of type void.
*/

#include <stdio.h>
#include <stdlib.h>

void findMaximumAndCountOccurrences(
    int numbers_array[],
    int *maximum_element,
    int *maximum_occurrences
){
    int *control_pointer;

    control_pointer = numbers_array;
    *maximum_element = *control_pointer;
    *maximum_occurrences = 1;

    for (
        control_pointer;
        control_pointer < numbers_array + 9;
        control_pointer++
    ){
        if (*control_pointer > *maximum_element){
            *maximum_element = *control_pointer;
            *maximum_occurrences = 1;
        }
        else if (*control_pointer == *maximum_element){
            (*maximum_occurrences)++;
        }
    }
}

int main(){

    int numbers_array[10] = {
        4, 3, 19, 1, 14, 25, 4, 6, 25, 14
    };

    int maximum_element, maximum_occurrences;

    findMaximumAndCountOccurrences(
        numbers_array,
        &maximum_element,
        &maximum_occurrences
    );

    printf(
        "Maximum element: %d\n"
        "Maximum element occurs %d times",
        maximum_element,
        maximum_occurrences
    );

    return 0;
}
