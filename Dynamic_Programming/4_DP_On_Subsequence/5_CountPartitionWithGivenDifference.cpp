#include<bits/stdc++.h>
using namespace std;

// DP (Tabulation + Space Optimization) : TC = O(n*k), SC = O(n)
int countPartition(int n, int k, vector<int>& arr) {
    vector<int> prev(k+1, 0);

    if (arr[0] == 0) {
        prev[0] = 2;
    } else {
        prev[0] = 1;
    }

    if (arr[0] != 0 && arr[0] <= k) {
        prev[arr[0]] = 1;
    }

    for(int index = 1; index < n; index++) {
        vector<int> temp(k+1, 0);
        for(int target = 0; target <= k; target++) {
            int notTake = prev[target];
            int take = 0;
            if(arr[index] <= target) take = prev[target-arr[index]];
            temp[target] = notTake + take;
        }
        prev = temp;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;

    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    if(sum - d < 0 || (sum - d) % 2) return false;
    int s2 = (sum-d)/2;

    cout << "\n" << countPartition(arr.size() - 1, s2, arr);

    return 0;
}