#include<bits/stdc++.h>
using namespace std;

// DP (Tabulation + Space Optimization) : TC = O(n), SC = O(1)
int maxMoneyDP(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];
    if (n == 2) return max(arr[0], arr[1]);
    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        int curr = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maxMoney(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp1, temp2;
    if(n == 1) return arr[0];
    for(int i = 0; i < n; i++) {
        if(i != 0) {
            temp1.push_back(arr[i]);
        }
        if(i != n - 1) {
            temp2.push_back(arr[i]);
        }
    }
    return max(maxMoneyDP(temp1), maxMoneyDP(temp2));
}

int main() {
    vector<int> arr = {1, 2, 6, 8, 9, 5, 8};

    cout << "Maximum Money is : " << maxMoney(arr);

    return 0;
}