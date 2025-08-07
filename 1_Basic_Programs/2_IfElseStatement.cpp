#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a > b) {
        cout << "A is greater than B" << endl;
    } else if (a < b) {
        cout << "B is greater than A" << endl;
    } else {
        cout << "A is equal to B" << endl;
    }

    return 0;
}