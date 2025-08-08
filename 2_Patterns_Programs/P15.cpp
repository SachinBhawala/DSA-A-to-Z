/*
    A         
    B B       
    C C C     
    D D D D   
    E E E E E
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    char c = 'A';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << c << " ";
        }
        c++;
        cout << endl;
    }
    return 0;
}