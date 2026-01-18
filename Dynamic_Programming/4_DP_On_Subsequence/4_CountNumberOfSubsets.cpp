#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
int countSubset(int index, int target, vector<int>& arr) {
    if(index == 0) {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }

    // if(target == 0) return 1;
    // if(index == 0) return (arr[0] == target);

    int notTake = countSubset(index-1, target, arr);
    int take = 0;
    if(arr[index] <= target) take = countSubset(index-1, target-arr[index], arr);

    return take + notTake;
}

// DP (Mamoization) : TC = O(n*k), SC = O(n*k + n)
int countSubsetDP1(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(index == 0) {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }

    // if(target == 0) return 1;
    // if(index == 0) return (arr[0] == target);

    if(dp[index][target] != -1) return dp[index][target];

    int notTake = countSubsetDP1(index-1, target, arr, dp);
    int take = 0;
    if(arr[index] <= target) take = countSubsetDP1(index-1, target-arr[index], arr, dp);

    return dp[index][target] = take + notTake;
}

// DP (Tabulation) : TC = O(n*k), SC = O(n*k)
int countSubsetDP2(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, 0));

    if (arr[0] == 0) {
        dp[0][0] = 2;          // pick 0 OR not pick 0
    } else {
        dp[0][0] = 1;          // empty subset
    }

    if (arr[0] != 0 && arr[0] <= k) {
        dp[0][arr[0]] = 1;     // single-element subset
    }

    for(int index = 0; index < n; index++) {
        dp[index][0] = 1;
    }
    // if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int index = 1; index < n; index++) {
        // for(int target = 1; target <= k; target++) {
        for(int target = 0; target <= k; target++) {
            int notTake = dp[index-1][target];
            int take = 0;
            if(arr[index] <= target) take = dp[index-1][target-arr[index]];
            dp[index][target] = take + notTake;
        }
    }

    return dp[n-1][k];
}

// DP (Tabulation + Space Optimization) : TC = O(n*k), SC = O(n)
int countSubsetDP3(int n, int k, vector<int>& arr) {
    vector<int> prev(k+1, 0);

    if (arr[0] == 0) {
        prev[0] = 2;      // pick 0 OR not pick 0
    } else {
        prev[0] = 1;      // empty subset
    }

    if (arr[0] != 0 && arr[0] <= k) {
        prev[arr[0]] = 1;
    }

    // prev[0] = 1;
    // if(arr[0] <= k) prev[arr[0]] = 1;

    for(int index = 1; index < n; index++) {
        vector<int> temp(k+1, 0);
        for(int target = 0; target <= k; target++) {
            int notTake = prev[target];
            int take = 0;
            if(arr[index] <= target) take = prev[target-arr[index]];
            temp[target] = notTake + take;
        }
        prev = temp;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    int n = arr.size();

    cout << "\n" << countSubset(n-1, k, arr);

    vector<vector<int>> dp1(n, vector<int> (k+1, -1));
    cout << "\n" << countSubsetDP1(n-1, k, arr, dp1);

    cout << "\n" << countSubsetDP2(n, k, arr);

    cout << "\n" << countSubsetDP3(n, k, arr);

    return 0;
}