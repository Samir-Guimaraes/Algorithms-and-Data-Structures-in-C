/***
A program that copies the content of a source text file into a new
destination text file, character by character. During the copy, it
counts how many characters were transferred and displays the total
on the screen. Focus on robust file handling and error checking.

Note: the source file "source.txt" must exist beforehand.
***/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *source_file, *destination_file;

    source_file = fopen("source.txt", "r");
    if(source_file == NULL){
        printf("Error opening the source file.\n");
        return 1;
    }

    destination_file = fopen("destination.txt", "w");
    if(destination_file == NULL){
        printf("Error opening the destination file.\n");
        fclose(source_file);          // don't leak the source file
        return 1;
    }

    int c = fgetc(source_file);
    int count = 0;
    while(c != EOF){
        fputc(c, destination_file);
        c = fgetc(source_file);
        count++;
    }

    fclose(source_file);
    fclose(destination_file);

    printf("\nNumber of characters transferred: %d\n", count);

    return 0;
}
