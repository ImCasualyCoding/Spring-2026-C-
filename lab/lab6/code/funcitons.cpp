#include <iostream>

int multiplyByTwo(int num) {
    return num * 2;
}

// pass by reference function to swap two numbers
void swapNumbers(int &a, int &b) {
    int temp = a; // store the value of a in a temporary variable
    a = b; // assign the value of b to a
    b = temp; // assign the value of temp (original a) to b
}