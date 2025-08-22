#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = val;
    }

    vector<int> hashArray(100, 0); // Hash array of size 100 initialized to 0
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0 && arr[i] < 100) {
            hashArray[arr[i]]++;
        }
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while(q--) {
        int query;
        cout << "Enter number to count: ";
        cin >> query;
        if(query >= 0 && query < 100) {
            cout << "Count of " << query << ": " << hashArray[query] << endl;
        } else {
            cout << "Number out of range." << endl;
        }
    }
    return 0;
}