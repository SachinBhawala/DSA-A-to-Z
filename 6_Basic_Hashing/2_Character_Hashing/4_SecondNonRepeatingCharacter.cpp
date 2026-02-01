#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "\nEnter a string: ";
    getline(cin, s);

    unordered_map<char, int> m;
    for(char c : s) {
        if(c != ' ') {
            m[c]++;
        }
    }

    int count = 0;
    for(char c : s) {
        if(c != ' ' && m[c] == 1) {
            if(count == 1) {
                cout << "First non repeating character is: " << c;
                break;
            }
            count++;
        }
    }

    return 0;
}