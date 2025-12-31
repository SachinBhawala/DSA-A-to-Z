#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
int frogJump(int n, vector<int>& height) {
    if(n == 1) return 0;
    int left = frogJump(n - 1, height) + abs(height[n - 1] - height[n - 2]);
    int right = INT_MAX;
    if(n > 2) {
        right = frogJump(n - 2, height) + abs(height[n - 1] - height[n - 3]);
    }
    return min(left, right);
}

// DP (Memoization) : TC = O(n), SC = O(2n)
int frogJumpDP1(int n, vector<int>& height, vector<int>& dp) {
    if(n == 1) return 0;
    if(dp[n] != -1) {
        return dp[n];
    }
    int left = frogJumpDP1(n - 1, height, dp) + abs(height[n - 1] - height[n - 2]);
    int right = INT_MAX;
    if(n > 2) {
        right = frogJumpDP1(n - 2, height, dp) + abs(height[n - 1] - height[n - 3]);
    }
    return dp[n] = min(left, right);
}

// DP (Tabulation) : TC = O(n), SC = O(n)
int frogJumpDP2(int n, vector<int>& height, vector<int>& dp) {
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if(i > 1) {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

// DP (Tabulation + Space Optimization) : TC = O(n), SC = O(1)
int frogJumpDP3(int n, vector<int>& height) {
    int prev1 = 0;
    int prev2 = 0;
    int curr;
    for(int i = 1; i < n; i++) {
        int left = prev1 + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if(i > 1) {
            right = prev2 + abs(height[i] - height[i - 2]);
        }
        curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n = 4;
    vector<int> height = {10, 20, 30, 10};

    cout << "Minimum energy is : " << frogJump(n, height);

    cout << endl;

    vector<int> dp1(n+1, -1);
    cout << "Minimum energy is : " << frogJumpDP1(n, height, dp1);

    cout << endl;

    vector<int> dp2(n, 0);
    cout << "Minimum energy is : " << frogJumpDP2(n, height, dp2);

    cout << endl;

    cout << "Minimum energy is : " << frogJumpDP3(n, height);

    return 0;
}