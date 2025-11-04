#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5, 6, 4, 8, 9, 7, 1, 3, 2};
    int key;
    bool flag = false;
    cout << "Search for: ";
    cin >> key;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) {
            cout << key << " is present at the index: " << i;
            flag = true;
            break;
        }
    }
    if(flag == false) {
        cout << "Not present in the array...!!!";
    }

    return 0;
}