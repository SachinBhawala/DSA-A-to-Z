#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr1 = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};

    // Brute Force Approach
    sort(arr1.begin(), arr1.end());
    cout << "Largest Element is: " << arr1[arr1.size() - 1];

    cout << endl;

    // Optimal Approach
    vector<int> arr2 = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};
    int max = arr2[0];
    for(int i : arr2) {
        if(i > max) {
            max = i;
        }
    }
    cout << "Largest Element is: " << max;
    return 0;
}