/*
Create a program containing a 3x3 float matrix.
Use a pointer to traverse the rows and another pointer to traverse
the elements of each row, printing the value of each element.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float float_matrix[3][3] = {
        {1.00, 2.00, 3.00},
        {4.00, 5.00, 6.00},
        {8.00, 9.00, 10.00}
    };

    float (*row_pointer)[3] = float_matrix;
    float *element_pointer = &float_matrix[0][0];

    for (row_pointer; row_pointer < float_matrix + 3; row_pointer++) {

        for (element_pointer = *row_pointer;
             element_pointer < *row_pointer + 3;
             element_pointer++) {

            printf("%.2f ", *element_pointer);
        }

        printf("\n");
    }

    return 0;
}
