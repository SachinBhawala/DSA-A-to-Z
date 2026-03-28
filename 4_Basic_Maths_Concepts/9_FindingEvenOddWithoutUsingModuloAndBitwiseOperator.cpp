#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if((n/2)*2 == n) {
        cout << "Even";
    } else {
        cout << "Odd";
    }

    return 0;
}