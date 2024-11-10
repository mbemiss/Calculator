// main.cpp
// Updated 11/10/2024.  Estimated time to complete: 60 minutes
#include <iostream> // Include input/output stream library
#include <cassert> // Include assert library for testing
#include <sstream> // Include stringstream library for string conversion
#include <limits> // Include limits library for numeric limits
#include "functions.h" // Include header file with function declarations

using namespace std;  // Using standard namespace for cout and cin to avoid writing std:: prefix each time
void runTests(); // Function to run inline tests for TDD

// Function to check if input is valid (contains only digits)
bool isValidInput(const string& input) {
    return !input.empty() && input.find_first_not_of("0123456789") == string::npos; // Check if input is not empty and contains only digits
}

// Function to get valid integer input
int getValidIntegerInput(const string& prompt) {
    string input;   // Variable to store user input
    int value;   // Variable to store integer value
    while (true) { // Loop until valid input is entered
        cout << prompt; // Display prompt message
        cin >> input; // Get input from user
        
        if (isValidInput(input)) { // Check if input is valid
            stringstream ss(input); // Convert string to integer, stringstream is used to convert string to integer
            if (ss >> value) { // Check if conversion was successful
                return value; // Return integer value
            }
        }
        cout << "Invalid input. Please enter digits only.\n";   // Display error message
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input and clear buffer
    }
}

// Main function to display menu and call functions
// Updated 11/10/2024 this includes the updated swapIntegers function and the getValidIntegerInput function
int main() {
    runTests();
    int choice;

    // Display menu and get user choice
    do {
        displayMenu(); // Display menu
        choice = getValidIntegerInput("Choose an option: "); // Get user choice

        switch (choice) {   // Switch case based on user choice
        case 1: {  // Case 1 to calculate factorial
            int number = getValidIntegerInput("Enter a number to calculate factorial: ");   // Get number from user
            int result = factorial(number); // Calculate factorial
            if (result == -1) { // Check if error occurred
                cout << "Error: Factorial of negative numbers is undefined.\n";     // Display error message
            }
            else {  
                cout << "Factorial of " << number << " is " << result << "\n\n";    // Display result
            }
            break;
        }
        case 2: {  // Case 2 to convert Celsius to Fahrenheit
            double celsius = getValidIntegerInput("Enter temperature in Celsius: "); // Get temperature in Celsius
            double fahrenheit = celsiusToFahrenheit(celsius); // Convert Celsius to Fahrenheit
            cout << celsius << " degrees C is " << fahrenheit << " degrees F\n\n"; // Display result
            break;
        }
        case 3: {  // Case 3 to swap two integers
            int a = getValidIntegerInput("Enter first integer to swap: ");  // Get first integer
            int b = getValidIntegerInput("Enter second integer to swap: "); // Get second integer
            cout << "Before swap: a = " << a << ", b = " << b << "\n";  // Display integers before swap
            swapIntegers(&a, &b); // Swap integers
            cout << "After swap: a = " << a << ", b = " << b << "\n\n";     // Display integers after swap
            break;
        }
        case 4: // Case 4 to exit program
            cout << "Exiting program.\n";   // Display exit message
            break;
        default:	// Default case for invalid choice  
            cout << "Invalid choice. Please try again.\n";  
        }
    } while (choice != 4);  // Loop until user chooses to exit program

    return 0;   // Return 0 to indicate successful completion
}

// Function to run inline tests for TDD
// Tests are run automatically when the program is executed
// Updated 11/10/2024
void runTests() {
    // Testing factorial function
    assert(factorial(5) == 120); // Test with positive number
    assert(factorial(0) == 1); // Test with 0
    assert(factorial(-3) == -1); // Test for error case

    // Testing Celsius to Fahrenheit conversion function
    assert(celsiusToFahrenheit(0) == 32.0); // Test with freezing point of water
    assert(celsiusToFahrenheit(100) == 212.0); // Test with boiling point of water

    // 11/10/24 Testing swapIntegers function, updated for pointers
    int x = 5, y = 10; // Test with two integers
    swapIntegers(&x, &y); // Pass addresses of x and y
    assert(x == 10 && y == 5); // Check if x and y are swapped

    cout << "All tests passed!\n"; // Display message if all tests pass
}
