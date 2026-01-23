#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Create a hash array
    int hash[256] = {0};

    // Hashing the characters
    for (char c : s) {
        hash[(unsigned char)c]++;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--) {
        char c;
        cout << "Enter a character to query frequency: ";
        cin >> c;
        cout << "Frequency of '" << c << "': " << hash[(unsigned char)c] << endl;
    }
    return 0;
}