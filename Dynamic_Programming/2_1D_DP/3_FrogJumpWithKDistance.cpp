#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
int frogJump(int n, vector<int>& height, int k) {
    if(n == 0) return 0;
    int minSteps = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(n - i >= 0) {
            minSteps = min(minSteps, frogJump(n - i, height, k) + abs(height[n] - height[n - i]));
        }
    }
    return minSteps;
}

// DP (Memoization) : TC = O(n*k), SC = O(2n)
int frogJumpDP1(int n, vector<int>& height, int k, vector<int>& dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) {
        return dp[n];
    }
    int minSteps = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(n - i >= 0) {
            minSteps = min(minSteps, frogJumpDP1(n - i, height, k, dp) + abs(height[n] - height[n - i]));
        }
    }
    return dp[n] = minSteps;
}

// DP (Tabulation) : TC = O(n*k), SC = O(n)
int frogJumpDP2(int n, vector<int>& height, int k, vector<int>& dp) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                minSteps = min(minSteps, dp[i - j] + abs(height[i] - height[i - j]));
            }
        }
        dp[i] = minSteps;
    }
    return dp[n];
}

int main() {
    int n = 6, k = 3;
    vector<int> height = {10, 20, 30, 10, 50, 30};

    cout << "Minimum energy is : " << frogJump(n - 1, height, k);
    
    cout << endl;
    
    vector<int> dp1(n, -1);
    cout << "Minimum energy is : " << frogJumpDP1(n - 1, height, k, dp1);

    cout << endl;
    
    vector<int> dp2(n, 0);
    cout << "Minimum energy is : " << frogJumpDP2(n - 1, height, k, dp2);

    return 0;
}