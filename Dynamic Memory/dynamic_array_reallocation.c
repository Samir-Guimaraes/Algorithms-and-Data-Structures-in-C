/*
A program that dynamically allocates an integer array based on
a user-defined number of elements.

Then, ask the user how many additional elements should be added,
resize the allocated memory using realloc(), and allow the user to
enter values for the new positions.

Finally, display all elements of the resized array and properly
release the allocated memory.
*/

#include <stdio.h>
#include <stdlib.h>

void populate_array(int **array, int *element_count) {

    printf("Enter the number of elements in the array:\n");
    scanf("%d", element_count);

    *array = (int *)malloc((*element_count) * sizeof(int));

    if (*array == NULL) {
        printf("Error: insufficient memory!\n");
        exit(1);
    }

    for (int i = 0; i < *element_count; i++) {
        printf("Enter the value for position %d:\n", (i + 1));
        scanf("%d", (*array) + i);
    }

    for (int i = 0; i < *element_count; i++) {
        printf("%d ", (*array)[i]);
    }
}


void increase_array_size(int **array, int **temporary_array,
                         int *additional_elements, int *element_count) {

    printf("\nEnter the number of elements to add to the array:\n");
    scanf("%d", additional_elements);

    *temporary_array = (int *)realloc(
        *array,
        (*additional_elements) * sizeof(int)
    );

    if (temporary_array != NULL) {
        array = temporary_array;
    }

    int new_position = *element_count + 1;

    for (int i = 0; i < *additional_elements; i++) {
        printf("Enter the value for position %d:\n", new_position);
        scanf("%d", (*array) + (*element_count + i));
        new_position++;
    }

    int new_length = *element_count + *additional_elements;

    for (int i = 0; i < new_length; i++) {
        printf("%d ", (*array)[i]);
    }
}


int main() {

    int *array = NULL, *temporary_array = NULL;
    int element_count, additional_elements;

    populate_array(&array, &element_count);

    increase_array_size(
        &array,
        &temporary_array,
        &additional_elements,
        &element_count
    );

    free(array);

    return 0;
}
