#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
int miniPathSum(int m, int n, vector<vector<int>>& arr) {
    if(m >= arr.size() || n >= arr[m].size()) return INT_MAX;
    if(m == arr.size() - 1) return arr[m][n];

    int down = miniPathSum(m+1, n, arr);
    int diagonal = miniPathSum(m+1, n+1, arr);

    int best = min(down, diagonal);
    if (best == INT_MAX) return INT_MAX;

    return arr[m][n] + best;
}

// DP (Memoization) : TC = O(n^2), SC = O(n^2)
int miniPathSumDP1(int m, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(m >= arr.size() || n >= arr[m].size()) return INT_MAX;
    if(m == arr.size() - 1) return arr[m][n];

    if(dp[m][n] != -1) return dp[m][n];

    int down = miniPathSumDP1(m+1, n, arr, dp);
    int diagonal = miniPathSumDP1(m+1, n+1, arr, dp);

    int best = min(down, diagonal);
    if (best == INT_MAX) return INT_MAX;

    return dp[m][n] = arr[m][n] + best;
}

// DP (Tabulation) : TC = O(n^2), SC = O(n^2)
int miniPathSumDP2(int m, int n, vector<vector<int>>& arr) {
    // vector<vector<int>> dp = arr;
    vector<vector<int>> dp(m, vector<int> (n, -1));

    for(int i = 0; i < n; i++) {
        dp[m-1][i] = arr[m-1][i];
    }

    for(int i = m-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    return dp[0][0];
}

// DP (Tabulation + Space Optimization) : TC = O(n^2), SC = O(n)
int miniPathSumDP3(int m, int n, vector<vector<int>>& arr) {
    vector<int> prev(n);

    for (int i = 0; i < n; i++) {
        prev[i] = arr[m-1][i];
    }

    for (int i = m - 2; i >= 0; i--) {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++) {
            temp[j] = arr[i][j] + min(prev[j], prev[j+1]);
        }
        prev = temp;
    }

    return prev[0];
}

int main() {
    vector<vector<int>> triangle{{2}, {3, 9}, {1, 6, 7}};
    int m = triangle.size();
    int n = triangle[m-1].size();

    cout << "\n" << miniPathSum(0, 0, triangle);

    vector<vector<int>> dp(m, vector<int> (n, -1));
    cout << "\n" << miniPathSumDP1(0, 0, triangle, dp);

    cout << "\n" << miniPathSumDP2(m, n, triangle);
    
    cout << "\n" << miniPathSumDP3(m, n, triangle);

    return 0;
}