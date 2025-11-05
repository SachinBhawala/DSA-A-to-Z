#include<bits/stdc++.h>
using namespace std;

int main() {
    // Optimal Approach : TC = O(n), SC = O(1)
    vector<int> arr = {3, 5, 1, 1, 1, 6, 5, 1, 1, 5, 8, 9, 1, 1, 1, 1, 5};
    int max_con = 0;
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 1) {
            count++;
        } else {
            max_con = max(max_con, count);
            count = 0;
        }
    }
    cout << "Maximum Consicutive is " << max_con;

    return 0;
}