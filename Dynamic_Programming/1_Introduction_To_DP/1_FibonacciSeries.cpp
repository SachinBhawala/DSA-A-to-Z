#include<bits/stdc++.h>
using namespace std;

// Using Recursion : TC = O(2^n), SC = O(n)
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Using DP (Memoization) : TC = O(n), SC = O(2n)
int fibonacciDP1(int n, vector<int> &dp) {
    if(n <= 1) {
        return n;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = fibonacciDP1(n-1, dp) + fibonacciDP1(n-2, dp);
}

// Using DP (Tabulation) : TC = O(n), SC = O(n)
int fibonacciDP2(int n, vector<int> &dp) {
    dp[0] = 0;
    dp[1] = 1;
    if(n <= 1) {
        return n;
    }
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Using DP (Tabulation + Space Optimization) : TC = O(n), SC = O(1)
int fibonacciDP3(int n) {
    int prev2 = 0;
    int prev1 = 1;
    int curr;
    if(n <= 1) {
        return n;
    }
    for(int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    int fib = fibonacci(n);
    cout << "Fibonacci number of n is : " << fib;

    cout << endl;

    vector<int> dp1(n+1, -1);
    int fibDP1 = fibonacciDP1(n, dp1);
    cout << "Fibonacci number of n is : " << fibDP1;

    cout << endl;

    vector<int> dp2(n+1);
    int fibDP2 = fibonacciDP2(n, dp2);
    cout << "Fibonacci number of n is : " << fibDP2;

    cout << endl;

    int fibDP3 = fibonacciDP3(n);
    cout << "Fibonacci number of n is : " << fibDP3;

    return 0;
}