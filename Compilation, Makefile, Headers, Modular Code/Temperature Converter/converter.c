#include "converter.h"

float celsius_to_fahrenheit(float celsius){
    return (celsius * 1.8) + 32;
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) / 1.8;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return ((fahrenheit - 32) * 1.8) + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit(float kelvin){
    return (kelvin - 273.15) * 1.8 + 32;
}
