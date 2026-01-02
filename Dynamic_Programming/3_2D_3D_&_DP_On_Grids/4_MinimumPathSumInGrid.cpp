#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^(m+n)), SC = O(m+n)
int minPathSum(int m, int n, vector<vector<int>>& arr) {
    if(m < 0 || n < 0) return INT_MAX;
    if(m == 0 && n == 0) return arr[m][n];

    int up = minPathSum(m-1, n, arr);
    int left = minPathSum(m, n-1, arr);

    int best = min(up, left);
    if(best == INT_MAX) return INT_MAX;

    return arr[m][n] + best;
}

// DP (Memoization) : TC = O(m*n), SC = O((m+n) + (m*n))
int minPathSumDP1(int m, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(m < 0 || n < 0) return INT_MAX;
    if(m == 0 && n == 0) return arr[m][n];

    if(dp[m][n] != -1) return dp[m][n];

    int up = minPathSumDP1(m-1, n, arr, dp);
    int left = minPathSumDP1(m, n-1, arr, dp);

    int best = min(up, left);
    if(best == INT_MAX) return INT_MAX;

    return dp[m][n] = arr[m][n] + best;
}

// DP (Tabulation) : TC = O(m*n), SC = O(m*n)
int minPathSumDP2(int m, int n, vector<vector<int>>& arr) {
    vector<vector<int>> dp(m, vector<int> (n, INT_MAX));

    dp[0][0] = arr[0][0];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) continue;

            int up = (i > 0) ? dp[i-1][j] : INT_MAX;
            int left = (j > 0) ? dp[i][j-1] : INT_MAX;

            dp[i][j] = arr[i][j] + min(up, left);
        }
    }
    return dp[m-1][n-1];
}

// DP (Tabulation + Space Optimization) : TC = O(m*n), SC = O(n)
int minPathSumDP3(int m, int n, vector<vector<int>>& arr) {
    vector<int> prev(n, INT_MAX);

    for(int i = 0; i < m; i++) {
        vector<int> temp(n, INT_MAX);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                temp[j] = arr[i][j];
                continue;
            }
            int up = (i > 0) ? prev[j] : INT_MAX;
            int left = (j > 0) ? temp[j-1] : INT_MAX;

            temp[j] = arr[i][j] + min(up, left);
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {
    vector<vector<int>> arr = {{5, 9, 6}, {11, 5, 2}, {9, 7, 8}};
    int m = arr.size();
    int n = arr[0].size();

    cout << minPathSum(m-1, n-1, arr);
    
    cout << endl;
    
    vector<vector<int>> dp1(m, vector<int> (n, -1));
    cout << minPathSumDP1(m-1, n-1, arr, dp1);

    cout << endl;
    
    cout << minPathSumDP2(m, n, arr);

    cout << endl;
    
    cout << minPathSumDP3(m, n, arr);

    return 0;
}