#include <stdio.h>
#include <stdlib.h>
#include "cryptography.h"

#define lenght 100

int main()
{
    char text[lenght];

    printf("Enter the text: ");
    scanf("%99s", text);

    encrypt_cesar(text);

    printf("Encrypted text: %s\n", text);

    return 0;
}
