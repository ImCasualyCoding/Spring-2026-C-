#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main() {
// Step 1: Declare arrays
char word[50];
char reverse[50];
char upper[50];
// Step 2: Take input
cout << "Enter a word: ";
cin>>word;
// Step 3: Find length
int len = strlen(word);
// Step 4: Convert to uppercase (store in new array)
for (int i = 0; i < len; i++) {
upper[i] = toupper(word[i]);
}
upper[len]='\0';
// Step 5: Reverse the word (store in new array)
for (int i = 0; i < len; i++) {
reverse[i] = word[len - 1 - i];
}
reverse[len]='\0';
// Step 6: Output results
cout << "\nOriginal Word: " << word;
cout<< "\nUppercase Word: "<<upper;
cout << "\nReversed Word: " << reverse;
return 0;//end of program
}