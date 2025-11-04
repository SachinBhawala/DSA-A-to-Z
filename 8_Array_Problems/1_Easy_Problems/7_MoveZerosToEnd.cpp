#include<bits/stdc++.h>
using namespace std;

int main() {
    // Brute Force Approach : TC = O(2n), SC = O(x) where x = number of non zero numbers
    vector<int> arr1 = {1, 5, 0, 6, 0, 4, 0, 9, 0, 3, 0, 0, 9, 8};
    vector<int> temp;
    for(int i : arr1) {
        if(i != 0) {
            temp.push_back(i);
        }
    }
    int len = temp.size();
    for(int i = 0; i < len; i++) {
        arr1[i] = temp[i];
    }
    for(int i = len; i < arr1.size(); i++) {
        arr1[i] = 0;
    }
    for(int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    //Optimal Approach : TC = O(n), SC = O(1)
    vector<int> arr2 = {1, 5, 0, 6, 0, 4, 0, 9, 0, 3, 0, 0, 9, 8};
    int j = -1;
    for(int i = 0; i < arr2.size(); i++) {
        if(arr2[i] == 0) {
            j = i;
            break;
        }
    }
    if(j == -1) cout << "No zeros is present...!!! \n";
    for(int i = j + 1; i < arr2.size(); i++) {
        if(arr2[i] != 0) {
            swap(arr2[j], arr2[i]);
            j++;
        }
    }
    for(int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}