#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Divisors of " << n << " are: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;


    // More optimal approach
    cout << "Divisors of " << n << " using optimized method are: ";
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            cout << i << " ";
            if(i != n / i) {
                cout << n / i << " ";
            }
        }
    }
    return 0;
}