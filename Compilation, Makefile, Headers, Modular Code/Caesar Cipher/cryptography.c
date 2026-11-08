#include "cryptography.h"
#include <ctype.h>

char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'z'};

char* encrypt_cesar(char text[]) {
    for(int i = 0; text[i] != '\0'; i++) {
        char atual = tolower(text[i]);

        for(int j = 0; j < 26; j++) {
            if(atual == alphabet[j]) {
                // Pula 3 casas e usa o '% 26' para dar a volta no alfabeto se passar do 'z'
                text[i] = alphabet[(j + 3) % 26];
                break;
            }
        }
    }
    return text;
}
