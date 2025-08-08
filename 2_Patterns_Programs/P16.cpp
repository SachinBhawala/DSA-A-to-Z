/*
            A         
          A B A       
        A B C B A     
      A B C D C B A   
    A B C D E D C B A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    char c;
    for(int i = 0; i < n; i++) {
        c = 'A';
        for(int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }

        for(int j = 0; j < 2 * i + 1; j++) {
            cout << c << " ";
            if(j < (2 * i + 1)/2) {
                c++;
            } else {
                c--;
            }
        }

        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}