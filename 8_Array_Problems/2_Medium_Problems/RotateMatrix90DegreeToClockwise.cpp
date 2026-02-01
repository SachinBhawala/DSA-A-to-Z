#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach : TC = O(n^2), SC = O(n^2)
void rotateMatrixBrute(vector<vector<int>>& arr) {
    vector<vector<int>> temp(arr.size(), vector<int> (arr[0].size()));

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            temp[j][(arr.size()-1)-i] = arr[i][j];
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

// Optimal Approach : TC = O(n/2 * n/2 + n*n/2), SC = O(1)
void rotateMatrixOptimal(vector<vector<int>>& arr) {
    // Transpose of matrix
    for(int i = 0; i < arr.size() - 1; i++) {
        for(int j = i + 1; j < arr[0].size(); j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Reverse every row
    for(int i = 0; i < arr.size(); i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    
    rotateMatrixBrute(arr);

    rotateMatrixOptimal(arr);

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}