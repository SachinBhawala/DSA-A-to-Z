#include<bits/stdc++.h>
using namespace std;

int main() {
    // Brute Force Approach
    vector<int> arr1 = {1, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 8, 9, 9};
    set<int> st;
    for(int j = 0; j < arr1.size(); j++) {
        st.insert(arr1[j]);
    }
    int index = 0;
    for(auto it : st) {
        arr1[index] = it;
        index++;
    }
    for(int j = 0; j < arr1.size(); j++) {
        cout << arr1[j] << " ";
    }

    cout << endl;

    // Optimal Approach
    vector<int> arr2 = {1, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 8, 9, 9};
    int n = arr2.size();
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(arr2[i] != arr2[j]) {
            arr2[i + 1] = arr2[j];
            i++;
        }
    }
    for(int j = 0; j < n; j++) {
        cout << arr2[j] << " ";
    }
    return 0;
}