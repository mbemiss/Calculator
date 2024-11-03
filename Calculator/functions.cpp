// functions.cpp
#include "functions.h" // Include the header file that contains the function declarations
#include <iostream> // For std::cout and std::cin

using namespace std;  // Using standard namespace for cout and cin

// Function definitions for the functions declared in functions.h
int factorial(int n) {
    if (n < 0) return -1; // Error case for negative input
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to convert celsius to fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to display the menu
void displayMenu() {
    cout << "Main Menu\n";
    cout << "1. Calculate Factorial\n";
    cout << "2. Celsius to Fahrenheit Conversion\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}