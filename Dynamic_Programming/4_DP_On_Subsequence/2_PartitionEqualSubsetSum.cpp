#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
bool partitionSubset(int index, int target, vector<int>& arr) {
    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);

    bool notTake = partitionSubset(index-1, target, arr);
    bool take = false;
    if(arr[index] <= target) take = partitionSubset(index-1, target-arr[index], arr);

    return notTake || take;
}

// DP (Mamoization) : TC = O(n*k), SC = O(n*k + n)
bool partitionSubsetDP1(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);

    if(dp[index][target] != -1) return dp[index][target];

    bool notTake = partitionSubsetDP1(index-1, target, arr, dp);
    bool take = false;
    if(arr[index] <= target) take = partitionSubsetDP1(index-1, target-arr[index], arr, dp);

    return dp[index][target] = notTake || take;
}

// DP (Tabulation) : TC = O(n*k), SC = O(n*k)
bool partitionSubsetDP2(int n, int k, vector<int>& arr) {
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
bool partitionSubsetDP3(int n, int k, vector<int>& arr) {
    vector<bool> prev(k+1, 0);

    prev[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;

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
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int target = sum/2;

    if(sum % 2 != 0) cout << "Cannot Possible..!!!";
    else {
        cout << "\n" << partitionSubset(n-1, target, arr);
        
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        cout << "\n" << partitionSubsetDP1(n-1, target, arr, dp);
        
        cout << "\n" << partitionSubsetDP2(n, target, arr);
    
        cout << "\n" << partitionSubsetDP3(n, target, arr);
    }

    return 0;
}