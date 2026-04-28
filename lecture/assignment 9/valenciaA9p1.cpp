/*************************************************************************
*****
COP 3275C assignment 9 PART 1 string and vector practice
Brandon Valencia
4/27/26
strings and vectors to reverse a full phrase, then 
reconstructs it with the words in reverse order.
**************************************************************************
*****/

#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Input a string phrase and a string vector by reference
// Separates a phrase into words and stores each word in a string vector
void separatePhrase(const string& phrase, vector<string>& words);


string reversePhrase(vector<string> reverseWords);

int main() {
    string phrase;
    vector<string> words;

    
    cout << "Enter a short phrase: ";
    
   
    getline(cin, phrase);


    string doubleReverse = phrase;

  
    reverse(doubleReverse.begin(), doubleReverse.end());
    
    cout << "\n--- Output ---" << endl;
    cout << "Fully reversed string: " << doubleReverse << "\n\n";

   
    separatePhrase(phrase, words);

    
    cout << "Words in a column:" << endl;
    for (size_t i = 0; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
    cout << endl;

    
    string backwardsPhrase = reversePhrase(words);
    cout << "Words in backwards order: " << backwardsPhrase << endl;

    return 0;
}

// ---------------------------------------------------------
// Function Implementations
// ---------------------------------------------------------

void separatePhrase(const string& phrase, vector<string>& words) {
    string currentWord = "";
    
    // Loop to locate all the characters in the phrase.size()
    for (size_t i = 0; i < phrase.size(); ++i) {
        if (phrase[i] == ' ') {
            
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear(); 
            }
        } else {
            currentWord += phrase[i];
        }
    }
    
    
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }
}

string reversePhrase(vector<string> reverseWords) {
    string newPhrase = "";
    
    // Pop the words off the vector from the back
    while (!reverseWords.empty()) {
        newPhrase += reverseWords.back(); // Get the last word
        reverseWords.pop_back();          // Remove the last word from the vector
        
        // Add a space after the word, as long as it isn't the very last word to be added
        if (!reverseWords.empty()) {
            newPhrase += " ";
        }
    }
    
    return newPhrase;
}