#include<bits/stdc++.h>
using namespace std;

int main() {
    // Brute Force approach : TC = O(n log n), SC = O(1)
    vector<int> arr1 = {1, 2, 0, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 2, 0};
    sort(arr1.begin(), arr1.end());
    for(auto i : arr1) {
        cout << i << " ";
    }

    cout << endl;

    // Better Approach : TC = O(2n), SC = O(1)
    vector<int> arr2 = {1, 2, 0, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 2, 0};
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(auto i : arr2) {
        if(i == 0) {
            count0++;
        } else if(i == 1) {
            count1++;
        } else {
            count2++;
        }
    }
    for(int i = 0; i < arr2.size(); i++) {
        if(count0 > 0) {
            arr2[i] = 0;
            count0--;
        } else if(count1 > 0) {
            arr2[i] = 1;
            count1--;
        } else {
            arr2[i] = 2;
            count2--;
        }
    }
    for(auto i : arr2) {
        cout << i << " ";
    }
 
    cout << endl;

    // Optimal Approach (Dutch National Flag Algorithm): TC = O(n), SC = O(1)
    vector<int> arr3 = {1, 2, 0, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 2, 0};
    int low = 0;
    int mid = 0;
    int high = arr2.size() - 1;
    while(mid <= high) {
        if(arr3[mid] == 0) {
            swap(arr3[low], arr3[mid]);
            low++;
            mid++;
        } else if(arr3[mid] == 1) {
            mid++;
        } else {
            swap(arr3[mid], arr3[high]);
            high--;
        }
    }
    for(auto i : arr3) {
        cout << i << " ";
    }

    return 0;
}