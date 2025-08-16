#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // BF approach
    for(int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << "GCD of " << a << " and " << b << " is: " << i << endl;
            break;
        }
    }

    // Using Euclidean algorithm
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) {
        cout << "GCD of the two numbers is: " << b << endl;
    } else {
        cout << "GCD of the two numbers is: " << a << endl;
    }

    return 0;
}