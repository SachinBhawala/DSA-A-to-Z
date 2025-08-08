/*
    E         
    D E       
    C D E     
    B C D E   
    A B C D E
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(char c = 'A' + (n - i - 1); c < 'A' + n; c++) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}