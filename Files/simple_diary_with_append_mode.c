/***
A program that works as a simple diary. It opens a file in append mode
so new lines are always added at the end, asks the user for a new line
of text, writes it to the file, and then reopens the file in read mode
to display the full history on the screen.
***/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *diary_file;
    char text[500];

    diary_file = fopen("diary.txt", "a");
    if(diary_file == NULL){
        printf("Error opening the file for writing.\n");
        return 1;
    }

    printf("Enter the text you want to write in the diary: ");
    fgets(text, sizeof(text), stdin);

    fputs(text, diary_file);
    fclose(diary_file);

    diary_file = fopen("diary.txt", "r");
    if(diary_file == NULL){
        printf("Error opening the file for reading.\n");
        return 1;
    }

    char line[500];
    printf("\nDiary history:\n");
    while(fgets(line, sizeof(line), diary_file) != NULL){
        printf("%s", line);
    }
    fclose(diary_file);

    return 0;
}
