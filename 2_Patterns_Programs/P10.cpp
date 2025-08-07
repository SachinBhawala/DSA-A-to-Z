/*
    1         
    0 1       
    1 0 1     
    0 1 0 1   
    1 0 1 0 1
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int start = 1;
    int temp;
    for(int i = 0; i < n; i++) {
        temp = start;
        for(int j = 0; j <= i; j++) {
            cout << start << " ";
            start = 1 - start;
        }
        start = temp;
        start = 1 - start;
        cout << endl;
    }
    return 0;
}
