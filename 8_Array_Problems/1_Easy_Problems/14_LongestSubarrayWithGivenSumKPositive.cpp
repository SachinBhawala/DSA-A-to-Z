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

    // Better approach : TC = O(n long n) SC = O(n)  {For -ves', zeros, & +ves'}
    int len2 = 0;
    map<long long, int> preSum;
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == k) {
            len2 = max(len2, i + 1);
        }
        long long rem = sum - k;
        if(preSum.find(rem) != preSum.end()) {
            int len = i - preSum[rem];
            len2 = max(len2, len);
        }
        if(preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
        }
    }
    cout << "Longest subarray is: " << len2;

    cout << endl;

    // Optimal Approach : TC = O(2n), SC = O(1)   {For zeros, & +ves'}
    int left = 0;
    int right = 0;
    int len3 = 0;
    sum = arr[0];
    int n = arr.size();
    while(right < n) {
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            len3 = max(len3, right - left + 1);
        }
        right++;
        if(right < n) {
            sum += arr[right];
        }
    }

    cout << "Longest subarray is: " << len3; 

    return 0;
}