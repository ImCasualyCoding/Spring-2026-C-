/****SAMPLE PROGRAM
HEADER*******************************************************
STUDENT NAME
Due Date:
Course: C0P3275C
Assignment: Assignment 5
Professor: Sorgente
Description: bird class with constructors, mutators, accessors, and non member functions to fill and display data
**************************************************************************
*****/
#include <iomanip> 
#include <iostream> 
#include <string> 
using namespace std;

class bird {
    int id;
    string name;
    string color;
    double weight;
    bool canFly;
public:
    //Constructor

    bird(); //defautl constructor
    bird(int nId, string nName, string nColor, double nWeight, bool nCanFly);// Explicit Value


    //mutator functions
    void setId(int nId);
    void setName(string nName); 
    void setColor(string nColor);
    void setWeight(double nWeight);
    void setCanFly(bool nCanFly);

    //accessor functions
    int getId();
    string getName();
    string getColor();
    double getWeight();
    bool getCanFly();


};

// member function definitions

//default constructor
bird::bird() {
    id = 0;
    name = "unknown";
    color = "unknown";
    weight = 0.0;
    canFly = 0;
}


//explicit value constructor
bird::bird(int nId, string nName, string nColor, double nWeight, bool nCanFly) {
    id = nId;
    name = nName;
    color = nColor;
    weight = nWeight;
    canFly = nCanFly;
}


// mutator functions
void bird::setId(int nid) {
    id = nid;
}
void bird::setName(string nname) {
    name = nname;
}
void bird::setColor(string ncolor) {
    color = ncolor;
}
void bird::setWeight(double nweight) {
    weight = nweight;
}
void bird::setCanFly(bool ncanFly) {
    canFly = ncanFly;
}


//accessor functions
int bird::getId() {
    return id;
}
string bird::getName() {
    return name;
}
string bird::getColor() {
    return color;
}
double bird::getWeight() {
    return weight;
}
bool bird::getCanFly() {
    return canFly;
}

// non member function prototypes
void fillBirdData(bird &b);
void displayBirdData(bird &b);


int main(){

    //explicit value constructor
    bird b1(1, "Sparrow", "Brown", 0.02, true);

    bird b2; // default constructor

    // objects filled by user
    bird b3; 
    bird b4;

    cout << "--- Enter Data for bird 3 ---" << endl;
    fillBirdData(b3);
    cout << "\n--- Enter Data for bird 4 ---" << endl;
    fillBirdData(b4);

    // Printing all objects
    cout << "\n==========================================" << endl;
    cout << "REPORTING ALL BIRD OBJECTS" << endl;
    cout << "==========================================" << endl;
    
    cout << "Object 1 (Explicit):" << endl;
    displayBirdData(b1);
    
    cout << "\nObject 2 (Default):" << endl;
    displayBirdData(b2);
    
    cout << "\nObject 3 (User Input):" << endl;
    displayBirdData(b3);
    
    cout << "\nObject 4 (User Input):" << endl;
    displayBirdData(b4);


return 0;
}

void fillBirdData(bird &b) {
    int tempId;
    string tempName, tempColor;
    double tempWeight;
    int tempFlyInput; 

    cout << "Enter ID: ";
    cin >> tempId;

    cout << "Enter Name (use_underscores): ";
    cin >> tempName;

    cout << "Enter Color: ";
    cin >> tempColor;

    cout << "Enter Weight (in kg): ";
    cin >> tempWeight;

    cout << "Can it fly? (1 for Yes, 0 for No): ";
    cin >> tempFlyInput; 

    // Use mutators to update the object
    b.setId(tempId);
    b.setName(tempName);
    b.setColor(tempColor);
    b.setWeight(tempWeight);
    
    
    b.setCanFly(tempFlyInput);
}

void displayBirdData(bird &b) {
    cout << fixed << setprecision(2); 
    cout << "ID: " << b.getId() << endl;
    cout << "Name: " << b.getName() << endl;
    cout << "Color: " << b.getColor() << endl;
    cout << "Weight: " << b.getWeight() << " kg" << endl;
    cout << "Can Fly: " << (b.getCanFly() ? "Yes" : "No") << endl;
}