#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
bool subset(int n, vector<int>& arr, int k) {
    if(k == 0) return true;
    if(n == 0) return (arr[0] == k);

    bool notTake = subset(n-1, arr, k);
    bool take = false;
    if(arr[n] <= k) take = subset(n-1, arr, k-arr[n]);

    return notTake || take;
}

// DP (Mamoization) : TC = O(n*k), SC = O(n*k + n)
bool subsetDP1(int n, vector<int>& arr, int k, vector<vector<int>>& dp) {
    if(k == 0) return true;
    if(n == 0) return (arr[0] == k);

    if(dp[n][k] != -1) return dp[n][k];

    bool notTake = subsetDP1(n-1, arr, k, dp);
    bool take = false;
    if(arr[n] <= k) take = subsetDP1(n-1, arr, k-arr[n], dp);

    return dp[n][k] = notTake || take;
}

// DP (Tabulation) : TC = O(n*k), SC = O(n*k)
bool subsetDP2(int n, vector<int>& arr, int k) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target) take = dp[i-1][target-arr[i]];
            dp[i][target] = notTake || take;
        }
    }

    return dp[n-1][k];
}

// DP (Tabulation + Space Optimization) : TC = O(n*k), SC = O(n)
bool subsetDP3(int n, vector<int>& arr, int k) {
    vector<bool> prev(k+1, 0);

    prev[0] = true;
    if(arr[0] > 0) prev[arr[0]] = true;

    for(int i = 1; i < n; i++) {
        vector<bool> temp(k+1, 0);
        temp[0] = true;
        for(int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[i] <= target) take = prev[target-arr[i]];
            temp[target] = notTake || take;
        }
        prev = temp;
    }

    return prev[k];
}

int main() {
    int k = 4;
    vector<int> arr = {1, 5, 3, 6, 6, 9};
    int n = arr.size();

    cout << "\n" << subset(n-1, arr, k);

    vector<vector<int>> dp(n, vector<int> (k + 1, -1));
    cout << "\n" << subsetDP1(n-1, arr, k, dp);
    
    cout << "\n" << subsetDP2(n, arr, k);
    
    cout << "\n" << subsetDP3(n, arr, k);

    return 0;
}