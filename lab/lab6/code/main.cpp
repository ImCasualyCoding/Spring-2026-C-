#include "functions.h"
#include <iostream>
#include <string>
#include <iomanip>



using namespace std;

int main()
{
    int x = 5;
    int y = 10;
    cout<< "Original x:" << x << endl;

    //Pass by value call

    int result = multiplyByTwo(x);
    cout <<"After MultiplyByTwo:" << result << endl;

    cout<<"x is still:" << x << endl;
    cout<<"\nBefore swap: x=" << x << ", y=" << y << endl;

    //pass by reference call
    swapNumbers(x, y);
    cout<<"After swap: x=" << x << ", y=" << y << endl;
    return 0;
}