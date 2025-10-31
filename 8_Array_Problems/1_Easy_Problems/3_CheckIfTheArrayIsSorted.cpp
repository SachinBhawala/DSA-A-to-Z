#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};
    // vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            cout << "Array is not sorted...!!!";
            break;
        }
    }
    cout << "Array is sorted...!!!";
    return 0;
}