// functions.cpp
#include "functions.h" // Include the header file that contains the function declarations
#include <iostream> // For std::cout and std::cin

using namespace std;  // Using standard namespace for cout and cin

// Function definitions for the functions declared in functions.h
// 11/10/24 Recursive factorial function
int factorial(int n) {
    if (n < 0) return -1; // Error case for negative input
    if (n == 0 || n == 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}


// Function to convert celsius to fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Updated 11/10/24 Function to display the menu
void displayMenu() {
    cout << "Main Menu\n";
    cout << "1. Calculate Factorial (Recursive)\n";
    cout << "2. Celsius to Fahrenheit Conversion\n";
    cout << "3. Swap Two Integers\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// 11/10/24 New function using pointers to swap two integers
void swapIntegers(int* a, int* b) {
    int temp = *a; // Store the value of a in a temporary variable
    *a = *b; // Assign the value of b to a
    *b = temp; // Assign the value of the temporary variable to b
}