#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int revNum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        revNum = revNum * 10 + lastDigit;
        n /= 10;
    }
    cout << "Reversed number: " << revNum << endl;
    return 0;
}