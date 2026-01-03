#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(3^m), SC = O(m)
int maxFallingSum(int m, int n, vector<vector<int>>& arr) {
    int cols = arr[0].size();
    if(m < 0 || n < 0 || n >= cols) return INT_MIN;
    if(m == 0) return arr[m][n];

    int leftDiagonal = maxFallingSum(m-1, n-1, arr);
    int up = maxFallingSum(m-1, n, arr);
    int rightDiagonal = maxFallingSum(m-1, n+1, arr);

    int best = max(leftDiagonal, max(up, rightDiagonal));
    if(best == INT_MIN) return INT_MIN;

    return arr[m][n] + best;
}

// DP (Memoization) : TC = O(m*n), SC = O(m*n + m)
int maxFallingSumDP1(int m, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    int cols = arr[0].size();
    if(m < 0 || n < 0 || n >= cols) return INT_MIN;
    if(m == 0) return arr[m][n];

    if(dp[m][n] != -1) return dp[m][n];

    int leftDiagonal = maxFallingSumDP1(m-1, n-1, arr, dp);
    int up = maxFallingSumDP1(m-1, n, arr, dp);
    int rightDiagonal = maxFallingSumDP1(m-1, n+1, arr, dp);

    int best = max(leftDiagonal, max(up, rightDiagonal));
    if(best == INT_MIN) return dp[m][n] = INT_MIN;

    return dp[m][n] = arr[m][n] + best;
}

// DP (Tabulation) : TC = O(m*n), SC = O(m*n)
int maxFallingSumDP2(int m, int n, vector<vector<int>>& arr) {
    vector<vector<int>> dp(m, vector<int> (n, -1));

    for(int i = 0; i < n; i++) {
        dp[0][i] = arr[0][i];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int leftDiagonal = (j > 0) ? dp[i-1][j-1] : INT_MIN;
            int up = dp[i-1][j];
            int rightDiagonal = (j < n-1) ? dp[i-1][j+1] : INT_MIN;

            int best = max(leftDiagonal, max(up, rightDiagonal));

            if (best != INT_MIN) {
                dp[i][j] = arr[i][j] + best;
            } else {
                dp[i][j] = INT_MIN;
            }
        }
    }

    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, dp[m-1][i]);
    }

    return maxi;
}

// DP (Tabulation + Space Optimization) : TC = O(m*n), SC = O(n)
int maxFallingSumDP3(int m, int n, vector<vector<int>>& arr) {
    vector<int> prev(n);

    for(int i = 0; i < n; i++) {
        prev[i] = arr[0][i];
    }

    for(int i = 1; i < m; i++) {
        vector<int> temp(n);
        for(int j = 0; j < n; j++) {
            int leftDiagonal = (j > 0) ? prev[j-1] : INT_MIN;
            int up = prev[j];
            int rightDiagonal = (j < n-1) ? prev[j+1] : INT_MIN;

            int best = max(leftDiagonal, max(up, rightDiagonal));

            if (best != INT_MIN) {
                temp[j] = arr[i][j] + best;
            } else {
                temp[j] = INT_MIN;
            }
        }
        prev = temp;
    }

    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, prev[i]);
    }

    return maxi;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int m = 4;
    int n = 4;

    int ans = INT_MIN;
    for(int j = 0; j < n; j++) {
        ans = max(ans, maxFallingSum(m-1, j, arr));
    }
    cout << "\n" << ans;

    vector<vector<int>> dp1(m, vector<int> (n, -1));
    int ans2 = INT_MIN;
    for(int j = 0; j < n; j++) {
        ans2 = max(ans2, maxFallingSumDP1(m-1, j, arr, dp1));
    }
    cout << "\n" << ans2;

    cout << "\n" << maxFallingSumDP2(m, n, arr);

    cout << "\n" << maxFallingSumDP3(m, n, arr);

    return 0;
}