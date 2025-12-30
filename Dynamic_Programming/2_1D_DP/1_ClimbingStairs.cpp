#include<bits/stdc++.h>
using namespace std;

// DP (Tabulation + Space Optimization) : TC = O(n), SC = O(1)
int climbStairs(int n) {
    int prev2 = 1;
    int prev1 = 1;
    int curr = 1;
    for(int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n;
    cout << "Enter number of steps : ";
    cin >> n;

    cout << "Number of possible ways are : " << climbStairs(n);

    return 0;
}