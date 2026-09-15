/*
Create a program containing a float array with 10 elements.
Print the address of each position in the array.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float float_array[10] = {
        1.8, 9.77, 7.0, 23.2, 5.9,
        17.2, 4.2, 10.0, 8.3, 1.98
    };

    float *array_pointer = float_array;

    for (array_pointer = float_array;
         array_pointer < float_array + 10;
         array_pointer++) {

        printf("%.2f\n", *array_pointer);
    }

    return 0;
}
