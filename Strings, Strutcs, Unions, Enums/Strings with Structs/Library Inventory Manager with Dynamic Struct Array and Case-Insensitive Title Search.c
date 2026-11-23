/*
A program that manages a small library, using a struct to group a book's
title, author, publication year, and genre, all strings represented as
fixed-size character arrays (except the year, which is an int).

The user can register an unlimited number of books (dynamic allocation
via realloc), list all of them, search for a title, and remove a book
(removal not yet implemented).

The program focuses on:
- declaring and initializing a struct with string members;
- comparing and searching strings case-insensitively;
- passing structs (and arrays of structs) to functions;
- dynamically growing the book list with realloc as new entries are added.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define title_length 100
#define author_length 80
#define genre_length 50

struct library{
    char title[title_length];    /* Book title. */
    char author[author_length];  /* Author's name. */
    int year;                    /* Publication year. */
    char genre[genre_length];    /* Book genre. */
};

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void insert_book(struct library *books, int inventory){

    printf("Insira o título do livro: ");
    fgets(books[inventory - 1].title, sizeof(books[inventory - 1].title), stdin);
    printf("Insira o nome do autor: ");
    fgets(books[inventory - 1].author, sizeof(books[inventory - 1].author), stdin);
    printf("Insira o gênero do filme: ");
    fgets(books[inventory - 1].genre, sizeof(books[inventory - 1].genre), stdin);
    printf("Insira o ano de publicação do livro: ");
    scanf("%d", &books[inventory - 1].year);
};


void list_books(struct library *books, int inventory){
    for(int i = 0; i < inventory; i++){
        printf("- Exemplar %dº -\n\
        Nome: %s\n\
        Autor: %s\n\
        Gênero: %s\n\
        Ano: %d\n", (i + 1), books[i].title, books[i].author, books[i].genre, books[i].year);
    }
};

void string_lower(char *titulo_atual){
    for(int i = 0; titulo_atual[i] != '\0'; i++){
        titulo_atual[i] = tolower(titulo_atual[i]);
    }

}

bool searched_book(char *titulo_atual, char *titulo_buscado){
    for(int i = 0; titulo_atual[i] != '\0'; i++){
        for(int j = 0; titulo_buscado[j] != '\0'; j++){
            if(titulo_atual[i] != titulo_buscado[j])
                return false;
        }
    }
    return true;
};

int main(){
    int option, scanf_result, inventory = 0;


    struct library *books = malloc(inventory * sizeof(inventory));
    if(books == NULL){
        printf("Memory alocation failed.\n");
        return 1;
    }

library_loop:
    do{
    printf("----- Library -----\n\
       selecione a opção desejada\n\
       1 - Cadastrar novos livros.\n\
       2 - Listas livros cadastrados\n\
       3 - Pesquisar por título.\n\
       4 - Remover títulos inscritos.\n\
       5 - Abortar processo.\n\
       --> ");
           scanf_result = scanf("%d", &option);
           clear_buffer();

           if(scanf_result != 1)
            printf("\nSelecione um valor válido\n");
    }while(!scanf_result);

    switch (option){
    case 1:
        struct library *books_temp = realloc(books, (inventory+1) * sizeof(*books));
        if(books_temp == NULL){
            printf("Realocation failed.\n");
            return 1;
        }
        books = books_temp;
        inventory++;
        insert_book(books, inventory);
        break;
    case 2:
        if(inventory == 0)
            printf("Nenhum livro foi cadastrado");
        else
            list_books(books, inventory);
        break;
    case 3:
        if(inventory == 0){
            printf("Nenhum livro foi cadastrado");
        }
        else{

            char livro_atual[title_length], livro_buscado[title_length];
            int found = 0, contador = 0;

            printf("Escreva o título que deseja buscar: ");
            fgets(livro_buscado, sizeof(livro_buscado), stdin);

            string_lower(livro_atual);
            string_lower(livro_buscado);

            for(int i = 0; i < inventory; i++){
                if(searched_book(livro_atual, livro_buscado))
                    found = 1;
                    contador ++;
            }

            if(found)
                printf("Título %s encontrado %d vezes", livro_buscado,contador);
            else
                printf("Título %s não encontrado.", livro_buscado);
        }
        break;
    case 4:
        printf("Caso 4");
        break;
    case 5:
        printf("Processo abortado");
        break;
    default:
        printf("option invalid.");
        break;

    }


    if(option != 5)
        goto library_loop;
    free(books);

    return 0;
}
