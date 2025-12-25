#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 3, 4, 2, 2, 5, 6, 2, 2};

    // Brute Force Approach : TC = O(n^2), SC = O(1)
    for(int i = 0; i < arr.size(); i++) {
        int count = 0;
        for(int j = i; j < arr.size(); j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > arr.size() / 2) {
            cout << "Majority element is : " << arr[i];
        }
    }

    cout << endl;

    // Better Approach : TC = O(n log n), SC = O(n)
    map<int, int> m;
    for(auto i : arr) {
        m[i]++;
    }
    for(auto i : m) {
        if(i.second > arr.size() / 2) {
            cout << "Majority element is : " << i.first;
        }
    }

    cout << endl;

    // Optimal Approach : TC = O(), SC = O()
    

    return 0;
}