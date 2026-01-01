#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^(m+n)), SC = O(m+n)
int gridUniquePath(int m, int n) {
    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;

    int up = gridUniquePath(m-1, n);
    int left = gridUniquePath(m, n-1);

    return up + left;
}

// DP (Memoiztion) : TC = O(m*n), SC = O(m*n + m+n)
int gridUniquePathDP1(int m, int n, vector<vector<int>>& dp) {
    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    int up = gridUniquePathDP1(m-1, n, dp);
    int left = gridUniquePathDP1(m, n-1, dp);

    return dp[m][n] = up + left;
}

// DP (Tabulation) : TC = O(m*n), SC = O(m*n)
int gridUniquePathDP2(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) continue;
            int up = 0, left = 0;
            if(i > 0) up = dp[i-1][j];
            if(j > 0) left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}

// DP (Tabulation + Space Optimization) : TC = O(m*n), SC = O(n)
int gridUniquePathDP3(int m, int n) {
    vector<int> prev(n, 0);
    for(int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(i > 0) up = prev[j];
            if(j > 0) left = temp[j-1];
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {
    int m = 2;
    int n = 2;

    cout << gridUniquePath(m - 1, n - 1);
    
    cout << endl;

    vector<vector<int>> dp1(m, vector<int>(n, -1));
    cout << gridUniquePathDP1(m - 1, n - 1, dp1);

    cout << endl;

    cout << gridUniquePathDP2(m, n);

    cout << endl;

    cout << gridUniquePathDP3(m, n);

    return 0;
}