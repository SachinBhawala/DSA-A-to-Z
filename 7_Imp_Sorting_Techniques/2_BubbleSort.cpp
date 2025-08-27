#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10, -80, 60, 30, -70, 90, 40, -50};
    int n = arr.size();
    bool alreadySorted = true;
    for(int i = 0; i < n; i++) {
        int didswap = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
                alreadySorted = false;
            }
        }
        if(didswap == 0) break;
    }
    if (alreadySorted) {
        cout << "Already sorted" << endl;
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}