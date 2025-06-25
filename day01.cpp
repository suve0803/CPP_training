#include <iostream>
#include <vector>
using namespace std;

int fifthLastFootprint(const vector<int>& trail) {
    // Queue to store the last 5 footprints
    int window[5] = {0};  // Fixed size array
    int count = 0;        // To count total steps

    for (int i = 0; i < trail.size(); i++) {
        window[count % 5] = trail[i];  // Circularly store footprints
        count++;
    }

    // If fewer than 5 steps, return -1
    if (count < 5) {
        return -1;
    }

    // Return the 5th last element in the window
    return window[count % 5];
}

int main() {
    vector<int> trail = {1, 2, 3, 4, 5, 6, 7};
    cout << "Fifth-last footprint: " << fifthLastFootprint(trail) << endl;
    return 0;
}



#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string isBridgeBalanced(const vector<int>& vehicleWeights) {
    stack<int> bridge;  // Simulate vehicles on the bridge

    for (int weight : vehicleWeights) {
        // Check if the bridge is currently imbalanced
        while (!bridge.empty() && bridge.top() < weight) {
            bridge.pop();  // Simulate lighter vehicle exiting
        }

        // Push the current vehicle onto the bridge
        bridge.push(weight);
    }

    return "Balanced";  // If no violations occur
}

int main() {
    vector<int> weights = {2, 3, 5, 4, 6};
    cout << "Bridge status: " << isBridgeBalanced(weights) << endl;
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int maxShadowShiftStartIndex(const vector<int>& shadowMovements) {
    if (shadowMovements.size() < 3) {
        return -1;  // Not enough hours for a 3-hour window
    }

    int maxSum = INT_MIN;  // Maximum cumulative movement
    int currentSum = 0;    // Current 3-hour window sum
    int startIndex = 0;    // Start index of the maximum window

    // Calculate the first 3-hour window sum
    for (int i = 0; i < 3; i++) {
        currentSum += shadowMovements[i];
    }
    maxSum = currentSum;

    // Slide the window through the list
    for (int i = 3; i < shadowMovements.size(); i++) {
        currentSum = currentSum - shadowMovements[i - 3] + shadowMovements[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            startIndex = i - 2;
        }
    }

    return startIndex;
}

int main() {
    vector<int> shadowMovements = {2, -1, 3, 4, -2, 5};
    cout << "Starting index of max shadow shift: " << maxShadowShiftStartIndex(shadowMovements) << endl;
    return 0;
}



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
