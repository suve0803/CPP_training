#include <iostream>
#include <sstream> // For stringstream
using namespace std;

// Utility function to convert string to double
double stringToDouble(const string& str) {
    stringstream ss(str);
    double value;
    ss >> value;
    return value;
}

// Function to handle triangle area calculation
void calculateTriangle(int argc, char* argv[]) {
    double base, height;
    if (argc == 4) {
        base = stringToDouble(argv[2]);
        height = stringToDouble(argv[3]);
    } else {
        cout << "Enter base and height of the triangle: ";
        cin >> base >> height;
    }
    cout << "Area of the triangle: " << 0.5 * base * height << endl;
}

// Function to handle rectangle area calculation
void calculateRectangle(int argc, char* argv[]) {
    double length, width;
    if (argc == 4) {
        length = stringToDouble(argv[2]);
        width = stringToDouble(argv[3]);
    } else {
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
    }
    cout << "Area of the rectangle: " << length * width << endl;
}

// Function to handle square area calculation
void calculateSquare(int argc, char* argv[]) {
    double side;
    if (argc == 3) {
        side = stringToDouble(argv[2]);
    } else {
        cout << "Enter the side of the square: ";
        cin >> side;
    }
    cout << "Area of the square: " << side * side << endl;
}

// Function to handle circle area calculation
void calculateCircle(int argc, char* argv[]) {
    const double PI = 3.14159;
    double radius;
    if (argc == 3) {
        radius = stringToDouble(argv[2]);
    } else {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }
    cout << "Area of the circle: " << PI * radius * radius << endl;
}

// Function to display the menu and call appropriate shape functions
void displayMenu() {
    int choice;
    cout << "Select a shape to calculate the area:\n";
    cout << "1. Triangle\n2. Rectangle\n3. Square\n4. Circle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            calculateTriangle(0, nullptr); // Pass dummy arguments for menu mode
            break;
        case 2:
            calculateRectangle(0, nullptr); // Pass dummy arguments for menu mode
            break;
        case 3:
            calculateSquare(0, nullptr); // Pass dummy arguments for menu mode
            break;
        case 4:
            calculateCircle(0, nullptr); // Pass dummy arguments for menu mode
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        string shape = argv[1];
        if (shape == "triangle") {
            calculateTriangle(argc, argv);
        } else if (shape == "rectangle") {
            calculateRectangle(argc, argv);
        } else if (shape == "square") {
            calculateSquare(argc, argv);
        } else if (shape == "circle") {
            calculateCircle(argc, argv);
        } else {
            cout << "Invalid shape or insufficient arguments!" << endl;
            cout << "Usage: ./program <shape> <parameters...>" << endl;
        }
    } else {
        displayMenu(); // Run menu-based input mode
    }
    return 0;
