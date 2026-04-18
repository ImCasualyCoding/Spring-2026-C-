/****SAMPLE PROGRAM
HEADER*******************************************************
Brandon Valencia 
Due Date:2/16/2026
Course: C0P3275C
Assignment: Assignment 3 FUNCTIONS separate compilation
Professor: Sorgente
Description: determins the generation of three users based, while compiling multiple files
program we processed....
*************************************************************/

#include <iostream>
#include <string>
#include "age.h"
#include "age.cpp"

using namespace std;

int main() {
    char choice;

    do {
        // Arrays or individual variables to store data for 3 people
        string names[3], categories[3];
        int years[3], ages[3];

        // Loop to gather data for people
        for (int i = 0; i < 3; i++) {
            cout << "\nData for Person " << (i + 1) << ":" << endl;
            getData(names[i], years[i]);
            getGeneration(names[i], years[i], categories[i]);
            ages[i] = calculateAge(names[i], years[i]);
        }

        // Determine who is youngest and oldest
        int youngIdx = findYoungest(ages[0], ages[1], ages[2]) - 1; 
        int oldIdx = findOldest(ages[0], ages[1], ages[2]) - 1;

        // Print results
        printYoungest(names[youngIdx], ages[youngIdx], years[youngIdx], categories[youngIdx]);
        printOldest(names[oldIdx], ages[oldIdx], years[oldIdx], categories[oldIdx]);

        cout << "\nWould you like to enter information for three more people? (Y/N): ";
        cin >> choice;
        
        
        cin.ignore(1000, '\n');

    } while (choice == 'Y' || choice == 'y');

    cout << "Adios!" << endl;
    return 0;
}