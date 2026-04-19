/**************************************************************
Name: Brandon Valencia Ramriez 
Date:4/18/2026
Course: COP3275C
Assignment: Program 8
Description: This C++ program is a menu-driven inventory system
that manages a static array of product objects to demonstrate
object-oriented programming concepts like member functions and 
operator overloading using friend functions
**************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// ============================================================================
// 1. DECLARATION: Class definition, private members, and prototypes
// ============================================================================
class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructors
    Product();
    Product(string n, double p, int q);

    // Class member display function to display ONE object
    void displayObject() const;

    // Class member function implementation feature
    void applyDiscount(double percent);

    // Friend function prototypes (Operator Overloading)
    // Overloading relational operator (<) to compare prices
    friend bool operator<(const Product& left, const Product& right);
    
    friend Product operator+(const Product& left, const Product& right);
};

// ============================================================================
// 2. MEMBER FUNCTION IMPLEMENTATION 
// ============================================================================

Product::Product() {
    name = "Empty";
    price = 0.0;
    quantity = 0;
}

Product::Product(string n, double p, int q) {
    name = n;
    price = p;
    quantity = q;
}

void Product::displayObject() const {
    cout << left << setw(15) << name 
         << "Price: $" << fixed << setprecision(2) << setw(8) << price 
         << "Quantity: " << quantity << endl;
}

// Member function feature: Applies a percentage discount to the price
void Product::applyDiscount(double percent) {
    if (percent > 0 && percent <= 100) {
        price = price - (price * (percent / 100.0));
    }
}

// ============================================================================
// 3. NON-MEMBER FUNCTION PROTOTYPES
// ============================================================================
void displayMenu();
void loadFromFile(Product list[], int& count);
void addObject(Product list[], int& count);
void displayList(const Product list[], int count);
void demoRelational(const Product list[], int count);
void demoArithmetic(const Product list[], int count);
void demoMemberFeature(Product list[], int count);

// ============================================================================
// 4. THE MAIN FUNCTION (Driver)
// ============================================================================
int main() {
    Product inventory[50]; 
    
    int productCount = 0;  

    loadFromFile(inventory, productCount);

    int choice = 0;

    // Menu Driver
    while (choice != 6) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addObject(inventory, productCount);
                break;
            case 2:
                displayList(inventory, productCount);
                break;
            case 3:
                demoRelational(inventory, productCount);
                break;
            case 4:
                demoArithmetic(inventory, productCount);
                break;
            case 5:
                demoMemberFeature(inventory, productCount);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

// ============================================================================
// 5. NON-MEMBER FUNCTION DEFINITIONS 
// ============================================================================

// --- Friend Function Definitions ---

// Overload < operator to compare prices between two products
bool operator<(const Product& left, const Product& right) {
    return left.price < right.price;
}

// Overload + operator to add two objects. 
Product operator+(const Product& left, const Product& right) {
    string combinedName = left.name + " & " + right.name;
    double combinedPrice = left.price + right.price;
    int combinedQuantity = left.quantity + right.quantity;
    
    return Product(combinedName, combinedPrice, combinedQuantity);
}

// --- Regular Non-Member Function Definitions ---

// Displays the 6 menu options
void displayMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Add an object to the list\n";
    cout << "2. Display the list\n";
    cout << "3. Compare two objects (Friend Function < overload)\n";
    cout << "4. Combine two objects (Friend Function + overload)\n";
    cout << "5. Apply a discount (Member function feature)\n";
    cout << "6. Quit\n";
    cout << "Enter your choice: ";
}

// Loads initial objects from a .txt file starting at index 0
void loadFromFile(Product list[], int& count) {
    ifstream inFile("input.txt");
    string n;
    double p;
    int q;

    if (!inFile) {
        cout << "Warning: input.txt not found. Starting with an empty list.\n";
        return;
    }

    // Read until EOF or array limit is reached
    while (count < 50 && inFile >> n >> p >> q) {
        list[count] = Product(n, p, q);
        count++;
    }
    
    cout << "Successfully loaded " << count << " objects from file.\n";
    inFile.close();
}

// Adds an object to the array tracking the count
void addObject(Product list[], int& count) {
    if (count >= 50) {
        cout << "Error: The list is full (50 objects max).\n";
        return;
    }

    string n;
    double p;
    int q;

    // Assuming user enters correct data in correct order
    cout << "Enter Product Name: ";
    cin >> n;
    cout << "Enter Product Price: ";
    cin >> p;
    cout << "Enter Product Quantity: ";
    cin >> q;

    list[count] = Product(n, p, q);
    count++;
    cout << "Product added successfully!\n";
}

// Displays all stored objects by iterating and calling the member display function
void displayList(const Product list[], int count) {
    if (count == 0) {
        cout << "The list is currently empty.\n";
        return;
    }

    cout << "\n--- Current Inventory List ---\n";
    for (int i = 0; i < count; i++) {
        cout << "[" << i << "] ";
        list[i].displayObject();
    }
    cout << "------------------------------\n";
}

// Demonstrates the friend function relational operator (<)
void demoRelational(const Product list[], int count) {
    if (count < 2) {
        cout << "You need at least 2 objects to compare!\n";
        return;
    }
    
    int index1, index2;
    cout << "Enter the two indices of the objects to compare (0 to " << count - 1 << "): ";
    cin >> index1 >> index2;

    cout << "\nComparing Prices...\n";
    list[index1].displayObject();
    list[index2].displayObject();

    if (list[index1] < list[index2]) {
        cout << "Result: The first item is cheaper than the second item.\n";
    } else {
        cout << "Result: The first item is NOT cheaper than the second item.\n";
    }
}

// Demonstrates the friend function arithmetic operator (+)
void demoArithmetic(const Product list[], int count) {
    if (count < 2) {
        cout << "You need at least 2 objects to combine!\n";
        return;
    }

    int index1, index2;
    cout << "Enter the two indices of the objects to combine (0 to " << count - 1 << "): ";
    cin >> index1 >> index2;

    // Using the overloaded + operator to create a new bundled object
    Product bundled = list[index1] + list[index2];

    cout << "\nCreating a bundled product...\n";
    bundled.displayObject();
}

// Demonstrates the standard member function implementation feature
void demoMemberFeature(Product list[], int count) {
    if (count == 0) {
        cout << "The list is empty!\n";
        return;
    }

    int index;
    double discount;
    
    cout << "Enter the index of the object to discount (0 to " << count - 1 << "): ";
    cin >> index;
    cout << "Enter the discount percentage (e.g., 20 for 20%): ";
    cin >> discount;

    cout << "\nBefore discount: \n";
    list[index].displayObject();

    // Calling the member function
    list[index].applyDiscount(discount);

    cout << "After discount: \n";
    list[index].displayObject();
}