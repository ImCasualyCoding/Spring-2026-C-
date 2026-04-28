
/*************************************************************************
*****
COP 3275C assignment 9 PART 2 file I/O and vector practice
Brandon Valencia
4/27/26
Reading from a file, sorting vectors, and filtering values.
**************************************************************************
*****/
#include <iostream>
#include <vector>
#include <algorithm> 
#include <fstream>

using namespace std;

// Function Prototypes
void fillVector(ifstream& in, vector<double>& bitValues, int count);
void printVector(vector<double> bitValues);
void sortVector(vector<double> bitValues);
void countValues(vector<double> bitValues);
void calculateAverage(vector<double> greaterValues);

int main() {
    
    ifstream inFile("crypto.txt");
    if (!inFile) {
        cout << "Error: Could not open file. Please make sure 'crypto.txt' exists." << endl;
        return 1;
    }

    vector<double> myCryptoValues;
    int count;

    cout << "How many values would you like to read from the file? ";
    cin >> count;

    
    fillVector(inFile, myCryptoValues, count);
    inFile.close();

    
    cout << "\n--- Original Vector ---" << endl;
    printVector(myCryptoValues);

    
    cout << "\n--- Sorted Vector ---" << endl;
    sortVector(myCryptoValues);

    
    cout << "\n--- Filter and Average ---" << endl;
    countValues(myCryptoValues);

    return 0;
}

// ---------------------------------------------------------
// Function Implementations
// ---------------------------------------------------------

void fillVector(ifstream& in, vector<double>& bitValues, int count) {
    double number;
    for (int i = 0; i < count; i++) {
        // Read from file and check if the read was successful
        if (in >> number) {
            bitValues.push_back(number);
        } else {
            cout << "Reached end of file earlier than expected." << endl;
            break; 
        }
    }
}

void printVector(vector<double> bitValues) {
    // Note: bitValues is passed by value, so it's a copy
    for (size_t i = 0; i < bitValues.size(); i++) {
        cout << bitValues[i] << endl;
    }
}

void sortVector(vector<double> bitValues) {
    
    sort(bitValues.begin(), bitValues.end());
    
    
    printVector(bitValues); 
}

void countValues(vector<double> bitValues) {
    double threshold;
    cout << "Enter a value to filter by (find values greater than): ";
    cin >> threshold;

    vector<double> greaterValues;
    int count = 0;

    // Loop through and find values greater than the threshold
    for (size_t i = 0; i < bitValues.size(); i++) {
        if (bitValues[i] > threshold) {
            greaterValues.push_back(bitValues[i]);
            count++;
        }
    }

    // Print the results
    cout << "\nThere are " << count << " values greater than " << threshold << "." << endl;
    cout << "The new values are: " << endl;
    printVector(greaterValues);

    
    if (!greaterValues.empty()) {
        calculateAverage(greaterValues);
    } else {
        cout << "No values available to average." << endl;
    }
}

void calculateAverage(vector<double> greaterValues) {
    double sum = 0.0;
    
    for (size_t i = 0; i < greaterValues.size(); i++) {
        sum += greaterValues[i];
    }
    
    double average = sum / greaterValues.size();
    cout << "\nThe average of these new values is: " << average << endl;
}