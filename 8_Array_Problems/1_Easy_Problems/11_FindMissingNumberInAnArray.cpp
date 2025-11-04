#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 5}; int n = 5;

    // Brute Force Approach : TC = O(n^2), SC = O(1)
    bool flag;
    for(int i = 1; i <= n; i++) {
        flag = false;
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] == i) {
                flag = true;
                break;
            }
        }
        if(flag == false) {
            cout << i << " is missing";
            break;
        }
    }

    cout << endl;

    // Better Approach : TC = O(n), SC = O(n)
    vector<int> hash_arr(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        hash_arr[arr[i]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(hash_arr[i] == 0) {
            cout << i << " is missing";
            break;
        }
    }

    cout << endl;

    // Optimal Approach : TC = O(n), SC = O(1)
    int k = 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] != k) {
            cout << k << " is missing";
            break;
        }
        k++;
    }

    cout << endl;

    // Another Optimal Approach : TC = O(n), SC = O(1)
    int s = (n * (n + 1)) / 2;
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }
    cout << s - sum << " is missing";

    cout << endl;

    // One more Optimal Approach : TC = O(n), SC = O(1)
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n - 1; i++) {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n;
    int result = xor1 ^ xor2;
    cout << result << " is missing";

    return 0;
}