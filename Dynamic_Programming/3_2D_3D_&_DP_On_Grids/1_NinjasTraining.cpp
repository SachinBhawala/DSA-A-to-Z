#include<bits/stdc++.h>
using namespace std;

// Recursion : TC = O(2^n), SC = O(n)
int ninjaTraining(int day, vector<vector<int>>& arr, int last) {
    int maxi = 0;
    if(day == 0) {
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, arr[0][task]);
            }
        }
        return maxi;
    }
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int points = arr[day][task] + ninjaTraining(day-1, arr, task);
            maxi = max(maxi, points);
        }
    }
    return maxi;
}

// DP (Memoization) : TC = O(n*4), SC = O(n + n*4)
int ninjaTrainingDP1(int day, vector<vector<int>>& arr, int last, vector<vector<int>>& dp) {
    int maxi = 0;
    if(day == 0) {
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, arr[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) {
        return dp[day][last];
    }
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int points = arr[day][task] + ninjaTrainingDP1(day-1, arr, task, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][last] = maxi;
}

// DP (Tabulation) : TC = O(n*4), SC = O(n*4)
int ninjaTrainingDP2(int n, vector<vector<int>>& arr) {
    vector<vector<int>> dp(n, vector<int> (4, 0));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int points = arr[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }
    return dp[n-1][3];
}

// DP (Tabulation + Space Optimization) : TC = O(n*4), SC = O(4)
int ninjaTrainingDP3(int n, vector<vector<int>>& arr) {
    vector<int> prev(4, 0);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    temp[last] = max(temp[last], arr[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

int main() {
    int n = 2;
    vector<vector<int>> arr = {{10, 50, 1}, {5, 100, 11}};
    cout << ninjaTraining(n-1, arr, 3);
    
    cout << endl;

    vector<vector<int>> dp1(n, vector<int> (4,-1));
    cout << ninjaTrainingDP1(n-1, arr, 3, dp1);
    
    cout << endl;

    cout << ninjaTrainingDP2(n, arr);

    cout << endl;

    cout << ninjaTrainingDP3(n, arr);

    return 0;
}