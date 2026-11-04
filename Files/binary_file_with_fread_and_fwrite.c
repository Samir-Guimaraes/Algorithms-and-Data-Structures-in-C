/***
A program that stores a list of products in a binary file and reads
them back. Each product has a name (string), an ID (integer) and a
price (float). The program asks the user how many products will be
registered, writes all of them to the binary file using fwrite, and
then reopens the same file in read mode to display every product on
the screen using fread. Focus on correct binary file handling,
struct usage and error checking.
***/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    float price;
} Product;

int main(){

    FILE *file;
    int productCount;

    printf("How many products do you want to register: ");
    if (scanf("%d", &productCount) != 1 || productCount <= 0) {
        printf("Invalid number of products.\n");
        return 1;
    }

    Product *products = (Product *) malloc(productCount * sizeof(Product));
    if (products == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* ---------- WRITE ---------- */
    file = fopen("products.bin", "wb");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        free(products);
        return 1;
    }

    for (int i = 0; i < productCount; i++) {
        printf("\nProduct name: ");
        scanf(" %49s", products[i].name);          // space before % skips leftover \n
        printf("Product ID: ");
        scanf("%d", &products[i].id);
        printf("Product price: ");
        scanf("%f", &products[i].price);

        if (fwrite(&products[i], sizeof(Product), 1, file) != 1) {
            printf("Error writing product %d.\n", i + 1);
        }
    }
    fclose(file);

    /* ---------- READ ---------- */
    file = fopen("products.bin", "rb");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        free(products);
        return 1;
    }

    printf("\n----- Products stored in the binary file -----\n");
    int index = 0;
    while (fread(&products[index], sizeof(Product), 1, file) == 1) {
        printf("Name: %s | ID: %d | Price: %.2f\n",
               products[index].name,
               products[index].id,
               products[index].price);
        index++;
    }
    fclose(file);

    free(products);
    return 0;
}
