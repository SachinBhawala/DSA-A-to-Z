/*
    A B C D E 
    A B C D   
    A B C     
    A B       
    A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(char c = 'A'; c < 'A' + n - i; c++) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}