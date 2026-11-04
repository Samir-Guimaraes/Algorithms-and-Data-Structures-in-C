/***
A program that stores a list of addresses in a binary file and then
allows the user to access any address directly by its position,
without reading the previous ones. Each address has a country, a
state, a city and a street (all strings). The program asks the user
how many addresses will be registered, writes all of them to the
binary file using fwrite, and then asks the user for the index of
an address to retrieve. Using fseek, the program moves the file
pointer directly to the byte offset of the requested record, reads
it with fread and displays it on the screen. After that, the program
uses rewind to go back to the beginning of the file and displays
every address in order. Focus on byte offsets, SEEK_SET, SEEK_CUR
and SEEK_END, and on correct error checking.
***/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char country[50];
    char state[50];
    char city[50];
    char street[50];
} Address;

int main(){

    int addressCount;

    /* ---------- READ HOW MANY ADDRESSES ---------- */
    printf("How many addresses do you want to register: ");
    if (scanf("%d", &addressCount) != 1 || addressCount <= 0) {
        printf("Invalid number of addresses.\n");
        return 1;
    }

    /* ---------- ALLOCATE ARRAY OF STRUCTS ---------- */
    Address *addresses = (Address *) malloc(addressCount * sizeof(Address));
    if (addresses == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* ---------- WRITE TO BINARY FILE ---------- */
    FILE *file = fopen("addresses.bin", "wb");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        free(addresses);
        return 1;
    }

    for (int i = 0; i < addressCount; i++) {
        printf("\nCountry of address %d: ", i + 1);
        scanf("%49s", addresses[i].country);
        printf("State of address %d: ", i + 1);
        scanf("%49s", addresses[i].state);
        printf("City of address %d: ", i + 1);
        scanf("%49s", addresses[i].city);
        printf("Street of address %d: ", i + 1);
        scanf("%49s", addresses[i].street);

        // ONE fwrite of the WHOLE struct per record
        if (fwrite(&addresses[i], sizeof(Address), 1, file) != 1) {
            printf("Error writing address %d.\n", i + 1);
        }
    }
    fclose(file);

    /* ---------- REOPEN FOR READING ---------- */
    file = fopen("addresses.bin", "rb");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        free(addresses);
        return 1;
    }

    /* ---------- STEP 1: ASK THE INDEX ---------- */
    int index;
    printf("\nWhich address index do you want to retrieve (0 to %d): ",
           addressCount - 1);
    if (scanf("%d", &index) != 1 || index < 0 || index >= addressCount) {
        printf("Invalid index.\n");
        fclose(file);
        free(addresses);
        return 1;
    }

    /* ---------- STEP 2: fseek TO THE BYTE OFFSET ---------- */
    // offset = index * sizeof(Address)
    // SEEK_SET means "count from the beginning of the file"
    long offset = (long) index * sizeof(Address);
    if (fseek(file, offset, SEEK_SET) != 0) {
        printf("Error seeking in the file.\n");
        fclose(file);
        free(addresses);
        return 1;
    }

    /* ---------- STEP 3: fread THE REQUESTED RECORD ---------- */
    Address target;                      // separate variable, type Address (NOT char[50])
    if (fread(&target, sizeof(Address), 1, file) != 1) {
        printf("Error reading the requested address.\n");
        fclose(file);
        free(addresses);
        return 1;
    }

    printf("\n----- Requested address (index %d) -----\n", index);
    printf("Country: %s\n", target.country);   // print ALL fields, not just one
    printf("State:   %s\n", target.state);
    printf("City:    %s\n", target.city);
    printf("Street:  %s\n", target.street);

    /* ---------- STEP 4: rewind AND DISPLAY ALL ---------- */
    rewind(file);                        // back to byte 0 (also clears EOF flag)

    printf("\n----- All addresses in the file -----\n");
    int i = 0;
    while (fread(&addresses[i], sizeof(Address), 1, file) == 1) {
        printf("[%d] %s | %s | %s | %s\n",
               i,
               addresses[i].country,
               addresses[i].state,
               addresses[i].city,
               addresses[i].street);
        i++;
    }

    fclose(file);
    free(addresses);
    return 0;
}
