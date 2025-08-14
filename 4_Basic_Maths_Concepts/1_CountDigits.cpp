#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, lastDigit, count = 0;
    cout << "Enter a number: ";
    cin >> n;

    while(n > 0) {
        lastDigit = n % 10;
        cout << lastDigit << " ";
        n /= 10;
        count++;
    }
    cout << endl;
    cout << "Number of digits: " << count << endl;
    return 0;
}