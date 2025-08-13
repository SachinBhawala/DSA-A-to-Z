#include<bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> m;
    m.insert({1, "one"});
    m.insert({2, "two"});
    m.insert({3, "three"});
    m.insert({2, "deux"});
    m.insert({3, "trois"});

    for (auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}