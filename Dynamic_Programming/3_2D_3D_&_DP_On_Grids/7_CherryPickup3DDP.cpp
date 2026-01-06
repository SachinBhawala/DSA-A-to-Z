// 2 starting variable and various ending variable (0 -> n-1)

#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(9^m), SC = O(m)
int cherryPickup(int i1, int j1, int j2, vector<vector<int>>& arr) {
    if(j1 < 0 || j2 >= arr[0].size() || j1 >= arr[0].size() || j2 < 0) return -1e8;

    if(i1 == arr.size() - 1) {
        if(j1 != j2) {
            return arr[i1][j1] + arr[i1][j2];
        } else {
            return arr[i1][j1];
        }
    }
    
    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            if(j1 == j2) {
                maxi = max(maxi, arr[i1][j1] + cherryPickup(i1+1, j1+dj1, j2+dj2, arr));
            } else {
                maxi = max(maxi, arr[i1][j1] + arr[i1][j2] + cherryPickup(i1+1, j1+dj1, j2+dj2, arr));
            }
        }
    }

    return maxi;
}

// DP (Mamoization) : TC = O(m*n*n*9), SC = O(m*n*n + n)
int cherryPickupDP1(int i1, int j1, int j2, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp) {
    if(i1 >= arr.size() || j1 < 0 || j2 >= arr[0].size() || j1 >= arr[0].size() || j2 < 0) return -1e8;

    if(dp[i1][j1][j2] != -1) return dp[i1][j1][j2];

    if(i1 == arr.size() - 1) {
        if(j1 != j2) {
            return arr[i1][j1] + arr[i1][j2];
        } else {
            return arr[i1][j1];
        }
    }
    
    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            if(j1 == j2) {
                maxi = max(maxi, arr[i1][j1] + cherryPickupDP1(i1+1, j1+dj1, j2+dj2, arr, dp));
            } else {
                maxi = max(maxi, arr[i1][j1] + arr[i1][j2] + cherryPickupDP1(i1+1, j1+dj1, j2+dj2, arr, dp));
            }
        }
    }

    return dp[i1][j1][j2] = maxi;
}

// DP (Tabulation) : TC = O(m*n*n*9), SC = O(m*n*n)
int cherryPickupDP2(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1e8)));

    // Base case: last row
    for(int j1 = 0; j1 < n; j1++) {
        for(int j2 = 0; j2 < n; j2++) {
            if(j1 == j2) dp[m-1][j1][j2] = arr[m-1][j1];
            else dp[m-1][j1][j2] = arr[m-1][j1] + arr[m-1][j2];
        }
    }

    // Fill table bottom-up
    for(int i = m-2; i >= 0; i--) {
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                int maxi = -1e8;

                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if(nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n) {
                            int value;
                            if(j1 == j2) value = arr[i][j1];
                            else value = arr[i][j1] + arr[i][j2];

                            value += dp[i+1][nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][n-1];
}

// DP (Tabulation + Space Optimization) : TC = O(m*n*n*9), SC = O(n*n)
int cherryPickupDP3(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    vector<vector<int>> front(n, vector<int> (n, 0));
    vector<vector<int>> curr(n, vector<int> (n, 0));

    // Base case: last row
    for(int j1 = 0; j1 < n; j1++) {
        for(int j2 = 0; j2 < n; j2++) {
            if(j1 == j2) front[j1][j2] = arr[m-1][j1];
            else front[j1][j2] = arr[m-1][j1] + arr[m-1][j2];
        }
    }

    // Fill table bottom-up
    for(int i = m-2; i >= 0; i--) {
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                int maxi = -1e8;

                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if(nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n) {
                            int value;
                            if(j1 == j2) value = arr[i][j1];
                            else value = arr[i][j1] + arr[i][j2];

                            value += front[nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }

    return front[0][n-1];
}

int main() {
    vector<vector<int>> arr = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int m = arr.size();
    int n = arr[0].size();

    cout << "\n" << cherryPickup(0, 0, n-1, arr);
    
    vector<vector<vector<int>>> dp1(m, vector<vector<int>>(n, vector<int>(n, -1)));
    cout << "\n" << cherryPickupDP1(0, 0, n-1, arr, dp1);
    
    cout << "\n" << cherryPickupDP2(arr);
    
    cout << "\n" << cherryPickupDP3(arr);

    return 0;
}