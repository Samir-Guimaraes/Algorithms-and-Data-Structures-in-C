/***
A program that asks the user for a phrase and writes it to a text file.
Then, it reopens the same file and displays its content character by
character on the screen, with a strong focus on correct file opening,
closing and error checking.
***/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file;
    char text[50];

    file = fopen("file.txt", "w");

    if(file == NULL){
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter a phrase to be stored in the created file:\n");
    fgets(text, sizeof(text), stdin);

    fputs(text, file);
    fclose(file);

    file = fopen("file.txt", "r");

    if(file == NULL){
        printf("Error opening the file.\n");
        return 1;
    }

    int c = fgetc(file);
    printf("\nContent of the phrase stored in the file:\n");
    while(c != EOF){
        putchar(c);
        c = fgetc(file);
    }
    fclose(file);

    return 0;
}
