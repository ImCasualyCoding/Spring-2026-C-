#ifndef AGE_H
#define AGE_H

#include <string>

using namespace std;

// Function Prototypes
void getData(string &name, int &year);
void getGeneration(string name, int year, string &category);
int calculateAge(string name, int year);
int findYoungest(int a1, int a2, int a3);
int findOldest(int a1, int a2, int a3);
void printYoungest(string name, int age, int year, string category);
void printOldest(string name, int age, int year, string category);

#endif