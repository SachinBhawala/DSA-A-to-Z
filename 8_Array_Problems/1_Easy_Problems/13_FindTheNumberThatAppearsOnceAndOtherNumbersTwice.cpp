#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};

    // Brute Forch Approach
    int count;
    for(int i = 0; i < arr.size(); i++) {
        count = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count == 1) {
            cout << arr[i] << " appears one time...!!!";
            break;
        }
    }

    cout << endl;

    // Better Approach
    

    return 0;
}