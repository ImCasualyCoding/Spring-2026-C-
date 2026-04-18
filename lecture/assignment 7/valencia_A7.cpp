/*************************************************************************
*****
COP 3275C assignment 7 character arrays and strings in C++
Brandon Valencia Ramirez
4/6/26
This program transforms user input into reversed, uppercase, NATO phonetic, and ASCII average formats.
**************************************************************************
*****/

#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse and std::transform
#include <cctype>    // Required for toupper()

using namespace std;

// --- Function Prototypes ---
string reverseString(string str);
string uppercaseString(string str);
string getNatoWord(char c);
string* createNatoArray(const string& str);
int* createAsciiArray(const string& str);
double calculateAverage(const int* arr, int size);
void processString(const string& inputStr);

int main() {
    string firstName;
    
    // Get the user's first name
    cout << "Enter your first name: ";
    cin >> firstName;
    
    // Process the first name using the generalized function
    cout << "\n--- Processing First Name ---" << endl;
    processString(firstName);
    
    char choice;
    //  Allow the user to continue entering phrases
    do {
        string phrase;
        cout << "\nEnter a short phrase or title: ";
        
        // Clear the newline character left in the buffer by previous cin
        cin.ignore(); 
        // Use getline to allow spaces in the phrase
        getline(cin, phrase);
        
        //  Use the exact same function as the first name to process the phrase
        cout << "\n--- Processing Phrase ---" << endl;
        processString(phrase);
        
        // Ask if the user wants to continue
        cout << "\nDo you want to enter another phrase? (y/n): ";
        cin >> choice;
        
    } while (tolower(choice) == 'y'); // Loop continues as long as user enters 'y'
    
    cout << "Program ended. Goodbye!" << endl;
    
    return 0;
}

// --- Function Definitions ---

// Uses the <algorithm> library to reverse a string
string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

// Uses the <algorithm> library to convert a string to uppercase
string uppercaseString(string str) {
    string upper = str;
    // std::transform applies the ::toupper function to every character
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

// Helper function to return the NATO phonetic word for a given character
string getNatoWord(char c) {
    c = toupper(c); // Convert to uppercase for easy matching
    switch(c) {
        case 'A': return "Alpha";   case 'B': return "Bravo";   case 'C': return "Charlie";
        case 'D': return "Delta";   case 'E': return "Echo";    case 'F': return "Foxtrot";
        case 'G': return "Golf";    case 'H': return "Hotel";   case 'I': return "India";
        case 'J': return "Juliett"; case 'K': return "Kilo";    case 'L': return "Lima";
        case 'M': return "Mike";    case 'N': return "November";case 'O': return "Oscar";
        case 'P': return "Papa";    case 'Q': return "Quebec";  case 'R': return "Romeo";
        case 'S': return "Sierra";  case 'T': return "Tango";   case 'U': return "Uniform";
        case 'V': return "Victor";  case 'W': return "Whiskey"; case 'X': return "X-ray";
        case 'Y': return "Yankee";  case 'Z': return "Zulu";
        case ' ': return "(space)"; // Handle spaces in phrases
        default: return "(unknown)";
    }
}

// Creates a dynamically allocated string array containing NATO words
string* createNatoArray(const string& str) {
    // Dynamically allocate memory based on the string length
    string* natoArray = new string[str.length()];
    for (size_t i = 0; i < str.length(); i++) {
        natoArray[i] = getNatoWord(str[i]);
    }
    return natoArray; // Return the pointer to the dynamic array
}

// Creates a dynamically allocated integer array containing ASCII values
int* createAsciiArray(const string& str) {
    int* asciiArray = new int[str.length()];
    for (size_t i = 0; i < str.length(); i++) {
        asciiArray[i] = static_cast<int>(str[i]); // Cast character to its ASCII integer value
    }
    return asciiArray;
}

// Calculates the mathematical average of an integer array
double calculateAverage(const int* arr, int size) {
    if (size == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

// Main processing function used for both the first name and the phrase
void processString(const string& inputStr) {
    cout << "Original String: " << inputStr << endl;
    
    // Create and display reversed string
    string revStr = reverseString(inputStr);
    cout << "Reversed String: " << revStr << endl;
    
    // Create and display uppercase string
    string upStr = uppercaseString(inputStr);
    cout << "Uppercase String: " << upStr << endl;
    
    // --- Dynamic String Array (NATO Phonetic) ---
    string* natoArr = createNatoArray(inputStr);
    cout << "NATO Phonetic: ";
    for (size_t i = 0; i < inputStr.length(); i++) {
        cout << natoArr[i] << " ";
    }
    cout << endl;
    delete[] natoArr; // Free dynamic memory to prevent memory leaks
    
    // --- Dynamic Integer Array (Original ASCII) ---
    int* asciiOrig = createAsciiArray(inputStr);
    cout << "Original ASCII Values: ";
    for (size_t i = 0; i < inputStr.length(); i++) {
        cout << asciiOrig[i] << " ";
    }
    cout << "\nOriginal ASCII Average: " << calculateAverage(asciiOrig, inputStr.length()) << endl;
    delete[] asciiOrig; // Free dynamic memory
    
    // --- Dynamic Integer Array (Uppercase ASCII) ---
    int* asciiUp = createAsciiArray(upStr);
    cout << "Uppercase ASCII Values: ";
    for (size_t i = 0; i < upStr.length(); i++) {
        cout << asciiUp[i] << " ";
    }
    cout << "\nUppercase ASCII Average: " << calculateAverage(asciiUp, upStr.length()) << endl;
    delete[] asciiUp; // Free dynamic memory
}