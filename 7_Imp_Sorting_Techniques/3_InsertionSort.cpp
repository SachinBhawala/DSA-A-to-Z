#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}