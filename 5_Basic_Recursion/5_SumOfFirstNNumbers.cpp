#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    if(n <= 0) {
        return 0;
    }
    return n + sum(n - 1);
}

int sumNum(int i, int sum) {
    if(i < 1) {
        return sum;
    }
    sumNum(i - 1, sum + i);
}

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers is: " << sum(n) << endl;
    cout << "Sum of first " << n << " natural numbers is: " << sumNum(n, 0) << endl;
    return 0;
}