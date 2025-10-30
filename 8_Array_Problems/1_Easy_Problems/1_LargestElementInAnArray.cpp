#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5, 6, 8, 3, 2, 4, 5, 6, 9, 1};
    int max = arr[0];
    for(int i : arr) {
        if(i > max) {
            max = i;
        }
    }
    cout << "Largest Element is: " << max;
    return 0;
}