#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Brute Forch Approach : TC = O(n^2), SC = O(1)
    int count;
    for(int i = 0; i < arr.size(); i++) {
        count = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count == 1) {
            cout << arr[i] << " appears one time...!!!";
            break;
        }
    }

    cout << endl;

    // Better Approach : TC = O(n), SC = O(max element)
    int maxi = 0;
    for(int i : arr) {
        maxi = max(i, maxi);
    }
    vector<int> hash(maxi + 1, 0);
    for(int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }
    for(int i = 1; i < hash.size(); i++) {
        if(hash[i] == 1) {
            cout << i << " appears one time...!!!";
            break;
        }
    }

    cout << endl;

    // We can also use map data structure here : TC = O(n log n), SC = O(n/2 + 1)
    map<int, int> m;
    for(int i : arr) {
        m[i]++;
    }
    for(int i : arr) {
        if(m[i] == 1) {
            cout << i << " appears one time...!!!";
        }
    }

    cout << endl;

    // Optimal Approach : TC = O(n), SC = O(1)
    int x = 0;
    for(int i : arr) {
        x = x ^ i;
    }
    cout << x << " appears one time...!!!";

    return 0;
}