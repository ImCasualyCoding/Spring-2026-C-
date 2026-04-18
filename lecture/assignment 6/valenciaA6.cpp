/*************************************************************************
*****
COP 3275C assignment 6 arrays
Valenci Brandon
3/31/2026
This program dynamically allocates memory to read a specific amount of data
from a file, filters those values into a secondary array based on user input,
and then calculates the average of those filtered results using modular functions.
**************************************************************************
*****/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// --- Function Prototypes ---
void loadData(double* arr, int size, ifstream& inputFile);
void printArray(double* arr, int size);
void searchAndFilter(double* originalArr, int originalSize);
void printAverage(double* arr, int size);

int main() {
    const int MAX_FILE_SIZE = 75;
    string fileName = "valenciaA6.txt";
    int userSize;

    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    // Input Validation Loop
    cout << "How many values would you like to read? (Max " << MAX_FILE_SIZE << "): ";
    cin >> userSize;

    while (userSize <= 0 || userSize > MAX_FILE_SIZE) {
        cout << "Invalid input. Please enter a number between 1 and " << MAX_FILE_SIZE << ": ";
        cin >> userSize;
    }

    // Dynamic Memory Allocation
    double* dataArray = new double[userSize];

    // Function Calls
    loadData(dataArray, userSize, inputFile);
    
    cout << "\n--- All Loaded Values ---" << endl;
    printArray(dataArray, userSize);

    searchAndFilter(dataArray, userSize);

    // Clean up main array
    delete[] dataArray;
    inputFile.close();

    return 0;
}

// --- Function Definitions ---

// Function 1: Load data from file into the dynamic array
void loadData(double* arr, int size, ifstream& inputFile) {
    for (int i = 0; i < size; i++) {
        if (!(inputFile >> arr[i])) {
            break; // Stop if file ends unexpectedly
        }
    }
}

// Function 2: Print array elements in a column
void printArray(double* arr, int size) {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

// Function 3: Search, count, and store values greater than input
void searchAndFilter(double* originalArr, int originalSize) {
    double threshold;
    int count = 0;

    cout << "\nEnter a value to search for 'greater than' matches: ";
    cin >> threshold;

    // First pass: Count how many elements match the criteria
    for (int i = 0; i < originalSize; i++) {
        if (originalArr[i] > threshold) {
            count++;
        }
    }

    if (count > 0) {
        // Create second dynamic array for filtered values
        double* filteredArr = new double[count];
        int index = 0;

        // Second pass: Store the values
        for (int i = 0; i < originalSize; i++) {
            if (originalArr[i] > threshold) {
                filteredArr[index] = originalArr[i];
                index++;
            }
        }

        cout << "\nFound " << count << " values greater than " << threshold << ":" << endl;
        
        // Use Function 2 to print the filtered array
        printArray(filteredArr, count);

        // Use Function 4 to print the average of these filtered values
        printAverage(filteredArr, count);

        // Clean up second array
        delete[] filteredArr;
    } else {
        cout << "No values found greater than " << threshold << "." << endl;
    }
}

// Function 4: Calculate and print the average
void printAverage(double* arr, int size) {
    if (size == 0) return;

    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    double average = sum / size;
    cout << "\nThe average of these values is: " << average << endl;
}