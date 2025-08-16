#include<bits/stdc++.h>
using namespace std;

void printNumbers(int n) {
    if (n == 0) return; // Base case
    cout << n << " "; // Print the current number
    printNumbers(n - 1); // Recursive call
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    printNumbers(n); // Print numbers from 1 to n
    return 0;
}