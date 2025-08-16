#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    reverse(arr, 0, arr.size() - 1);
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}