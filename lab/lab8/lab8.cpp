#include <iostream>
using namespace std;
int main() {
// Pointer Basics

int num=25;
int *p=&num;
cout << "Value using pointer: " << *p << endl;

//Dynamic Memory
int *a=new int(50);
cout<<"Dynamic value:"<<*a<<endl;
delete a;

//Dynamic Array
int n=5;
int *arr = new int[n];
for(int i =0; i<n;i++)
  arr[i]=i*2; //assigning values to array


cout << "Array: ";
for(int i = 0; i < n; i++)
cout << arr[i] << " ";

delete[]arr; 
return 0; //end of program
}

