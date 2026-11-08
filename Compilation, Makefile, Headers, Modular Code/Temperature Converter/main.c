#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "converter.h"

int main()
{
    float temperature, converted_temperature;
    char temperature_unit, target_unit;
    char source_unit_lower, target_unit_lower;

    printf("Enter the current temperature: ");
    scanf("%f", &temperature);

    do {
        printf("Enter the temperature unit.\nC - Celsius\nK - Kelvin\nF - Fahrenheit\n-> ");
        scanf(" %c", &temperature_unit);
        source_unit_lower = tolower(temperature_unit);
    } while (source_unit_lower != 'c' && source_unit_lower != 'k' && source_unit_lower != 'f');

    do {
        printf("Select the unit you want to convert to.\nC - Celsius\nK - Kelvin\nF - Fahrenheit\n-> ");
        scanf(" %c", &target_unit);
        target_unit_lower = tolower(target_unit);
    } while (target_unit_lower != 'c' && target_unit_lower != 'k' && target_unit_lower != 'f');

    if (source_unit_lower == 'c') {
        if (target_unit_lower == 'k') {
            converted_temperature = celsius_to_kelvin(temperature);
            printf("%.2f degrees Celsius corresponds to %.2f Kelvin.\n", temperature, converted_temperature);
        } else if (target_unit_lower == 'f') {
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("%.2f degrees Celsius corresponds to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
        } else {
            printf("You selected the same unit!\n");
        }
    } else if (source_unit_lower == 'k') {
        if (target_unit_lower == 'c') {
            converted_temperature = kelvin_to_celsius(temperature);
            printf("%.2f Kelvin corresponds to %.2f degrees Celsius.\n", temperature, converted_temperature);
        } else if (target_unit_lower == 'f') {
            converted_temperature = kelvin_to_fahrenheit(temperature);
            printf("%.2f Kelvin corresponds to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
        } else {
            printf("You selected the same unit!\n");
        }
    } else if (source_unit_lower == 'f') {
        if (target_unit_lower == 'c') {
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("%.2f degrees Fahrenheit corresponds to %.2f degrees Celsius.\n", temperature, converted_temperature);
        } else if (target_unit_lower == 'k') {
            converted_temperature = fahrenheit_to_kelvin(temperature);
            printf("%.2f degrees Fahrenheit corresponds to %.2f Kelvin.\n", temperature, converted_temperature);
        } else {
            printf("You selected the same unit!\n");
        }
    }

    return 0;
}
