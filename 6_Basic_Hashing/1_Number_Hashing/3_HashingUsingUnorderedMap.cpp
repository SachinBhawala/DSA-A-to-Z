#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 1, 3, 4, 5, 1, 4, 1};
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }
    for (auto& pair : freqMap) {
        cout << "Number " << pair.first << " appears " << pair.second << " times." << endl;
    }
    return 0;
}