#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int sum = 0, original = n;
    int digits = to_string(n).length();
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit * digit;
        n /= 10;
    }
    if (original == sum) {
        cout << original << " is an Armstrong number." << endl;
    } else {
        cout << original << " is not an Armstrong number." << endl;
    }
    return 0;
}
