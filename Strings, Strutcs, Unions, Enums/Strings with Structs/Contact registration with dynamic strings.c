/*
A program that manages a small contact schedule, using a struct to group
a person's name, phone number, email, and physical address, all represented
as fixed-size character arrays.

The user can register an unlimited number of contacts (dynamic allocation
via realloc), list all of them, and search for a contact by name using
string comparison.

The exercise focuses on:
- declaring and initializing a struct with string members;
- safely reading strings (avoiding buffer overflow);
- comparing and searching strings (case-insensitive);
- passing structs (and arrays of structs) to functions;
- dynamically growing the contact list with realloc as new entries are added.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAME_LENGTH     50
#define PHONE_LENGTH    15
#define EMAIL_LENGTH    60
#define ADDRESS_LENGTH  100

struct contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char address[ADDRESS_LENGTH];
};

/* Clears any leftover characters in stdin (e.g. the trailing newline). */
void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Converts a string to lowercase in place for case-insensitive comparison. */
void string_to_lower(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower((unsigned char)word[i]);
    }
}

/* Returns true if both strings are equal up to the length of word_02.
   Note: word_01 is expected to be pre-lowercased as well. */
bool words_are_equal(char *word_01, char *word_02) {
    for (int i = 0; word_02[i] != '\0'; i++) {
        if (word_01[i] != word_02[i])
            return false;
    }
    return true;
}

/* Reads a contact's data into the last slot of the schedule array. */
void insert_contact(struct contact *schedule, int num_users) {
    printf("Enter the contact's name: ");
    fgets(schedule[num_users - 1].name, sizeof(schedule[num_users - 1].name), stdin);

    printf("Enter the contact's phone number: ");
    fgets(schedule[num_users - 1].phone, sizeof(schedule[num_users - 1].phone), stdin);

    printf("Enter the contact's email: ");
    fgets(schedule[num_users - 1].email, sizeof(schedule[num_users - 1].email), stdin);

    printf("Enter the contact's physical address: ");
    fgets(schedule[num_users - 1].address, sizeof(schedule[num_users - 1].address), stdin);
}

/* Prints every registered contact in the schedule. */
void print_contacts(struct contact *schedule, int num_users) {
    for (int i = 0; i < num_users; i++) {
        printf("\n--------------------\n");
        printf("\nContact #%d\n", i + 1);
        printf("Name:     %s", schedule[i].name);
        printf("Phone:    %s", schedule[i].phone);
        printf("Email:    %s", schedule[i].email);
        printf("Address:  %s", schedule[i].address);
        printf("\n--------------------\n");
    }
}

int main(void) {

    int num_users = 0, scanf_result, option;
    char search_name[NAME_LENGTH];

    struct contact *schedule = malloc(num_users * sizeof(*schedule));
    if (!schedule) {
        printf("Memory allocation failed.\n");
        return 1;
    }

loop:
    do {
        printf("Choose an action:\n \
           1 - Register a new contact.\n \
           2 - View all registered contacts.\n \
           3 - Search for a contact by name.\n \
           4 - Exit.\n \
           -> ");
        scanf_result = scanf("%d", &option);
        clear_buffer();
        if (scanf_result != 1) {
            printf("- Please select a valid option -\n");
        }
    } while (!scanf_result);

    switch (option) {
    case 1: {
        struct contact *schedule_temp = realloc(schedule, sizeof(*schedule) * (num_users + 1));
        if (schedule_temp == NULL) {
            printf("Reallocation failed!\n");
            free(schedule);
            return 1;
        }
        schedule = schedule_temp;
        num_users++;
        insert_contact(schedule, num_users);
        break;
    }

    case 2:
        if (num_users == 0) {
            printf("\n\nSchedule is empty, nothing to print.\n\n");
        } else {
            print_contacts(schedule, num_users);
        }
        break;

    case 3: {
        int found = 0;
        if (num_users == 0) {
            printf("\n\nSchedule is empty, no names to search.\n\n");
        } else {
            printf("Enter the name you want to search for: ");
            fgets(search_name, sizeof(search_name), stdin);
            string_to_lower(search_name);

            for (int i = 0; i < num_users; i++) {
                string_to_lower(schedule[i].name);
                if (words_are_equal(schedule[i].name, search_name)) {
                    found++;
                }
            }

            if (found != 0)
                printf("\n\nYes, the name %s has already been registered.\n\n", search_name);
            else
                printf("\n\nNo contact found with that name.\n\n");
        }
        break;
    }

    case 4:
        printf("Operation aborted.\n");
        free(schedule);
        exit(0);
        break;

    default:
        printf("Invalid option.\n");
        break;
    }

    int var;
    printf("\nEnter the number 1 to return to schedule.\nEnter any other number to end the process\n \
           -->");
    scanf("%d", &var);
    if(var)
        goto loop;

    free(schedule);

    return 0;
}
