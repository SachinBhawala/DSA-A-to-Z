#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k = 3;

    // Brute Force Approach : TC = O(n^3), SC = O(1)
    int len1 = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if(sum == k) {
                len1 = max(len1, j - i + 1);
                break;
            } else if(sum > k) {
                break;
            }
        }
    }
    cout << "Longest subarray is: " << len1;

    cout << endl;

    // Better approach
    

    cout << endl;

    return 0;
}