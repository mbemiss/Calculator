// main.cpp
#include <iostream>
#include <cassert>
#include "functions.h"

using namespace std;  // Using standard namespace for cout and cin
void runTests(); // Function to run inline tests for TDD

// Main function to display menu and call functions
int main() {
    runTests(); // Call tests first for TDD
    int choice;

    // Display menu and get user choice
    do {
        displayMenu();
        cin >> choice;

        // Call functions based on user choice
        if (choice == 1) {
            int number;
            cout << "Enter a number to calculate factorial: ";
            cin >> number;
            int result = factorial(number);
            if (result == -1) {
                cout << "Error: Factorial of negative numbers is undefined.\n";
            }
            else {
                cout << "Factorial of " << number << " is " << result << "\n\n";
            }
        }
        // Celsius to Fahrenheit conversion
        else if (choice == 2) {
            double celsius;
            cout << "Enter temperature in Celsius: ";
            cin >> celsius;
            double fahrenheit = celsiusToFahrenheit(celsius);
            cout << celsius << " degrees C is " << fahrenheit << " degrees F\n\n";
        }
    } while (choice != 3); // Exit when user chooses 3

    cout << "Exiting program.\n";
    return 0;
}

// Function to run inline tests for TDD
// Tests are run automatically when the program is executed
void runTests() {
    // Testing factorial function
    assert(factorial(5) == 120);
    assert(factorial(0) == 1);
    assert(factorial(-3) == -1); // Test for error case

    // Testing Celsius to Fahrenheit conversion function
    assert(celsiusToFahrenheit(0) == 32.0);
    assert(celsiusToFahrenheit(100) == 212.0);

    cout << "All tests passed!\n";
}
