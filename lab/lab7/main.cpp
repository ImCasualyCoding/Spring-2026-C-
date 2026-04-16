#include <iostream>
#include <array>
#include <vector>
using namespace std;


int main() {
int numbers[5];
cout << "Enter 5 integers:" << endl;
for(int i = 0; i < 5; i++) {
cin >>numbers[i];
}
cout << "\nYou entered:" << endl;
for(int i = 0; i < 5; i++) {
cout << numbers[i] << endl;
}
return 0;
}