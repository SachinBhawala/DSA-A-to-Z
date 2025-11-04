#include<bits/stdc++.h>
using namespace std;

int main() {
    // Optimal Approach : TC = O(arr1 + arr2), SC = O(1)
    vector<int> arr1 = {1, 2, 2, 3, 4, 5, 5, 6, 6, 6, 8, 9};
    vector<int> arr2 = {1, 2, 2, 4, 5, 6, 7, 8, 9};
    vector<int> intersection;
    int i = 0;
    int j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] == arr2[j]) {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        } else {
            if(arr1[i] < arr2[j]) {
                i++;
            } else {
                j++;
            }
        }
    }
    for(int k = 0; k < intersection.size(); k++) {
        cout << intersection[k] << " ";
    }

    return 0;
}