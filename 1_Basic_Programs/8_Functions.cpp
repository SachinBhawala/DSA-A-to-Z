#include<bits/stdc++.h>
using namespace std;

void printMessage() {
    cout << "Hello from a function!" << endl;
}

// Function to demonstrate passing by value
void passByValueFunction(int x) {
    cout << "This is pass by value function. You passed: " << x << endl;
}

// Function to demonstrate passing by reference
void passByReferenceFunction(int& a) {
    cout << "This is pass by reference function. You passed: " << a << endl;
}

int main() {
    int a = 10;
    printMessage();
    passByValueFunction(42);
    passByReferenceFunction(a);
    return 0;
}
// This program demonstrates the use of functions in C++.