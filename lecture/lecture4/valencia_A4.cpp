/****SAMPLE PROGRAM
HEADER*******************************************************
Brandon valencia 
Due Date: 2/23/26
Course: C0P3275C
Assignment: Assignment 4
Professor: Sorgente
Description: Takes input files assigning the variables according to the ones in the struct
Then later displays the informationjom
**************************************************************************
*****/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Creating my struct with dedicated variables
struct VideoGame {
    int id; 
    string title;
    string pov;
    double developerCost;
    double retailPrice;
};

// function prototypes 
void fillGame(VideoGame& game, ifstream& inFile);
void printGame(const VideoGame& game);


int main() {
    // Open the input file
    ifstream inFile("input.txt");

    // making sure the file opened sucessfully 
    if (!inFile) {
        cout << "Error: Cannot open the given file" << endl;
        return 1;
    }

    //  declaring my game objects
    VideoGame game1, game2, game3;

    // fill the objects from the file
    fillGame(game1, inFile);
    fillGame(game2, inFile);
    fillGame(game3, inFile);

    // Close the file stream once reading is done
    inFile.close();

    // Print the objects to the screen
    printGame(game1);
    printGame(game2);
    printGame(game3);

    cout << "...Program finished with exit code 0" << endl;
    cout << "Press ENTER to exit console.";
    
    // Clear input buffer and wait for user to press ENTER
    cin.ignore();
    cin.get(); 

    return 0;
}

// Function to fill the member variables from a file
// Takes a reference to the object and a reference to the input stream
void fillGame(VideoGame& game, ifstream& inFile) {
    inFile >> game.id >> game.title >> game.pov >> game.developerCost >> game.retailPrice;
}

// Function to print the information for one object
// Takes a const reference to prevent accidental modification of the object
void printGame(const VideoGame& game) {
    cout << "------Printing Game info-----" << endl;
    cout << "ID : " << game.id << endl;
    cout << "Game title: " << game.title << endl;
    cout << "Game genre: " << game.pov << endl;
    
    // Formatting math/currency to two decimal places
    cout << fixed << setprecision(2);
    cout << "Developer cost: $" << game.developerCost << endl;
    cout << "Retail price: $" << game.retailPrice << endl;
}
