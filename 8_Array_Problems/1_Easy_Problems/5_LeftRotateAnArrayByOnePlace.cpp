#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {6, 5, 1, 5, 8, 9, 3, 2, 4, 1};
    int n = arr.size();

    if (n == 0) return 0;

    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}