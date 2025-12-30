#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
int maxSum(int n, vector<int>& arr) {
    if(n == 0) return arr[n];
    if(n < 0) return 0;
    int pick = arr[n] + maxSum(n-2, arr);
    int notPick = 0 + maxSum(n-1, arr);
    return max(pick, notPick);
}

// DP (Memoization) : TC = O(n), SC = O(2n)
int maxSumDP1(int n, vector<int>& arr, vector<int>& dp) {
    if(n == 0) return arr[n];
    if(n < 0) return 0;
    if(dp[n] != -1) {
        return dp[n];
    }
    int pick = arr[n] + maxSumDP1(n-2, arr, dp);
    int notPick = 0 + maxSumDP1(n-1, arr, dp);
    return dp[n] = max(pick, notPick);
}

// DP (Tabulation) : TC = O(n), SC = O(n)
int maxSumDP2(vector<int>& arr, vector<int>& dp) {
    int n = arr.size();
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0], arr[1]);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++) {
        int pick = arr[i] + dp[i-2];
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

// DP (Tabulation + Space Optimization) : TC = O(n), SC = O(1)
int maxSumDP3(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];
    if (n == 2) return max(arr[0], arr[1]);
    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        int curr = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n = 2;
    vector<int> arr = {1, 2};

    cout << "Maximum Sum is : " << maxSum(n-1, arr);

    cout << endl;

    vector<int> dp1(n, -1);
    cout << "Maximum Sum is : " << maxSumDP1(n-1, arr, dp1);

    cout << endl;

    vector<int> dp2(n, 0);
    cout << "Maximum Sum is : " << maxSumDP2(arr, dp2);
    
    cout << endl;
    
    cout << "Maximum Sum is : " << maxSumDP3(arr);
    return 0;
}