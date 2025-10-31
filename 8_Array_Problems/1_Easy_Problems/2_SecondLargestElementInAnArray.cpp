#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr1 = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};

    // Brute Force Approach
    sort(arr1.begin(), arr1.end());
    for(int i = arr1.size() - 1; i >= 0; i--) {
        if(arr1[i] != arr1[i - 1]) {
            cout << "Second Largest Element is: " << arr1[i - 1];
            break;
        }
    }

    cout << endl;

    // Better Approach
    vector<int> arr2 = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};
    int largest = arr2[0];
    for(int i = 0; i < arr2.size(); i++) {
        if(arr2[i] > largest) {
            largest = arr2[i];
        }
    }
    int secondLargest = arr2[0];
    for(int i = 0; i < arr2.size(); i++) {
        if(arr2[i] > secondLargest && arr2[i] != largest) {
            secondLargest = arr2[i];
        }
    }
    cout << "Second Largest Element is: " << secondLargest;

    cout << endl;

    // Optimal Approach
    vector<int> arr3 = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};
    int large = arr3[0];
    int secondLarge = -1;
    for(int i = 0; i < arr3.size(); i++) {
        if(arr3[i] > large) {
            secondLarge = large;
            large = arr3[i];
        }
    }
    cout << "Second Largest Element is: " << secondLarge;
    return 0;
}