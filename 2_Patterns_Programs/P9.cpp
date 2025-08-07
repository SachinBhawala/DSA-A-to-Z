/*
    *         
    * *       
    * * *     
    * * * *   
    * * * * * 
    * * * *   
    * * *     
    * *       
    *
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int key;
    for(int i = 0; i < 2 * n - 1; i++) {
        if(i >= n) {
            key = (2 * n - i) - 2;
        } else {
            key = i;
        }
        for(int j = 0; j <= key; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}