#include<bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>& arr, int last) {
    int maxi = 0;
    if(n == 0) {
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    for(int i = 0; i < 3; i++) {
        if(i != last) {
            int points = arr[n][i] + ninjaTraining(n-1, arr, i);
            maxi = max(maxi, points);
        }
    }
    return maxi;
}

int main() {
    int n = 2;
    vector<vector<int>> arr = {{10, 50, 1}, {5, 100, 11}};
    cout << ninjaTraining(n-1, arr, 3);

    return 0;
}