#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4, 5, 5, 6, 6, 6, 8, 9};
    vector<int> arr2 = {1, 2, 2, 4, 5, 6, 7, 8, 9};

    // Brute Force Approach : TC = O(arr1 log n + arr2 log n) + O(arr1 + arr2), SC = O(arr1 + arr2) + O(arr1 + arr2)
    set<int> st;
    for(int i = 0; i < arr1.size(); i++) {
        st.insert(arr1[i]);
    }
    for(int i = 0; i < arr2.size(); i++) {
        st.insert(arr2[i]);
    }
    vector<int> union_arr1(st.size());
    int k = 0;
    for(auto i : st) {
        union_arr1[k] = i;
        k++;
    }
    for(int i = 0; i < union_arr1.size(); i++) {
        cout << union_arr1[i] << " ";
    }

    cout << endl;

    // Optimal Approach : TC = O(arr1 + arr2), SC = O(arr1 + arr2)
    vector<int> union_arr2;
    int i = 0;
    int j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            if(union_arr2.size() == 0 || union_arr2.back() != arr1[i]) {
                union_arr2.push_back(arr1[i]);
            }
            i++;
        } else {
            if(union_arr2.size() == 0 || union_arr2.back() != arr2[j]) {
                union_arr2.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j < arr2.size()) {
        if(union_arr2.size() == 0 || union_arr2.back() != arr2[j]) {
            union_arr2.push_back(arr2[j]);
        }
        j++;
    }
    while(i < arr1.size()) {
        if(union_arr2.size() == 0 || union_arr2.back() != arr1[i]) {
            union_arr2.push_back(arr1[i]);
        }
        i++;
    }
    for(int i = 0; i < union_arr2.size(); i++) {
        cout << union_arr2[i] << " ";
    }

    return 0;
}