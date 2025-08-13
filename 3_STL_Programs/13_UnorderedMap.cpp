#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um;
    um[1] = "one";
    um[2] = "two";
    um[3] = "three";
    um[5] = "five";
    um[8] = "eight";
    um[7] = "seven";
    um[9] = "nine";
    um[4] = "four";
    um[6] = "six";

    for (auto it : um) {
        cout << it.first << ": " << it.second << endl;
    }

    cout << um[1] << endl;
    cout << um[2] << endl;
    cout << um[3] << endl;

    return 0;
}