#include<bits/stdc++.h>
using namespace std;

// DP (Tabulation) : TC = O(n × sum + sum), SC = O(n × sum)
int minAbsSumDiff(int n, int sum, vector<int>& arr) {
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for(int index = 0; index < n; index++) {
        dp[index][0] = true;
    }
    if(arr[0] <= sum) dp[0][arr[0]] = true;

    for(int index = 1; index < n; index++) {
        for(int target = 1; target <= sum; target++) {
            bool notTake = dp[index-1][target];
            bool take = false;
            if(arr[index] <= target) take = dp[index-1][target-arr[index]];
            dp[index][target] = notTake || take;
        }
    }

    int mini = 1e8;
    for(int i = 0; i <= sum/2; i++) {
        if(dp[n-1][i] == true) {
            int s1 = i;
            int s2 = sum-i;
            mini = min(mini, abs(s1 - s2));
        }
    }

    return mini;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "\n" << minAbsSumDiff(n, sum, arr);

    return 0;
}