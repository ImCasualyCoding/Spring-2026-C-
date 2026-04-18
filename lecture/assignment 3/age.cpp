#include "age.h"
#include <iostream>
#include <string>

using namespace std;

// Get name and year by reference
void getData(string &name, int &year) {
    cout << "Enter name: ";
    getline(cin >> ws, name); // ws consumes leading whitespace and newlines
    cout << "Enter birth year: ";
    cin >> year;
}

//  Assign and print generation based on year
void getGeneration(string name, int year, string &category) {
    if (year >= 2013) category = "Gen Alpha";
    else if (year >= 1997) category = "Gen Z";
    else if (year >= 1981) category = "Millennial";
    else if (year >= 1965) category = "Gen X";
    else category = "Baby Boomer or Older";

    cout << name << " belongs to: " << category << endl;
}

//  Calculate age at end of 2026
int calculateAge(string name, int year) {
    int age = 2026 - year;
    cout << "Calculating age for " << name << "..." << endl;
    return age;
}

// Return 1, 2, or 3 based on who is youngest
int findYoungest(int a1, int a2, int a3) {
    if (a1 <= a2 && a1 <= a3) return 1;
    if (a2 <= a1 && a2 <= a3) return 2;
    return 3;
}

//  Return 1, 2, or 3 based on who is oldest
int findOldest(int a1, int a2, int a3) {
    if (a1 >= a2 && a1 >= a3) return 1;
    if (a2 >= a1 && a2 >= a3) return 2;
    return 3;
}

//  Print youngest details
void printYoungest(string name, int age, int year, string category) {
    cout << "\n Youngest Person" << endl;
    cout << "Name: " << name << "  Age: " << age << "  Year: " << year << " Gen: " << category << endl;
}

//  Print oldest details
void printOldest(string name, int age, int year, string category) {
    cout << "\nOldest Person" << endl;
    cout << "Name: " << name << " Age: " << age << " Year: " << year << " Gen: " << category << endl;
}