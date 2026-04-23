#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal
{
protected:
    string name; // Protected variable so derived class can use it

public:
    // Constructor to initialize animal name
    Animal(string n)
    {
        name = n;
    }

    // Function to show eating action
    void eat()
    {
        cout << name << " is eating." << endl;
    }

    // Function to show sleeping action
    void sleep()
    {
        cout << name << " is sleeping." << endl;
    }
};

// Derived class Dog inherits Animal
class Dog : public Animal
{
private:
    string breed; // Private variable for dog breed

public:
    // Constructor initializes base class and breed
    Dog(string n, string b) : Animal(n)
    {
        breed = b;
    }

    // Function to display dog details
    void showInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Breed: " << breed << endl;
    }

    // Function for barking
    void bark()
    {
        cout << name << " the " << breed << " is barking." << endl;
    }
};

int main()
{
    // Create object of Dog class
    Dog d1("Buddy", "Labrador");

    // Call member functions
    d1.showInfo();
    d1.eat();
    d1.sleep();
    d1.bark();

    return 0; // End of program
}