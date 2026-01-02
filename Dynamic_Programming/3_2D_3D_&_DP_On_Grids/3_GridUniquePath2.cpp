// Grid Path with obstacles
#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^(m+n)), SC = O(m+n)
int gridUniquePath(int m, int n, vector<vector<int>>& arr) {
    if(m < 0 || n < 0) return 0;
    if(arr[m][n] == -1) return 0;
    if(m == 0 && n == 0) return 1;
    int up = gridUniquePath(m-1, n, arr);
    int left = gridUniquePath(m, n-1, arr);
    return up + left;
}

// DP (Memoization) : TC = O(m*n), SC = O((m+n) + (m*n))
int gridUniquePathDP1(int m, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(m < 0 || n < 0) return 0;
    if(arr[m][n] == -1) return 0;
    if(m == 0 && n == 0) return 1;

    if(dp[m][n] != -1) return dp[m][n];

    int up = gridUniquePathDP1(m-1, n, arr, dp);
    int left = gridUniquePathDP1(m, n-1, arr, dp);
    return dp[m][n] = up + left;
}

// DP (Tabulation) : TC = O(m*n), SC = O(m*n)
int gridUniquePathDP2(int m, int n, vector<vector<int>>& arr) {
    vector<vector<int>> dp(m, vector<int> (n, 0));
    dp[0][0] = (arr[0][0] == -1 ? 0 : 1);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
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
int gridUniquePathDP3(int m, int n, vector<vector<int>>& arr) {
    vector<int> prev(n, 0);

    for(int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == -1) {
                temp[j] = 0;
                continue;
            }
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
    int m = 3;
    int n = 3;
    vector<vector<int>> arr = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};

    cout << gridUniquePath(m-1, n-1, arr);

    cout << endl;

    vector<vector<int>> dp1(m, vector<int> (n, -1));
    cout << gridUniquePathDP1(m-1, n-1, arr, dp1);

    cout << endl;

    cout << gridUniquePathDP2(m, n, arr);

    cout << endl;

    cout << gridUniquePathDP3(m, n, arr);

    return 0;
}