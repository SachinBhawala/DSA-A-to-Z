#include<bits/stdc++.h>
using namespace std;

int main() {
    //Brute Force Approach : TC = O(n1 + rotation1), SC = O(rotation1)
    vector<int> arr1 = {6, 5, 1, 5, 8, 9, 3, 2, 4, 1};
    int n1 = arr1.size();
    int rotation1;
    cout << "Enter number of rotation: ";
    cin >> rotation1;
    if(rotation1 > n1) {
        rotation1 = rotation1 % n1;
    }
    vector<int> temp;
    for(int i = 0; i < rotation1; i++) {
        temp.push_back(arr1[i]);
    }
    for(int i = rotation1; i < n1; i++) {
        arr1[i - rotation1] = arr1[i];
    }
    for(int i = n1 - rotation1; i < n1; i++) {
        arr1[i] = temp[i - (n1 - rotation1)];
    }
    for(int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    // Optimal Approach : TC = O(n), SC = O(1)
    vector<int> arr2 = {6, 5, 1, 5, 8, 9, 3, 2, 4, 1};
    int n2 = arr2.size();
    int rotation2;
    cout << "Enter number of rotation: ";
    cin >> rotation2;
    if(rotation2 > n2) {
        rotation2 = rotation2 % n2;
    }
    reverse(arr2.begin(), arr2.end());
    reverse(arr2.begin(), arr2.begin() + n2 - rotation2);
    reverse(arr2.begin() + n2 - rotation2, arr2.end());
    for(int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}