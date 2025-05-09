#include <iostream>
using namespace std;

// Function to convert Binary to Decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;

    while (binary > 0) {
        int lastDigit = binary % 10; // Extract the last digit
        decimal += lastDigit * base; // Add to the decimal value
        base *= 2;                   // Increment the base (2^n)
        binary /= 10;                // Remove the last digit
    }

    return decimal;
}

// Function to convert Decimal to Binary
int decimalToBinary(int decimal) {
    int binary = 0, base = 1;

    while (decimal > 0) {
        int remainder = decimal % 2; // Find remainder (binary digit)
        binary += remainder * base; // Add to the binary value
        base *= 10;                 // Increment base (10^n for binary)
        decimal /= 2;               // Update the decimal number
    }

    return binary;
}

// Function to convert Octal to Decimal
int octalToDecimal(int octal) {
    int decimal = 0, base = 1;

    while (octal > 0) {
        int lastDigit = octal % 10; // Extract the last digit
        decimal += lastDigit * base; // Add to the decimal value
        base *= 8;                   // Increment the base (8^n)
        octal /= 10;                 // Remove the last digit
    }

    return decimal;
}

// Function to convert Decimal to Octal
int decimalToOctal(int decimal) {
    int octal = 0, base = 1;

    while (decimal > 0) {
        int remainder = decimal % 8; // Find remainder (octal digit)
        octal += remainder * base;  // Add to the octal value
        base *= 10;                 // Increment base (10^n for octal)
        decimal /= 8;               // Update the decimal number
    }

    return octal;
}

int main() {
    int choice, number;

    cout << "Conversion Menu:\n";
    cout << "1. Binary to Decimal\n";
    cout << "2. Decimal to Binary\n";
    cout << "3. Octal to Decimal\n";
    cout << "4. Decimal to Octal\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "Enter the number: ";
    cin >> number;

    switch (choice) {
        case 1:
            cout << "Binary to Decimal: " << binaryToDecimal(number) << endl;
            break;
        case 2:
            cout << "Decimal to Binary: " << decimalToBinary(number) << endl;
            break;
        case 3:
            cout << "Octal to Decimal: " << octalToDecimal(number) << endl;
            break;
        case 4:
            cout << "Decimal to Octal: " << decimalToOctal(number) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
