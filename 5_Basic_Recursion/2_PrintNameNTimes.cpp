#include<bits/stdc++.h>
using namespace std;

void printName(int n) {
    if (n == 0) return; // Base case
    cout << "Sachin" << endl;
    printName(n - 1); // Recursive call
}

int main() {
    int n;
    cout << "Enter the number of times to print the name: ";
    cin >> n;
    printName(n); // Print name n times
    return 0;
}