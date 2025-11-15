#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    // Brute Force Approach : TC = O(n^2), SC = O(1)
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == target) {
                cout << "Yes\n" << "Index: " << i << "," << j;
                break;
            }
        }
    }

    cout << endl;

    // Optimal Approach : TC = O(n logn), SC = O(n)
    map<int, int> m;
    int flag = false;
    for(int i = 0; i < arr.size(); i++) {
        int more = target - arr[i];
        if(m.find(more) != m.end()) {
            cout << "Yes\n" << "Index: " << m[more] << "," << i;
            flag = true;
            break;
        }
        m[arr[i]] = i;
    }
    if(flag == false) {
        cout << "No";
    }
    return 0;
}