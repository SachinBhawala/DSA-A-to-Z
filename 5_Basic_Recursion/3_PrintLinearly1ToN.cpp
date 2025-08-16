#include<bits/stdc++.h>
using namespace std;

void printNumbers(int n) {
    if (n == 0) return; // Base case
    printNumbers(n - 1); // Recursive call
    cout << n << " "; // Print the current number
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    printNumbers(n); // Print numbers from 1 to n
    return 0;
}