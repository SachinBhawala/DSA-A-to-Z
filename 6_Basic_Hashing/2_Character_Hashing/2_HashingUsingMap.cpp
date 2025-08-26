#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "sachin bhawala";
    map<char, int> freqMap;
    for (char c : s) {
        if (c != ' ') {
            freqMap[c]++;
        }
    }
    for (auto& pair : freqMap) {
        cout << "Character '" << pair.first << "' appears " << pair.second << " times." << endl;
    }
    return 0;
}
