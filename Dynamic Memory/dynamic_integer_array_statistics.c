/*
A program that receives from the user the number N of values to be entered.
Then, the program must dynamically allocate an array of N integers,
receive N numbers from the user and store them in the array, and display
the largest value in the array, the smallest value in the array, and the average.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array, *max_element, *min_element;
    int number_of_elements, sum_of_elements;
    float average;

    printf("Enter the number of values to be inserted into the array:\n");
    scanf("%d", &number_of_elements);

    array = (int *) calloc(number_of_elements, sizeof(int));

    if (array == NULL) {
        printf("Memory allocation error.");
        exit(1);
    }

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter the value for position %d:\n", i);
        scanf("%d", &array[i]);
    }

    max_element = array;
    min_element = array;
    sum_of_elements = 0;

    for (int i = 0; i < number_of_elements; i++) {

        if (array[i] < *min_element) {
            min_element = &array[i];
        }

        if (array[i] > *max_element) {
            max_element = &array[i];
        }

        sum_of_elements += array[i];

        printf("%d ", array[i]);
    }

    average = sum_of_elements / number_of_elements;

    printf(
        "\nLargest element: %d\n"
        "Smallest element: %d\n"
        "Sum of elements: %d\n"
        "Average: %.2f",
        *max_element,
        *min_element,
        sum_of_elements,
        average
    );

    free(array);
    return 0;
}
