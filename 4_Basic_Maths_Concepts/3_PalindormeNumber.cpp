#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int reversed = 0, original = n;
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    if (original == reversed) {
        cout << original << " is a palindrome number." << endl;
    } else {
        cout << original << " is not a palindrome number." << endl;
    }
    return 0;
}