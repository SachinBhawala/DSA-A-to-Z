/*
    *                 * 
    * *             * * 
    * * *         * * * 
    * * * *     * * * * 
    * * * * * * * * * * 
    * * * *     * * * * 
    * * *         * * * 
    * *             * * 
    *                 *
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int k, l;
    for(int i = 0; i < 2 * n - 1; i++) {
        if(i >= n) {
            k = 2 * n - 2 - i;
            l = 2 * i - 2 * n + 2;
        } else {
            k = i;
            l = 2 * n - 2 * i - 2;
        }
        
        for(int j = 0; j <= k; j++) {
            cout << "* ";
        }

        for(int j = 0; j < l; j++) {
            cout << "  ";
        }

        for(int j = 0; j <= k; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}