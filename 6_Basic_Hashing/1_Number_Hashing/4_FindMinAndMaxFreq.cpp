#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 1, 3, 4, 5, 1, 4, 1};
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }

    // Find minimum and maximum frequency
    int minFreq = INT_MAX, maxFreq = INT_MIN;
    for (auto& pair : freqMap) {
        minFreq = min(minFreq, pair.second);
        maxFreq = max(maxFreq, pair.second);
    }

    cout << "Minimum frequency: " << minFreq << endl;
    cout << "Maximum frequency: " << maxFreq << endl;

    return 0;
}
