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
#include <string.h>

#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 80
#define GENRE_LENGTH 50

struct library {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
    char genre[GENRE_LENGTH];
};

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void trim_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

bool searched_book(const char *current_title, const char *search_title) {
    size_t n = strlen(search_title);
    if (n == 0) return true;
    for (size_t i = 0; current_title[i] != '\0'; i++) {
        size_t j = 0;
        while (j < n && current_title[i + j] != '\0' &&
               tolower((unsigned char)current_title[i + j]) ==
               tolower((unsigned char)search_title[j]))
            j++;
        if (j == n) return true;
    }
    return false;
}

void insert_book(struct library *books, int inventory) {
    int index = inventory - 1;
    printf("Enter the book title: ");
    fgets(books[index].title, sizeof(books[index].title), stdin);
    trim_newline(books[index].title);

    printf("Enter the author's name: ");
    fgets(books[index].author, sizeof(books[index].author), stdin);
    trim_newline(books[index].author);

    printf("Enter the book genre: ");
    fgets(books[index].genre, sizeof(books[index].genre), stdin);
    trim_newline(books[index].genre);

    printf("Enter the book publication year: ");
    if (scanf("%d", &books[index].year) != 1) {
        books[index].year = 0;
    }
    clear_buffer();
}

bool remove_book(struct library **books, int *inventory, const char *search_title) {
    int index = -1;

    for (int i = 0; i < *inventory; i++) {
        if (searched_book((*books)[i].title, search_title)) {
            index = i;
            break;
        }
    }

    if (index < 0) return false;

    for (int i = index; i < *inventory - 1; i++) {
        (*books)[i] = (*books)[i + 1];
    }

    (*inventory)--;

    if (*inventory > 0) {
        struct library *tmp = realloc(*books, (size_t)(*inventory) * sizeof(**books));
        if (tmp != NULL) *books = tmp;
    } else {
        free(*books);
        *books = NULL;
    }
    return true;
}

void list_books(const struct library *books, int inventory) {
    for (int i = 0; i < inventory; i++) {
        printf("- Copy %d -\n"
               "        Title: %s\n"
               "        Author: %s\n"
               "        Genre: %s\n"
               "        Year: %d\n",
               i + 1, books[i].title, books[i].author,
               books[i].genre, books[i].year);
    }
}

int main(void) {
    int option = 0;
    int inventory = 0;
    struct library *books = NULL;

    while (option != 5) {
        int scanf_result;
        do {
            printf("----- Library -----\n"
                   "       Select the desired option\n"
                   "       1 - Register new books.\n"
                   "       2 - List registered books.\n"
                   "       3 - Search by title.\n"
                   "       4 - Remove registered titles.\n"
                   "       5 - Abort process.\n"
                   "       --> ");
            scanf_result = scanf("%d", &option);
            clear_buffer();

            if (scanf_result != 1) {
                option = 0;
                printf("\nPlease select a valid value\n");
            }
        } while (scanf_result != 1);

        switch (option) {
        case 1: {
            struct library *tmp = realloc(books, (size_t)(inventory + 1) * sizeof(*books));
            if (tmp == NULL) {
                printf("Reallocation failed.\n");
                free(books);
                return 1;
            }
            books = tmp;
            inventory++;
            insert_book(books, inventory);
            break;
        }
        case 2:
            if (inventory == 0)
                printf("No books have been registered.\n");
            else
                list_books(books, inventory);
            break;
        case 3: {
            if (inventory == 0) {
                printf("No books have been registered.\n");
                break;
            }
            char search_title[TITLE_LENGTH];
            int counter = 0;

            printf("Enter the title you want to search for: ");
            fgets(search_title, sizeof(search_title), stdin);
            trim_newline(search_title);

            for (int i = 0; i < inventory; i++) {
                if (searched_book(books[i].title, search_title)) {
                    printf("Found: %s (Year: %d)\n", books[i].title, books[i].year);
                    counter++;
                }
            }

            if (counter > 0)
                printf("Title \"%s\" found %d time(s).\n", search_title, counter);
            else
                printf("Title \"%s\" not found.\n", search_title);
            break;
        }
        case 4: {
            if (inventory == 0) {
                printf("No books have been registered.\n");
                break;
            }
            char search_title[TITLE_LENGTH];

            printf("Enter the title you want to remove: ");
            fgets(search_title, sizeof(search_title), stdin);
            trim_newline(search_title);

            if (remove_book(&books, &inventory, search_title)) {
                printf("Book removed successfully.\n");
                if (inventory > 0)
                    list_books(books, inventory);
                else
                    printf("The library is empty.\n");
            } else {
                printf("The book \"%s\" has not been registered.\n", search_title);
            }
            break;
        }
        case 5:
            printf("Process aborted.\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    }

    free(books);
    return 0;
}
