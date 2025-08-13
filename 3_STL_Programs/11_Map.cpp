#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    for (auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << m[1] << endl;
    cout << m[2] << endl;
    cout << m[3] << endl;

    map<pair<int, int>, int> m2;
    m2[{1, 2}] = 3;
    m2[{4, 5}] = 9;
    for(auto it : m2) {
        cout << it.first.first << " + " << it.first.second << " = " << it.second << endl;
    }
    return 0;
}