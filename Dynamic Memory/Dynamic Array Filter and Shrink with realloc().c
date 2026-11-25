/*
Write a program that asks the user for the quantity N of integers
they want to insert. Then, dynamically allocate an array of N integers
and fill it with the values entered by the user.

After that, ask the user for a value X (any integer). The program must
remove all occurrences of X from the array, "compacting" the remaining
elements to the beginning of the array (i.e., without leaving gaps).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_array(int *array, int length_array){
    printf("\n--- Array ---\n");
    for(int i = 0; i < length_array; i++){
       printf("%d ", array[i]);
    }
}

bool number_in_array(int *array, int length_array, int number){
    for(int i = 0; i < length_array; i++){
        if(array[i] == number)
            return true;
    }
    return false;
}

void remover_number(int **array, int *length_array, int number){

    int *array_temp, indice;

    if(*length_array == 1){
        printf("\nA size-1 array cannot be shrunk.\n");
        free(*array);
        exit(1);
    }

    for(int i = 0; i < *length_array; i++){
        if((*array)[i] == number){
            indice = i;
            break;
        }
    }

    for(int i = indice; i < (*length_array - 1); i++){
        (*array)[i] = (*array)[i + 1];
    }

    array_temp = (int *) realloc(*array, (*length_array - 1) * sizeof(int));
    if(array_temp == NULL){
        printf("Memory reallocation error.");
        exit(1);
    }
    (*length_array)--;

    *array = array_temp;
}

int main(){
    int *array, length_array;

    printf("Enter the desired array size: ");
    scanf("%d", &length_array);

    array = (int *) malloc(length_array * sizeof(int));
    if(array == NULL){
        printf("Memory allocation error.");
        return 1;
    }

    for(int i = 0; i < length_array; i++){
        printf("Enter the number you want to insert at position %d: ", (i+1));
        scanf("%d", &array[i]);
    }

    print_array(array, length_array);

    int number, indice, contador = 0;

    process_loop:
    printf("\nSelect a number to be removed from the array: ");
    scanf("%d", &number);

    if(!number_in_array(array, length_array, number)){
        printf("\nThe number %d is not present in the array.\n", number);
    }else{
        do{
            remover_number(&array, &length_array, number);
        }while(number_in_array(array, length_array, number));
    }

    print_array(array, length_array);


    int option;
    printf("\n\nDo you want to remove another number?\nSelect 1 for remove another number.\nSelect any other number to end the process.\n-->");
    scanf("%d", &option);

    if(option == 1)
        goto process_loop;
    free(array);

    return 0;
}
