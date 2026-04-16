
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Function Template: works for any data type
template <typename T>
T add(T a, T b) {
return a+b;
}


int main() {
    // Using template function with different data types
    cout << "Sum (int): " << add(4, 6) << endl;
    cout << "Sum (double): " << add(2.5, 3.5) << endl;
    // Creating and initializing a vector
    vector<int> v={5,2,8,1};
    // Adding element to vector
    v.push_back(3);
    // Displaying vector elements
    cout << "\nVector: ";
    for (int x : v) {
    cout << x << " ";
    }
    // Sorting the vector using STL

    sort(v.begin(), v.end());
    // Displaying sorted vector
    cout << "\nSorted: ";
    for (int x : v) {
    cout << x << " ";
    }
    // Accessing first and last elements
    cout << "\nFirst element: " << v.front();
    cout << "\nLast element: " << v.back();
    // Removing last element
    v.pop_back();
    // Display after removal
    cout << "\nAfter pop_back: ";
    for (int x : v) {
    cout << x << " ";
    }
return 0;
// End of program
}